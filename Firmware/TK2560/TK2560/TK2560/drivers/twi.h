/*
 * twi.h
 *
 * Created: 23/08/2021 09:19:04
 *  Author: OBED
 */ 


#ifndef TWI_H_
#define TWI_H_

#include "tk2560.h"
#include <inttypes.h>

#define TWI_FREQ 100000L //100kHz Can be configured up to 400kHz

#ifndef TWI_BUFFER_LENGTH
#define TWI_BUFFER_LENGTH 32
#endif

//TWI States
#define TWI_READY 0
#define TWI_MRX   1 //Master Receiver
#define TWI_MTX   2 //Master Transmitter
#define TWI_SRX   3 //Slave Receiver
#define TWI_STX   4 //Slave Transmitter

void twi_init(void);
void twi_disable(void);
void twi_setAddress(uint8_t);
void twi_setFrequency(uint32_t);
uint8_t twi_readFrom(uint8_t, uint8_t*, uint8_t, uint8_t);
uint8_t twi_writeTo(uint8_t address, uint8_t* data, uint8_t length, uint8_t wait, uint8_t sendStop);
uint8_t twi_transmit(const uint8_t*, uint8_t);
void twi_attachSlaveRxEvent( void (*)(uint8_t*, int) );
void twi_attachSlaveTxEvent( void (*)(void) );
void twi_reply(uint8_t);
void twi_stop(void);
void twi_releaseBus(void);
void twi_setTimeoutInMicros(uint32_t, bool);
void twi_handleTimeout(bool);
bool twi_manageTimeoutFlag(bool);

#endif /* TWI_H_ */