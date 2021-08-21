/*
 * serial2.c
 *
 * Created: 20/08/2021 10:27:40
 *  Author: OBED
 */ 
#include "hardwareSerial.h"

void _tx0_udr_empty_irq(void);
void _rx0_complete_irq(void);

void Serial0_begin(unsigned long baud, uint8_t config )
{
	_rx_buffer0_head = 0;
	_rx_buffer0_tail = 0;
	_tx_buffer0_head = 0;
	_tx_buffer0_tail = 0;
	
	_timeout0 = 1000; //DEFAULT timeout
	
	//Try u2x mode first
	uint16_t baud_setting = (F_CPU / 4 / baud - 1)/2; // check datasheet page 203
	UCSR0A = 1 << U2X0; //Double speed mode
	
	// Hard coded exception for 57600 for compatibility with the bootloader shipped with the Duemilanove and previous boards 
	// and the firmware on the 8U2 on the Uno and Mega 2560. 
	// Also, The baud_setting cannot be > 4095, so switch back to non-u2x mode if the baud rate is too low.
	if (((F_CPU == 16000000UL) && (baud == 57600)) || (baud_setting >4095))
	{
		UCSR0A = 0;
		baud_setting = (F_CPU / 8 / baud - 1) / 2;
	}
	
	//Assign the baud_setting
	UBRR0H = baud_setting >> 8;
	UBRR0L = baud_setting;
	
	// Set the data bits, parity, and stop bits(config)
	UCSR0C = config;
	
	//configure interrupts
	bitSet(UCSR0B, RXEN0);
	bitSet(UCSR0B, TXEN0);
	bitSet(UCSR0B, RXCIE0); //Rx complete interrupt enable
	bitClear(UCSR0B, UDRIE0); //data register empty int -disable
	
}

/*
* Sets maximum milliseconds to wait for stream data, default is 1 second
*/
void Serial0_setTimeout(unsigned long timeout)
{
	_timeout0 = timeout;
}

/*
* Get the number of bytes (characters) available for reading from the serial port. 
* This is data that is already arrived and stored in the serial receive buffer (which holds 64 bytes).
*/
int Serial0_available(void)
{
	 return ((unsigned int)(SERIAL_RX_BUFFER_SIZE + _rx_buffer0_head - _rx_buffer0_tail)) % SERIAL_RX_BUFFER_SIZE;
}

int Serial0_read(void)
{
	// if the head isn't ahead of the tail, we don't have any characters
	if (_rx_buffer0_head == _rx_buffer0_tail){
		return -1;
	}else{
		unsigned char c = _rx_buffer0[_rx_buffer0_tail];
		_rx_buffer0_tail = (rx_buffer_index_t)(_rx_buffer0_tail + 1) % SERIAL_RX_BUFFER_SIZE;
		return c;
	}
}

int Serial0_timedRead(void)
{
	  int c;
	  _startMillis0 = millis();
	  do {
		  c = Serial0_read();
		  if (c >= 0) return c;
	  } while(millis() - _startMillis0 < _timeout0);
	  return -1;     // -1 indicates timeout
}

/*
* Read characters from stream into buffer terminates if length characters have been read, or timeout (see setTimeout)
* Returns the number of characters placed in the buffer
* the buffer is NOT null terminated.
*/
size_t Serial0_readBytes(char *buffer, size_t length)
{
	size_t count = 0;
	while (count < length) {
		int c = Serial0_timedRead();
		if (c < 0) break;
		*buffer++ = (char)c;
		count++;
	}
	return count;
}

size_t Serial0_readBytesUntil(char terminator, char *buffer, size_t length)
{
	size_t index = 0;
	while (index < length) {
		int c = Serial0_timedRead();
		if (c < 0 || c == terminator) break;
		*buffer++ = (char)c;
		index++;
	}
	return index; // return number of characters, not including null terminator	
}

size_t Serial0_readAllBytes(char *buffer, size_t length)
{
	size_t index = 0;
	
	while(index < length )
	{
		int c = Serial0_timedRead();
		if(c < 0 ) break;
		*buffer++ = (char)c;
		index++;		
	}
	return index;	
}

size_t Serial0_write(uint8_t c)
{
	// If the buffer and the data register is empty, just write the byte to the data register and be done. 
	// This shortcut helps significantly improve the effective data rate at high (>500kbit/s) bitrates, 
	// where interrupt overhead becomes a slowdown.
	if (_tx_buffer0_head == _tx_buffer0_tail && bit_is_set(UCSR0A, UDRE0)){
		// If TXC is cleared before writing UDR and the previous byte completes before writing to UDR, TXC will be set but a byte
		// is still being transmitted causing flush() to return too soon. So writing UDR must happen first.
		// Writing UDR and clearing TC must be done atomically, otherwise interrupts might delay the TXC clear so the byte written to UDR
		// is transmitted (setting TXC) before clearing TXC. 
		// Then TXC will be cleared when no bytes are left, causing flush() to hang
		ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
			UDR0 = c;
			UCSR0A = ((UCSR0A) & ((1 << U2X0) | (1 << MPCM0))) | (1 << TXC0);
		}
		return 1;
	}
	tx_buffer_index_t i = (_tx_buffer0_head + 1) % SERIAL_TX_BUFFER_SIZE;
	
	// If the output buffer is full, there's nothing for it other than to wait for the interrupt handler to empty it a bit
	while (i == _tx_buffer0_tail){
		if (bit_is_clear(SREG, 7)){
			// Interrupts are disabled, so we'll have to poll the data register empty flag ourselves. 
			// If it is set, pretend an interrupt has happened and call the handler to free up space for us.
			if(bit_is_set(UCSR0A, UDRE0))
				_tx0_udr_empty_irq();
		}else{
			// nop, the interrupt handler will free up space for us
		}	
	}
	
	_tx_buffer0[_tx_buffer0_head] = c;
	
	// make atomic to prevent execution of ISR between setting the head pointer 
	// and setting the interrupt flag resulting in buffer retransmission
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
		_tx_buffer0_head = i;
		bitSet(UCSR0B, UDRIE0);
	}
	
	return 1;
}

size_t Serial0_print(char *string) {
	size_t n = 0;
	for (char *it = string; *it; it++) {
		Serial0_write((uint8_t)*it); 
		n++;
	}
	return n;
}

void Serial0_flush(void)
{
	//Waits for the transmission of outgoing serial data to complete.
	while (bit_is_set( UCSR0B, UDRIE0) || bit_is_clear(UCSR0A, TXC0)) {
		if(bit_is_clear(SREG, 7) && bit_is_set(UCSR0B, UDRIE0) )
		// Interrupts are globally disabled, but the DR empty 
		// interrupt should be enabled, so poll the DR empty flag to prevent deadlock
		if (bit_is_set(UCSR0A, UDRE0))
			_tx0_udr_empty_irq();
	}
	// If we get here, nothing is queued anymore (DRIE is disabled) and
	// the hardware finished transmission (TXC is set).
}

void Serial0_end(void)
{
	// wait for transmission of outgoing data
	Serial0_flush();
	
	bitClear(UCSR0B, RXEN0);
	bitClear(UCSR0B, TXEN0);
	bitClear(UCSR0B, RXCIE0); //Rx complete interrupt enable
	bitClear(UCSR0B, UDRIE0); //data register empty int -disable
	
	//clear any received data
	_rx_buffer0_head = _rx_buffer0_tail;	
}

/************************************************************************/
/*         Interrupt handlers                                           */
/************************************************************************/
// Data Register Empty - ready to receive new data
void _tx0_udr_empty_irq(void)
{
	// If interrupts are enabled, there must be more data in the output buffer. 
	unsigned char c = _tx_buffer0[_tx_buffer0_tail];
	_tx_buffer0_tail = (_tx_buffer0_tail + 1) % SERIAL_TX_BUFFER_SIZE;
	
	// Send the next byte
	UDR0 = c;
	
	// clear the TXC bit -- "can be cleared by writing a one to its bit location". 
	// This makes sure flush() won't return until the bytes actually got written. 
	// Other r/w bits are preserved, and zeros written to the rest.
	UCSR0A = ((UCSR0A) & ((1 << U2X0) | (1 << MPCM0))) | (1 << TXC0);
	
	if (_tx_buffer0_head == _tx_buffer0_tail) {
		// Buffer empty, so disable interrupts
		bitClear(UCSR0B, UDRIE0);
	}
}

void _rx0_complete_irq(void)
{
	if (bit_is_clear(UCSR0A, UPE0)){
		// No Parity error, read byte and store it in the buffer if there is room
		unsigned char c = UDR0;
		rx_buffer_index_t i = (unsigned int)(_rx_buffer0_head + 1) % SERIAL_RX_BUFFER_SIZE;
		
		// if we should be storing the received character into the location just before the tail 
		// (meaning that the head would advance to the current location of the tail), we're about to overflow the buffer
		// and so we don't write the character or advance the head.
		if (i != _rx_buffer0_tail) {
			_rx_buffer0[_rx_buffer0_head] = c;
			_rx_buffer0_head = i;
		}
	}else{
		// Parity error, read byte but discard it
		UDR0;
	}
}

/************************************************************************/
/*					 ISRs                                                */
/************************************************************************/
ISR(USART0_RX_vect){
	_rx0_complete_irq();
}

ISR(USART0_UDRE_vect){
	_tx0_udr_empty_irq();
}