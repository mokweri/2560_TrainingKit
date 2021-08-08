/*
 * gpio.c
 *
 * Created: 02/08/2021 08:42:21
 *  Author: OBED
 */ 
#include "gpio.h"


void pinMode(uint8_t pin, uint8_t mode)
{
	uint8_t bit = pinToBitMask(pin);
	uint8_t port = pinToPort(pin);
	volatile uint8_t *reg, *out;
	
	if (port == NOT_A_PIN) return;
	
	reg = portDDRRegister(port);
	out = portOutputRegister(port);
	
	if (mode == INPUT)
	{
		uint8_t oldSREG = SREG;
		cli();
		*reg &= ~bit;
		*out &= ~bit;
		SREG = oldSREG;
	}else if(mode == INPUT_PULLUP)
	{
		uint8_t oldSREG = SREG;
		cli();
		*reg &= ~bit;
		*out |= bit;
		SREG = oldSREG;
	}else{
		//output
		uint8_t oldSREG = SREG;
		cli();
		*reg |= bit;
		SREG = oldSREG;
	}
		
}

void digitalWrite(uint8_t pin, uint8_t val)
{
	uint8_t bit = pinToBitMask(pin);
	uint8_t port = pinToPort(pin);
	volatile uint8_t *out;
	
	if (port == NOT_A_PIN) return;
	
	out = portOutputRegister(port);
	
	uint8_t oldSREG = SREG;
	cli();
	
	if (val == LOW) {
		*out &= ~bit;
	} else {
		*out |= bit;
	}
	
	SREG = oldSREG;
	
}

void togglePin(uint8_t pin)
{
	uint8_t bit = pinToBitMask(pin);
	uint8_t port = pinToPort(pin);
	volatile uint8_t *out;
	
	if (port == NOT_A_PIN) return;
	
	out = portOutputRegister(port);
	
	uint8_t oldSREG = SREG;
	cli();
	
	//toggle
	*out ^= bit;
	
	SREG = oldSREG;
}

int  digitalRead(uint8_t pin)
{
	uint8_t bit = pinToBitMask(pin);
	uint8_t port = pinToPort(pin);
	
	if (port == NOT_A_PIN) return LOW;
	
	if (*portInputRegister(port) & bit) return HIGH;
	return LOW;	
}
