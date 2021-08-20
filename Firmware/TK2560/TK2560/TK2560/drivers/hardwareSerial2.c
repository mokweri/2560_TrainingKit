/*
 * serial2.c
 *
 * Created: 20/08/2021 10:27:40
 *  Author: OBED
 */ 
#include "hardwareSerial.h"

void _tx2_udr_empty_irq(void);
void _rx2_complete_irq(void);

void Serial2_begin(unsigned long baud, uint8_t config )
{
	_rx_buffer_head = 0;
	_rx_buffer_tail = 0;
	_tx_buffer_head = 0;
	_tx_buffer_tail = 0;
	
	//Try u2x mode first
	uint16_t baud_setting = (F_CPU / 4 / baud - 1)/2; // check datasheet page 203
	UCSR2A = 1 << U2X2; //Double speed mode
	
	// Hard coded exception for 57600 for compatibility with the bootloader shipped with the Duemilanove and previous boards 
	// and the firmware on the 8U2 on the Uno and Mega 2560. 
	// Also, The baud_setting cannot be > 4095, so switch back to non-u2x mode if the baud rate is too low.
	if (((F_CPU == 16000000UL) && (baud == 57600)) || (baud_setting >4095))
	{
		UCSR2A = 0;
		baud_setting = (F_CPU / 8 / baud - 1) / 2;
	}
	
	//Assign the baud_setting
	UBRR2H = baud_setting >> 8;
	UBRR2L = baud_setting;
	
	// Set the data bits, parity, and stop bits(config)
	UCSR2C = config;
	
	//configure interrupts
	bitSet(UCSR2B, RXEN2);
	bitSet(UCSR2B, TXEN2);
	bitSet(UCSR2B, RXCIE2); //Rx complete interrupt enable
	bitClear(UCSR2B, UDRIE2); //data register empty int -disable
	
}

int Serial2_available(void)
{
	 return ((unsigned int)(SERIAL_RX_BUFFER_SIZE + _rx_buffer_head - _rx_buffer_tail)) % SERIAL_RX_BUFFER_SIZE;
}

int Serial2_read(void)
{
	// if the head isn't ahead of the tail, we don't have any characters
	if (_rx_buffer_head == _rx_buffer_tail){
		return -1;
	}else{
		unsigned char c = _rx_buffer[_rx_buffer_tail];
		_rx_buffer_tail = (rx_buffer_index_t)(_rx_buffer_tail + 1) % SERIAL_RX_BUFFER_SIZE;
		return c;
	}
}

size_t Serial2_write(uint8_t c)
{
	// If the buffer and the data register is empty, just write the byte to the data register and be done. 
	// This shortcut helps significantly improve the effective data rate at high (>500kbit/s) bitrates, 
	// where interrupt overhead becomes a slowdown.
	if (_tx_buffer_head == _tx_buffer_tail && bit_is_set(UCSR2A, UDRE2)){
		// If TXC is cleared before writing UDR and the previous byte completes before writing to UDR, TXC will be set but a byte
		// is still being transmitted causing flush() to return too soon. So writing UDR must happen first.
		// Writing UDR and clearing TC must be done atomically, otherwise interrupts might delay the TXC clear so the byte written to UDR
		// is transmitted (setting TXC) before clearing TXC. 
		// Then TXC will be cleared when no bytes are left, causing flush() to hang
		ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
			UDR2 = c;
			UCSR2A = ((UCSR2A) & ((1 << U2X2) | (1 << MPCM2))) | (1 << TXC2);
		}
		return 1;
	}
	tx_buffer_index_t i = (_tx_buffer_head + 1) % SERIAL_TX_BUFFER_SIZE;
	
	// If the output buffer is full, there's nothing for it other than to wait for the interrupt handler to empty it a bit
	while (i == _tx_buffer_tail){
		if (bit_is_clear(SREG, 7)){
			// Interrupts are disabled, so we'll have to poll the data register empty flag ourselves. 
			// If it is set, pretend an interrupt has happened and call the handler to free up space for us.
			if(bit_is_set(UCSR2A, UDRE2))
				_tx2_udr_empty_irq();
		}else{
			// nop, the interrupt handler will free up space for us
		}	
	}
	
	_tx_buffer[_tx_buffer_head] = c;
	
	// make atomic to prevent execution of ISR between setting the head pointer 
	// and setting the interrupt flag resulting in buffer retransmission
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
		_tx_buffer_head = i;
		bitSet(UCSR2B, UDRIE2);
	}
	
	return 1;
}

size_t Serial2_write_(const uint8_t *buffer, size_t size)
{
	size_t n = 0;
	while (size--) {
		if (Serial2_write(*buffer++)) n++;
		else break;
	}
	return n;
}


void Serial2_flush(void)
{
	//Waits for the transmission of outgoing serial data to complete.
	while (bit_is_set( UCSR2B, UDRIE2) || bit_is_clear(UCSR2A, TXC2)) {
		if(bit_is_clear(SREG, 7) && bit_is_set(UCSR2B, UDRIE2) )
		// Interrupts are globally disabled, but the DR empty 
		// interrupt should be enabled, so poll the DR empty flag to prevent deadlock
		if (bit_is_set(UCSR2A, UDRE2))
			_tx2_udr_empty_irq();
	}
	// If we get here, nothing is queued anymore (DRIE is disabled) and
	// the hardware finished transmission (TXC is set).
}

void Serial2_end(void)
{
	// wait for transmission of outgoing data
	Serial2_flush();
	
	bitClear(UCSR2B, RXEN2);
	bitClear(UCSR2B, TXEN2);
	bitClear(UCSR2B, RXCIE2); //Rx complete interrupt enable
	bitClear(UCSR2B, UDRIE2); //data register empty int -disable
	
	//clear any received data
	_rx_buffer_head = _rx_buffer_tail;	
}


// Interrupt handlers
void _tx2_udr_empty_irq(void)
{
	// If interrupts are enabled, there must be more data in the output buffer. 
	unsigned char c = _tx_buffer[_tx_buffer_tail];
	_tx_buffer_tail = (_tx_buffer_tail + 1) % SERIAL_TX_BUFFER_SIZE;
	
	// Send the next byte
	UDR2 = c;
	
	// clear the TXC bit -- "can be cleared by writing a one to its bit location". 
	// This makes sure flush() won't return until the bytes actually got written. 
	// Other r/w bits are preserved, and zeros written to the rest.
	UCSR2A = (UCSR2A & ((1 << U2X2) | (1 << MPCM2))) | (1 << TXC2);
	
	if (_tx_buffer_head == _tx_buffer_tail) {
		// Buffer empty, so disable interrupts
		bitSet(UCSR2B, UDRIE2);
	}
}

void _rx2_complete_irq(void)
{
	if (bit_is_clear(UCSR2A, UPE0)){
		// No Parity error, read byte and store it in the buffer if there is room
		unsigned char c = UDR2;
		rx_buffer_index_t i = (unsigned int)(_rx_buffer_head + 1) % SERIAL_RX_BUFFER_SIZE;
		
		// if we should be storing the received character into the location just before the tail 
		// (meaning that the head would advance to the current location of the tail), we're about to overflow the buffer
		// and so we don't write the character or advance the head.
		if (i != _rx_buffer_tail) {
			_rx_buffer[_rx_buffer_head] = c;
			_rx_buffer_head = i;
		}
	}else{
		// Parity error, read byte but discard it
		UDR2;
	}
}

//IRQ
ISR(USART2_RX_vect){
	_rx2_complete_irq();
}

ISR(USART2_UDRE_vect){
	_tx2_udr_empty_irq();
}