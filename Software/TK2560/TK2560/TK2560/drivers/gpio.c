/*
 * gpio.c
 *
 * Created: 02/08/2021 08:42:21
 *  Author: OBED
 */ 
#include "gpio.h"

void pinMode(uint8_t pin, uint8_t mode)
{
	uint8_t bit = PinToBitMask(pin);
	uint8_t port = PinToPort(pin);
}
