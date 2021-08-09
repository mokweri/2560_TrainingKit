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

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "binary.h"

#define F_CPU 1000000UL
#define HIGH	0x1
#define LOW		0x0

#define INPUT			0x0
#define OUTPUT			0x1
#define INPUT_PULLUP	0x2

#define NOT_A_PIN	0
#define NOT_A_PORT	0
#define NOT_USED	0

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

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


#define Pin_PG5		1	// PG 5 ** 1 ** OC0B - PWM
#define Pin_PE0		2	// PE 0 ** 2 ** USART0_RX
#define Pin_PE1		3	// PE 1 ** 3 ** USART0_TX
#define Pin_PE2		4	// PE 2 ** 4 **
#define Pin_PE3		5	// PE 3 ** 5 ** OC3A-PWM
#define Pin_PE4		6	// PE 4 ** 6 ** OC3B-PWM, INT4
#define Pin_PE5		7	// PE 5 ** 7 ** OC3C-PWM, INT5
#define Pin_PE6		8	// PE 6 ** 8 ** INT6
#define Pin_PE7		9	// PE 7 ** 9 ** INT7
	//		** 10 ** VCC
	//		** 11 ** GND
#define Pin_PH0		12	// PH 0 ** 12 ** USART2_RX
#define Pin_PH1		13	// PH 1 ** 13 ** USART2_TX
#define Pin_PH2		14	// PH 2 ** 14 **
#define Pin_PH3		15	// PH 3 ** 15 ** OC4A-PWM
#define Pin_PH4		16	// PH 4 ** 16 ** OC4B-PWM
#define Pin_PH5		17	// PH 5 ** 17 ** OC4C-PWM
#define Pin_PH6		18	// PH 6 ** 18 ** OC2B-PWM
#define Pin_PB0		19	// PB 0 ** 19 ** SPI_SS
#define Pin_PB1		20	// PB 1 ** 20 ** SPI_SCK
#define Pin_PB2		21	// PB 2 ** 21 ** SPI_MOSI
#define Pin_PB3		22	// PB 3 ** 22 ** SPI_MISO
#define Pin_PB4		23	// PB 4 ** 23 ** OC2A-PWM, PCINT4
#define Pin_PB5		24	// PB 5 ** 24 ** OC1A-PWM, PCINT5
#define Pin_PB6		25	// PB 6 ** 25 ** OC1B-PWM, PCINT6
#define Pin_PB7		26	// PB 7 ** 26 ** OC0A/OC1C-PWM, PCINT7
#define Pin_PH7		27	// PH 7 ** 27 **
#define Pin_PG3		28	// PG 3 ** 28 **
#define Pin_PG4		29	// PG 4 ** 29 **
	//		** 30 ** RESET
	//		** 31 ** VCC
	//		** 32 ** GND
	//		** 33 ** XTAL2
	//		** 34 ** XTAL1
#define Pin_PL0		35	// PL 0 ** 35 **
#define Pin_PL1		36	// PL 1 ** 36 **
#define Pin_PL2		37	// PL 2 ** 37 **
#define Pin_PL3		38	// PL 3 ** 38 ** OC5A-PWM
#define Pin_PL4		39	// PL 4 ** 39 ** OC5B-PWM
#define Pin_PL5		40	// PL 5 ** 40 ** OC5C-PWM
#define Pin_PL6		41	// PL 6 ** 41 **
#define Pin_PL7		42	// PL 7 ** 42 **
#define Pin_PD0		43	// PD 0 ** 43 ** I2C_SCL, INT0
#define Pin_PD1		44	// PD 1 ** 44 ** I2C_SDA, INT1
#define Pin_PD2		45	// PD 2 ** 45 ** USART1_RX, INT2
#define Pin_PD3		46	// PD 3 ** 46 ** USART1_TX, INT3
#define Pin_PD4		47	// PD 4 ** 47 **
#define Pin_PD5		48	// PD 5 ** 48 **
#define Pin_PD6		49	// PD 6 ** 49 **
#define Pin_PD7		50	// PD 7 ** 50 **
#define Pin_PG0		51	// PG 0 ** 51 **
#define Pin_PG1		52	// PG 1 ** 52 **
#define Pin_PC0		53	// PC 0 ** 53 **
#define Pin_PC1		54	// PC 1 ** 54 **
#define Pin_PC2		55	// PC 2 ** 55 **
#define Pin_PC3		56	// PC 3 ** 56 **
#define Pin_PC4		57	// PC 4 ** 57 **
#define Pin_PC5		58	// PC 5 ** 58 **
#define Pin_PC6		59	// PC 6 ** 59 **
#define Pin_PC7		60	// PC 7 ** 60 **
	//		** 61 ** VCC
	//		** 62 ** GND
#define Pin_PJ0		63	// PJ 0 ** 63 ** USART3_RX
#define Pin_PJ1		64	// PJ 1 ** 64 ** USART3_TX
#define Pin_PJ2		65	// PJ 2 ** 65 ** PCINT11
#define Pin_PJ3		66	// PJ 3 ** 66 ** PCINT12
#define Pin_PJ4		67	// PJ 4 ** 67 ** PCINT13
#define Pin_PJ5		68	// PJ 5 ** 68 ** PCINT14
#define Pin_PJ6		69	// PJ 6 ** 69 ** PCINT15
#define Pin_PG2		70	// PG 2 ** 70 **
#define Pin_PA7		71	// PA 7 ** 71 **
#define Pin_PA6		72	// PA 6 ** 72 **
#define Pin_PA5		73	// PA 5 ** 73 **
#define Pin_PA4		74	// PA 4 ** 74 **
#define Pin_PA3		75	// PA 3 ** 75 **
#define Pin_PA2		76	// PA 2 ** 76 **
#define Pin_PA1		77	// PA 1 ** 77 **
#define Pin_PA0		78	// PA 0 ** 78 **
#define Pin_PJ7		79	// PJ 7 ** 79 **
	//		** 80 ** VCC
	//		** 81 ** GND
#define Pin_PK7		82	// PK 7 ** 82 ** ADC15, PCINT23
#define Pin_PK6		83	// PK 6 ** 83 ** ADC14, PCINT22
#define Pin_PK5		84	// PK 5 ** 84 ** ADC13, PCINT21
#define Pin_PK4		85	// PK 4 ** 85 ** ADC12, PCINT20
#define Pin_PK3		86	// PK 3 ** 86 ** ADC11, PCINT19
#define Pin_PK2		87	// PK 2 ** 87 ** ADC10, PCINT18
#define Pin_PK1		88	// PK 1 ** 88 ** ADC9, PCINT17
#define Pin_PK0		89	// PK 0 ** 89 ** ADC8, PCINT16
#define Pin_PF7		90	// PF 7 ** 90 ** ADC7
#define Pin_PF6		91	// PF 6 ** 91 ** ADC6
#define Pin_PF5		92	// PF 5 ** 92 ** ADC5
#define Pin_PF4		93	// PF 4 ** 93 ** ADC4
#define Pin_PF3		94	// PF 3 ** 94 ** ADC3
#define Pin_PF2		95	// PF 2 ** 95 ** ADC2
#define Pin_PF1		96	// PF 1 ** 96 ** ADC1
#define Pin_PF0		97	// PF 0 ** 97 ** ADC0
	//		** 98 ** AREF
	//		** 99 ** GND
	//		** 100 ** AVCC

//SPI Pins definition
#define PIN_SPI_SS    Pin_PB0
#define PIN_SPI_MOSI  Pin_PB2
#define PIN_SPI_MISO  Pin_PB3
#define PIN_SPI_SCK   Pin_PB1

// static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

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

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
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


#define pinToPort(P) ( pgm_read_byte( pin_to_port_PGM + (P) ) )
#define pinToBitMask(P) ( pgm_read_byte( pin_to_bit_mask_PGM + (P) ) )
//#define pinToTimer(P) ( pgm_read_byte( pin_to_timer_PGM + (P) ) )
#define portOutputRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_output_PGM + (P))) )
#define portInputRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_input_PGM + (P))) )
#define portDDRRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_ddr_PGM + (P))) )



#include "gpio.h"

#endif /* TK2560_H_ */