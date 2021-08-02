/*
 * tk2560.h
 *
 * Created: 02/08/2021 08:18:24
 *  Author: OBED
 */ 


#ifndef TK2560_H_
#define TK2560_H_

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define HIGH	0x1
#define LOW		0x0

#define INPUT			0x0
#define OUTPUT			0x1
#define INPUT_PULLUP	0x2

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352


/************************************************************************/
/*                        MACROS                                        */
/************************************************************************/

// undefine stdlib's abs if encountered
#ifdef abs
#undef abs
#endif

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

#define interrupts() sei()
#define noInterrupts() cli()

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

//#define _BV(n) (1 << n)

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))

/************************************************************************/
/*                           API DEFINITIONS                            */
/************************************************************************/

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);

/************************************************************************/
/*                           OTHER DEFINITIONS                          */
/************************************************************************/
// Get the bit location within the hardware port of the given virtual pin.
// This comes from the pins.h file for the board configuration.
extern const uint16_t PROGMEM port_to_ddr_PGM[];
extern const uint16_t PROGMEM port_to_input_PGM[];
extern const uint16_t PROGMEM port_to_output_PGM[];

extern const uint8_t PROGMEM pin_to_port_PGM[];
extern const uint8_t PROGMEM pin_to_bit_mask_PGM[];

// These perform slightly better as macros compared to inline functions
#define pinToPort(P) ( pgm_read_byte( pin_to_port_PGM + (P) ) )
#define pinToBitMask(P) ( pgm_read_byte( pin_to_bit_mask_PGM + (P) ) )
//#define pinToTimer(P) ( pgm_read_byte( digital_pin_to_timer_PGM + (P) ) )
#define portOutputRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_output_PGM + (P))) )
#define portInputRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_input_PGM + (P))) )
#define portDDRRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_ddr_PGM + (P))) )

#define NOT_A_PIN 0
#define NOT_A_PORT 0

//PORTS
#define PA 1
#define PB 2
#define PC 3
#define PD 4
#define PE 5
#define PF 6
#define PG 7
#define PH 8
#define PJ 10
#define PK 11
#define PL 12


#include "pins.h"

#endif /* TK2560_H_ */