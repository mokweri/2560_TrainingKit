/*
 * spi.c
 *
 * Created: 24/08/2021 09:14:19
 *  Author: OBED
 */ 
#include "spi.h"

/************************************************************************/
/* Constants and macros                                                 */
/************************************************************************/
#define SPI_ACTIVE			0 // SS Pin put Low
#define SPI_INACTIVE		1 // SS Pin put High

/* size of RX/TX buffers */
#define SPI_RX_BUFFER_MASK ( SPI_RX_BUFFER_SIZE - 1)
#define SPI_TX_BUFFER_MASK ( SPI_TX_BUFFER_SIZE - 1)


/************************************************************************/
/* Global variable                                                      */
/************************************************************************/
static volatile uint8_t SPI_TxBuf[SPI_TX_BUFFER_SIZE];
static volatile uint8_t SPI_RxBuf[SPI_RX_BUFFER_SIZE];
static volatile uint8_t SPI_TxHead;
static volatile uint8_t SPI_TxTail;
static volatile uint8_t SPI_RxHead;
static volatile uint8_t SPI_RxTail;

#if defined (SPI_MASTER_ENABLED) && defined(SPI_SLAVE_ENABLED)
	#error The multimaster mode of SPI is not yet implement. Do not hesitate to implement it, then submit a pull request ! Thx
#elif defined(SPI_MASTER_ENABLED)
	static volatile uint8_t SPI_CTS;
	static volatile uint8_t SPI_bytesRequest; // Number of bytes request
#elif defined(SPI_SLAVE_ENABLED)
	static volatile uint8_t SPI_SPDR;
	#define SPI_SPDR_EMPTY	0
	#define SPI_SPDR_FULL	1
#endif

#if defined (SPI_MASTER_ENABLED)
/*************************************************************************
Function: spi_master_init()
Purpose:  Initialize SPI in Master Mode
Input:    mode SPI_MODEx (x : 0 -> 3)
Input:    clock SPI_CLOCK_DIVx (x : 2, 4, 8, 16, 32, 64 or 128)
Input:    bitOrder: LSBFIRST, MSBFIRST
Returns:  none
**************************************************************************/
void spi_master_init(uint8_t mode, uint8_t clockDiv, uint8_t bitOrder){
	
	// Pin Configuration
	pinMode(SS, OUTPUT );
	digitalWrite(SS, HIGH);
	
	SPI_CTS	 = SPI_INACTIVE; 
	// Set MOSI and SCK output, all others input
	pinMode(MOSI, OUTPUT);
	pinMode(SCK, OUTPUT);
	// MISO pin automatically overrides to INPUT.
	
	// Enable SPI, Master, set clock rate
	SPCR = _BV(SPE) | _BV(MSTR) | ((bitOrder == LSBFIRST) ? _BV(DORD) : 0) |
	(mode & SPI_MODE_MASK) | ((clockDiv >> 1) & SPI_CLOCK_MASK);
	SPSR = clockDiv & SPI_2XCLOCK_MASK;

}

/*************************************************************************
Function: spi_master_transmit()
Purpose:  transmit string to SPI and launch the SPI communication
Input:    string to be transmitted
Returns:  none
**************************************************************************/
void spi_master_transmit(const char *s){
	
	uint16_t tmptail=0;
	
	// Stores datas in buffer
	while (*s) {
		spi_putc(*s++);
	}
	
	// Checks if ready to send and proceed
	if(SPI_CTS==SPI_INACTIVE){
		
		SPI_CTS=SPI_ACTIVE;
		digitalWrite(SS, LOW);// Pull-down the line
		
		if ( SPI_TxHead != SPI_TxTail) {
			tmptail = (SPI_TxTail + 1) & SPI_TX_BUFFER_MASK;
			SPI_TxTail = tmptail;
			/* get one byte from buffer and write it to SPI */
			SPDR = SPI_TxBuf[tmptail];  /* start transmission */
		}
	}
	
}
/*************************************************************************
Function: spi_master_read()
Purpose:  transmit 0x00 to get the number of bytes requested
Input:    numberOfBytes that want to be read
Returns:  none
**************************************************************************/
void spi_master_read(uint8_t numberOfBytes){
	
	SPI_bytesRequest = numberOfBytes;
	
	// Checks if ready to send and proceed
	if(SPI_CTS==SPI_INACTIVE){
			
		SPI_CTS=SPI_ACTIVE;
		digitalWrite(SS, LOW);// Pull-down the line
		SPDR = 0x00; /* start transmission */
	}
}
#elif defined (SPI_SLAVE_ENABLED)
/*************************************************************************
Function: spi_slave_init()
Purpose:  Initialize SPI in Slave Mode
Input:    none
Returns:  none
**************************************************************************/
void spi_slave_init(void){

	// Set MISO output, all others input
	pinMode(MISO,OUTPUT);
	// set SPI enable, spi interrupts enable
	SPCR = (1<<SPE)|(1<<SPIE);
	
	// Clear SPI Interrupt by reading SPSR and SPDR
	uint8_t dummy = 0x00;
	dummy = SPSR;
	dummy = SPDR;
	SPDR=0x00; // Set SPDR to 0x00
	
	SPI_SPDR = SPI_SPDR_EMPTY;

}
#endif //Endof MASTER/SLAVE functions

/************************************************************************/
/*   ISR                                                                */
/************************************************************************/
/*************************************************************************
Function: SPI interrupt
Purpose:  called when the SS pin has been put low
**************************************************************************/
ISR(SPI_STC_vect)
{
	uint16_t tmphead=0;
	uint16_t tmptail=0;
	/* SPI MASTER */
#if defined (SPI_MASTER_ENABLED)
	
	//RECEIVE
	// calculate buffer index
	tmphead = ( SPI_RxHead + 1) & SPI_RX_BUFFER_MASK;
	if ( tmphead == SPI_RxTail ) {
		// error: receive buffer overflow
	} else {
		// store new index
		SPI_RxHead = tmphead;
		// store received data in buffer
		SPI_RxBuf[tmphead] = SPDR;
	}

	// SEND
	if ( SPI_TxHead != SPI_TxTail) {
		// calculate and store new buffer index
		tmptail = (SPI_TxTail + 1) & SPI_TX_BUFFER_MASK;
		SPI_TxTail = tmptail;
		// get one byte from buffer and write it to UART
		SPDR = SPI_TxBuf[tmptail];  // start transmission
	}
	else if(SPI_bytesRequest>0){
		SPI_bytesRequest--;
		SPDR = 0x00;
	}
	else {
		// tx buffer empty, STOP the transmission
		digitalWrite(SS, HIGH);
		SPI_CTS = SPI_INACTIVE;
	}

/* SPI Slave */
#elif defined(SPI_SLAVE_ENABLED)
	
	//RECEIVE
	// calculate buffer index
	tmphead = ( SPI_RxHead + 1) & SPI_RX_BUFFER_MASK;
	if ( tmphead == SPI_RxTail ) {
		// error: receive buffer overflow
	} else {
		// store new index
		SPI_RxHead = tmphead;
		// store received data in buffer
		SPI_RxBuf[tmphead] = SPDR;
	}

	// SEND
	if ( SPI_TxHead != SPI_TxTail) {
		// calculate and store new buffer index
		tmptail = (SPI_TxTail + 1) & SPI_TX_BUFFER_MASK;
		SPI_TxTail = tmptail;
		// get one byte from buffer and write it to UART
		SPDR = SPI_TxBuf[tmptail];  //start transmission
	}
	else{
		SPDR=0x00;
	}
	
#endif //End of Master/Slave ISR
}

/*************************************************************************
Function: spi_close()
Purpose:  Close SPI, flush and clear any received datas
Input:    none
Returns:  none
**************************************************************************/
void spi_close(void){
	
	spi_flush();
	
	SPCR = (0x00);
	pinMode(SS, INPUT);
	digitalWrite(SS,LOW);	
}

/*************************************************************************
Function: spi_getc()
Purpose:  return byte from ringbuffer
Returns:  byte:  received byte from ringbuffer
**************************************************************************/
uint8_t spi_getc(void)
{
	uint16_t tmptail;
	uint8_t data;

	if ( SPI_RxHead == SPI_RxTail ) {
		/* no data available */
	}

	/* calculate /store buffer index */
	tmptail = (SPI_RxTail + 1) & SPI_RX_BUFFER_MASK;
	SPI_RxTail = tmptail;

	/* get data from receive buffer */
	data = SPI_RxBuf[tmptail];

	return data;
}

/*************************************************************************
Function: spi_putc()
Purpose:  write byte to ringbuffer for transmitting via SPI
Input:    byte to be transmitted
Returns:  none
**************************************************************************/
void spi_putc(uint8_t data)
{
	uint16_t tmphead;

	tmphead  = (SPI_TxHead + 1) & SPI_TX_BUFFER_MASK;
	
#if defined (SPI_SLAVE_ENABLED)
	// If no char in SPDR -> fill directly
	if (SPI_TxHead == SPI_TxTail && SPI_SPDR==SPI_SPDR_EMPTY){
		SPDR = data;
		SPI_SPDR = SPI_SPDR_FULL;
	}
	else if (tmphead != SPI_TxTail){
		SPI_TxBuf[tmphead] = data;
		SPI_TxHead = tmphead;
	}
#elif defined (SPI_MASTER_ENABLED)
	if (tmphead != SPI_TxTail){
		SPI_TxBuf[tmphead] = data;
		SPI_TxHead = tmphead;
	}
#endif
	
}

/*************************************************************************
Function: spi_puts()
Purpose:  transmit string to SPI
Input:    string to be transmitted
Returns:  none
**************************************************************************/
void spi_puts(const char *s )
{
	while (*s) {
		spi_putc(*s++);
	}

}

/*************************************************************************
Function: spi_available()
Purpose:  Determine the number of bytes waiting in the receive buffer
Input:    None
Returns:  Integer number of bytes in the receive buffer
**************************************************************************/
uint16_t spi_available(void)
{
	return (SPI_RX_BUFFER_SIZE + SPI_RxHead - SPI_RxTail) & SPI_RX_BUFFER_MASK;
}

/*************************************************************************
Function: spi_flush()
Purpose:  Flush bytes waiting the receive buffer.  Acutally ignores them.
Input:    None
Returns:  None
**************************************************************************/
void spi_flush(void)
{
	SPI_RxHead = SPI_RxTail;
}