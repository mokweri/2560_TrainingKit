/*
 * spi.h
 *
 * Created: 24/08/2021 09:14:00
 *  Author: OBED
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "tk2560.h"

/************************************************************************/
/* Constants and macros                                                 */
/************************************************************************/

/* SPI Mode */
#define SPI_MASTER_ENABLED
//#define SPI_SLAVE_ENABLED

/* Set size of receive and transmit buffers */
#ifndef SPI_RX_BUFFER_SIZE
#define SPI_RX_BUFFER_SIZE 64 /**< Size of the circular receive buffer, must be power of 2 */
#endif

#ifndef SPI_TX_BUFFER_SIZE
#define SPI_TX_BUFFER_SIZE 64 /**< Size of the circular transmit buffer, must be power of 2 */
#endif

#define LSBFIRST 0
#define MSBFIRST 1

/* SPI Clock */
// Clock settings are defined as follows. Note that this shows SPI2X
// inverted, so the bits form increasing numbers. 
// Also note that fosc/64 appears twice
// SPR1 SPR0 ~SPI2X Freq
//   0    0     0   fosc/2
//   0    0     1   fosc/4
//   0    1     0   fosc/8
//   0    1     1   fosc/16
//   1    0     0   fosc/32
//   1    0     1   fosc/64
//   1    1     0   fosc/64
//   1    1     1   fosc/128
#define SPI_CLOCK_DIV4		0x00
#define SPI_CLOCK_DIV16		0x01
#define SPI_CLOCK_DIV64		0x02
#define SPI_CLOCK_DIV128	0x03
#define SPI_CLOCK_DIV2		0x04
#define SPI_CLOCK_DIV8		0x05
#define SPI_CLOCK_DIV32		0x06

/* SPI Mode */
#define SPI_MODE0 0x00	//CPOL=0, CPHA=0
#define SPI_MODE1 0x04	//CPOL=0, CPHA=1
#define SPI_MODE2 0x08	//CPOL=1, CPHA=0
#define SPI_MODE3 0x0C	//CPOL=1, CPHA=1

#define SPI_MODE_MASK    0x0C  // CPOL = bit 3, CPHA = bit 2 on SPCR
#define SPI_CLOCK_MASK   0x03  // SPR1 = bit 1, SPR0 = bit 0 on SPCR
#define SPI_2XCLOCK_MASK 0x01  // SPI2X = bit 0 on SPSR

// define SPI_AVR_EIMSK for AVR boards with external interrupt pins
#define SPI_AVR_EIMSK  EIMSK

/* Slave structure */
struct spi_slave_info
{
	uint8_t pin;
	uint8_t port;
	uint8_t ddr;
};

/************************************************************************/
/*  Functions prototype                                                  */
/************************************************************************/
/*************************************************************************
Function: spi_master_init()
Purpose:  Initialize SPI in Master Mode
Input:    mode SPI_MODEx (x : 0 -> 3)
Input:    clock SPI_CLOCK_DIVx (x : 2, 4, 8, 16, 32, 64 or 128)
Input:    bitOrder: LSBFIRST, MSBFIRST
Returns:  none
**************************************************************************/
void spi_master_init(uint8_t mode, uint8_t clockDiv, uint8_t bitOrder);

/**
   @brief   Initialize SPI in Slave Mode
   @param   none
   @return  none
*/
void spi_slave_init(void);

/**
   @brief   Close SPI, flush and clear any received datas
   @param   none
   @return  none
*/
void spi_close(void);

/**
 *  @brief   Put string to ringbuffer for transmitting via SPI & start transmission
 *			 Stop when nothing more to transmit
 *  @param   s string to be transmitted
 *  @return  none
 */
void spi_master_transmit(const char *s);

/**
 *  @brief   Read x bytes from the slave
 *  @param   numberOfBytes to read from the slave
 *  @return  none
 */
void spi_master_read(uint8_t numberOfBytes);

//extern void spi_master_addSlave(spi_slave_info slave);

//extern void spi_master_transmitToSlave(spi_slave_info slave, const char *s);

/**
 *  @brief   Get received byte from ringbuffer
 *
 * Returns in the lower byte the received character and in the 
 * higher byte the last receive error.
 * SPI_NO_DATA is returned when no data is available.
 *
 *  @return  byte:  received byte from ringbuffer
 */
uint8_t spi_getc(void);

/**
 *  @brief   Put byte to ringbuffer for transmitting via SPI
 *  @param   data byte to be transmitted
 *  @return  none
 */
void spi_putc(uint8_t data);

/**
 *  @brief   Put string to ringbuffer for transmitting via SPI
 *
 *  The string is buffered by the SPI library in a circular buffer
 *  and one character at a time is transmitted to the SPI using interrupts.
 *  Blocks if it can not write the whole string into the circular buffer.
 * 
 *  @param   s string to be transmitted
 *  @return  none
 */
void spi_puts(const char *s );

/**
 *  @brief   Return number of bytes waiting in the receive buffer
 *  @return  bytes waiting in the receive buffer
 */
uint16_t spi_available(void);

/**
 *  @brief   Flush bytes waiting in receive buffer
 */
void spi_flush(void);

#endif /* SPI_H_ */