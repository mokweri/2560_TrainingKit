/*
 * hardwareSerial.h
 *
 * Created: 19/08/2021 14:41:31
 *  Author: OBED
 */ 


#ifndef HARDWARESERIAL_H_
#define HARDWARESERIAL_H_

#include <util/atomic.h>
#include "tk2560.h"

#define SERIAL_TX_BUFFER_SIZE 64
#define SERIAL_RX_BUFFER_SIZE 64
typedef uint8_t tx_buffer_index_t;
typedef uint8_t rx_buffer_index_t;

/*
 Serial config - (SERIAL_Framesize+Parity+Stop bits)
 These configuration apply to UCSRnC register
*/
#define SERIAL_5N1 0x00 //No parity
#define SERIAL_6N1 0x02
#define SERIAL_7N1 0x04
#define SERIAL_8N1 0x06 //(DEFAULT)
#define SERIAL_5N2 0x08 
#define SERIAL_6N2 0x0A
#define SERIAL_7N2 0x0C
#define SERIAL_8N2 0x0E
#define SERIAL_5E1 0x20 //Even parity
#define SERIAL_6E1 0x22
#define SERIAL_7E1 0x24
#define SERIAL_8E1 0x26
#define SERIAL_5E2 0x28
#define SERIAL_6E2 0x2A
#define SERIAL_7E2 0x2C
#define SERIAL_8E2 0x2E
#define SERIAL_5O1 0x30 //Odd Parity
#define SERIAL_6O1 0x32
#define SERIAL_7O1 0x34
#define SERIAL_8O1 0x36
#define SERIAL_5O2 0x38
#define SERIAL_6O2 0x3A
#define SERIAL_7O2 0x3C
#define SERIAL_8O2 0x3E

/************************************************************************/
/*     VARIABLES Definition                                             */
/************************************************************************/
/*----Serial 0---------*/
unsigned char _rx_buffer0[SERIAL_RX_BUFFER_SIZE];
unsigned char _tx_buffer0[SERIAL_TX_BUFFER_SIZE];

volatile rx_buffer_index_t _rx_buffer0_head;
volatile rx_buffer_index_t _rx_buffer0_tail;
volatile tx_buffer_index_t _tx_buffer0_head;
volatile tx_buffer_index_t _tx_buffer0_tail;

unsigned long _startMillis0;
unsigned long _timeout0; //DEFAULT timeout

/*----Serial 1---------*/
// unsigned char _rx_buffer1[SERIAL_RX_BUFFER_SIZE];
// unsigned char _tx_buffer1[SERIAL_TX_BUFFER_SIZE];
// 
// volatile rx_buffer_index_t _rx_buffer1_head;
// volatile rx_buffer_index_t _rx_buffer1_tail;
// volatile tx_buffer_index_t _tx_buffer1_head;
// volatile tx_buffer_index_t _tx_buffer1_tail;

unsigned long _startMillis1;
unsigned long _timeout1; //DEFAULT timeout

/*----Serial 2---------*/
unsigned char _rx_buffer[SERIAL_RX_BUFFER_SIZE];
unsigned char _tx_buffer[SERIAL_TX_BUFFER_SIZE];

volatile rx_buffer_index_t _rx_buffer_head;
volatile rx_buffer_index_t _rx_buffer_tail;
volatile tx_buffer_index_t _tx_buffer_head;
volatile tx_buffer_index_t _tx_buffer_tail;

unsigned long _startMillis;
unsigned long _ttimeout; //DEFAULT timeout

/*----Serial 3---------*/
// unsigned char _rx_buffer3[SERIAL_RX_BUFFER_SIZE];
// unsigned char _tx_buffer3[SERIAL_TX_BUFFER_SIZE];
// 
// volatile rx_buffer_index_t _rx_buffer3_head;
// volatile rx_buffer_index_t _rx_buffer3_tail;
// volatile tx_buffer_index_t _tx_buffer3_head;
// volatile tx_buffer_index_t _tx_buffer3_tail;
// 
// unsigned long _startMillis3;
// unsigned long _timeout13; //DEFAULT timeout

/************************************************************************/
/*               APIs                                                   */
/************************************************************************/
/*-------Hardware Serial 0----------------------------------------*/
void Serial0_begin(unsigned long baud, uint8_t config );
void Serial0_setTimeout(unsigned long timeout);
int Serial0_available(void);
int Serial0_read(void);		//reads one byte
int Serial0_timedRead(void); //reads one byte with timeout
size_t Serial0_readBytes(char *buffer, size_t length);
size_t Serial0_readBytesUntil(char terminator, char *buffer, size_t length);
size_t Serial0_readAllBytes(char *buffer, size_t length);
size_t Serial0_write(uint8_t c);
size_t Serial0_print(char *string);
void Serial0_flush(void);
void Serial0_end(void);

/*-------Hardware Serial 1----------------------------------------*/
// void Seria1_begin(unsigned long baud, uint8_t config );
// void Serial1_setTimeout(unsigned long timeout);
// int Serial1_available(void);
// int Serial1_read(void);		//reads one byte
// int Serial1_timedRead(void); //reads one byte with timeout
// size_t Serial1_readBytes(char *buffer, size_t length);
// size_t Serial1_readBytesUntil(char terminator, char *buffer, size_t length);
// size_t Serial1_readAllBytes(char *buffer, size_t length);
// size_t Serial1_write(uint8_t c);
// size_t Serial1_print(char *string);
// void Serial1_flush(void);
// void Serial1_end(void);

/*-------Hardware Serial 2----------------------------------------*/
void Serial2_begin(unsigned long baud, uint8_t config );
void Serial2_setTimeout(unsigned long timeout);
int Serial2_available(void);
int Serial2_read(void);		//reads one byte
int Serial2_timedRead(void); //reads one byte with timeout
size_t Serial2_readBytes(char *buffer, size_t length);
size_t Serial2_readBytesUntil(char terminator, char *buffer, size_t length);
size_t Serial2_readAllBytes(char *buffer, size_t length);
size_t Serial2_write(uint8_t c);
size_t Serial2_print(char *string);
void Serial2_flush(void);
void Serial2_end(void);

/*-------Hardware Serial 3----------------------------------------*/
// void Serial3_begin(unsigned long baud, uint8_t config );
// void Serial3_setTimeout(unsigned long timeout);
// int Serial3_available(void);
// int Serial3_read(void);		//reads one byte
// int Serial3_timedRead(void); //reads one byte with timeout
// size_t Serial3_readBytes(char *buffer, size_t length);
// size_t Serial3_readBytesUntil(char terminator, char *buffer, size_t length);
// size_t Serial3_readAllBytes(char *buffer, size_t length);
// size_t Serial3_write(uint8_t c);
// size_t Serial3_print(char *string);
// void Serial3_flush(void);
// void Serial3_end(void);



#endif /* HARDWARESERIAL_H_ */