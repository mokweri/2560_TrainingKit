/*
 * gpio.h
 *
 * Created: 02/08/2021 08:39:51
 *  Author: OBED
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "tk2560.h"

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int  digitalRead(uint8_t pin);

#define EXTERNAL_NUM_INTERRUPTS 8 //for ATmega2560
#define EXTERNAL_INT_0 0
// #define EXTERNAL_INT_1 1
#define EXTERNAL_INT_2 2
#define EXTERNAL_INT_3 3
#define EXTERNAL_INT_4 4
#define EXTERNAL_INT_5 5
#define EXTERNAL_INT_6 6
#define EXTERNAL_INT_7 7
#endif /* GPIO_H_ */