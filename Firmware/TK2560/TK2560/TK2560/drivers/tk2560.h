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
#include <stdio.h>
#include <math.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "pinMap.h"

#define F_CPU 16000000UL
#define HIGH	0x1
#define LOW		0x0

#define INPUT			0x0
#define OUTPUT			0x1
#define INPUT_PULLUP	0x2

#define NOT_A_PIN	0
#define NOT_A_PORT	0
#define NOT_USED	0
#define NOT_AN_INTERRUPT	-1
#define NOT_ADC_PIN	-1

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

#define EXTERNAL_NUM_INTERRUPTS 8 //for ATmega2560
#define EXTERNAL_INT_0 0
#define EXTERNAL_INT_1 1
#define EXTERNAL_INT_2 2
#define EXTERNAL_INT_3 3
#define EXTERNAL_INT_4 4
#define EXTERNAL_INT_5 5
#define EXTERNAL_INT_6 6
#define EXTERNAL_INT_7 7

#define CHANGE	1
#define FALLING 2
#define RISING	3

#define DEFAULT 1

/************************************************************************/
/*   TIMERS                                                             */
/************************************************************************/
#define NOT_ON_TIMER 0
#define TIMER0A 1
#define TIMER0B 2
#define TIMER1A 3
#define TIMER1B 4
#define TIMER1C 5
#define TIMER2  6
#define TIMER2A 7
#define TIMER2B 8

#define TIMER3A 9
#define TIMER3B 10
#define TIMER3C 11
#define TIMER4A 12
#define TIMER4B 13
#define TIMER4C 14
#define TIMER4D 15
#define TIMER5A 16
#define TIMER5B 17
#define TIMER5C 18

// /* Status Register */
#ifndef SREG
#  if __AVR_ARCH__ >= 100
#    define SREG _SFR_MEM8(0x3F)
#  else
#    define SREG _SFR_IO8(0x3F)
#  endif
#endif

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

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L ) //e.g. 16Mhz/1M = 16 clk cycles per microsecond
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#ifndef _BV
#define _BV(n) (1 << n) 
#endif


#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))


extern const PROGMEM uint16_t  port_to_ddr_PGM[];
extern const PROGMEM uint16_t  port_to_input_PGM[];
extern const PROGMEM uint16_t  port_to_output_PGM[];
extern const PROGMEM uint8_t  pin_to_port_PGM[];
extern const PROGMEM uint8_t  pin_to_bit_mask_PGM[];
extern const PROGMEM uint8_t  pin_to_timer_PGM[];

//PCINT pins
// convert a normal pin to its PCINT number (0 - max 23), used by the user
#define pinToPCICR(p)	( (((p) >= 19) && ((p) <= 26)) || \
						  ((p) == 2)  || \
						  (((p) >= 63) && ((p) <= 69)) || \
						  (((p) >= 82) && ((p) <= 89)) ? (&PCICR) : ((uint8_t *)0) )

#define pinToPCICRbit(p) ( (((p) >= 19) && ((p) <= 26)) ? 0:  \
						   (((p) == 2) || (((p) >= 63) && ((p) <= 69))) ? 1 : \
						   ((((p) >= 82) && ((p) <= 89)) ? 2 : \
						   0 ) )

#define pinToPCMSK(p) ( (((p) >= 19) && ((p) <= 26)) ? (&PCMSK0):  \
						(((p) == 2) || ((p) >= 63) && ((p) <= 69)) ? (&PCMSK1) : \
						((((p) >= 82) && ((p) <= 89)) ? (&PCMSK2) : \
						((uint8_t *)0) ) )

#define pinToPCMSKbit(p) ( (((p) >= 19) && ((p) <= 26)) ? ((p) - 19) : \
						 ( ((p) == 2) ? 0 : \
						 ( (((p) >= 63) && ((p) <= 69)) ? ((p) - 62) : \
						 ( (((p) >= 82) && ((p) <= 89)) ? (89 - (p)) : \
						 0 ) ) ) ) 

#define pinToPinChangeInterrupt(p) (pinToPCICR(p) ? ((8 * (pinToPCICRbit(p) - PCIE0)) + pinToPCMSKbit(p)) : NOT_AN_INTERRUPT)

#define pinToADCChannel(p) ((((p) >= 90) && ((p) <= 97)) ? (97 - (p)) : \
							(((p) >= 82) && ((p) <= 89)) ? (97 - (p)) : \
							NOT_ADC_PIN	)

#define pinToPort(P) ( pgm_read_byte( pin_to_port_PGM + (P) ) )
#define pinToBitMask(P) ( pgm_read_byte( pin_to_bit_mask_PGM + (P) ) )
#define pinToTimer(P) ( pgm_read_byte( pin_to_timer_PGM + (P) ) )
#define portOutputRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_output_PGM + (P))) )
#define portInputRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_input_PGM + (P))) )
#define portDDRRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_ddr_PGM + (P))) )

/************************************************************************/
/*   APIs                                                               */
/************************************************************************/
// Digital I/O
void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
void togglePin(uint8_t pin);
int  digitalRead(uint8_t pin);

// PWM
void pwm_init(void);
void analogWrite(uint8_t pin, int val);

// Frequency generator - All timers[one Selected(3)]
void tone(uint8_t _pin, unsigned int frequency, unsigned long duration);
void noTone(uint8_t _pin);

//ADC
void adc_init(void);
int analogRead(uint8_t pin);
void analogReference(uint8_t mode);

// Timer0 & Delay
void millis_init(void);
unsigned long millis(void);
unsigned long micros(void);
void delay_ms(unsigned long ms);
void delay_us(unsigned int us);

//External Interrupts
void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode);
void detachInterrupt(uint8_t interruptNum);

//Pin change Interrupts
#include "pinChangeInterrupts.h"

//Serial
#include "hardwareSerial.h"
#include "twi.h"

// Board support packages(BSPs)
#include "bsp/lcd/lcd.h"
#include "bsp/rtc/ds1307.h"

#endif /* TK2560_H_ */