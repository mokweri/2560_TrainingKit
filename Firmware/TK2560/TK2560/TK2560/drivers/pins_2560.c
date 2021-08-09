/*
 * pins.c
 *
 * Created: 8/8/2021 12:24:47
 *  Author: Obed
 */ 

#include "tk2560.h"
#include <avr/pgmspace.h>



const PROGMEM uint16_t  port_to_ddr_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
	(uint16_t) &DDRE,
	(uint16_t) &DDRF,
	(uint16_t) &DDRG,
	(uint16_t) &DDRH,
	NOT_A_PORT,
	(uint16_t) &DDRJ,
	(uint16_t) &DDRK,
	(uint16_t) &DDRL,
};
const PROGMEM uint16_t  port_to_output_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
	(uint16_t) &PORTE,
	(uint16_t) &PORTF,
	(uint16_t) &PORTG,
	(uint16_t) &PORTH,
	NOT_A_PORT,
	(uint16_t) &PORTJ,
	(uint16_t) &PORTK,
	(uint16_t) &PORTL,
};

const PROGMEM uint16_t  port_to_input_PGM[] = {
	NOT_A_PIN,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
	(uint16_t) &PINE,
	(uint16_t) &PINF,
	(uint16_t) &PING,
	(uint16_t) &PINH,
	NOT_A_PIN,
	(uint16_t) &PINJ,
	(uint16_t) &PINK,
	(uint16_t) &PINL,};const PROGMEM uint8_t pin_to_port_PGM[] ={
	// PORTLIST
	// -------------------------------------------
	NOT_USED, // 0	
	PG	,	// PG 5 ** 1 ** OC0B - PWM
	PE	,	// PE 0 ** 2 ** USART0_RX
	PE	,	// PE 1 ** 3 ** USART0_TX
	PE	,	// PE 2 ** 4 ** 
	PE	,	// PE 3 ** 5 ** OC3A-PWM
	PE	,	// PE 4 ** 6 ** OC3B-PWM, INT4
	PE	,	// PE 5 ** 7 ** OC3C-PWM, INT5
	PE	,	// PE 6 ** 8 ** INT6
	PE	,	// PE 7 ** 9 ** INT7
	NOT_USED,	//	** 10 ** VCC
	NOT_USED,	//	** 11 ** GND
	PH	,	// PH 0 ** 12 ** USART2_RX
	PH	,	// PH 1 ** 13 ** USART2_TX
	PH	,	// PH 2 ** 14 **
	PH	,	// PH 3 ** 15 ** OC4A-PWM
	PH	,	// PH 4 ** 16 ** OC4B-PWM
	PH	,	// PH 5 ** 17 ** OC4C-PWM
	PH	,	// PH 6 ** 18 ** OC2B-PWM			
	PB	,	// PB 0 ** 19 ** SPI_SS
	PB	,	// PB 1 ** 20 ** SPI_SCK
	PB	,	// PB 2 ** 21 ** SPI_MOSI
	PB	,	// PB 3 ** 22 ** SPI_MISO
	PB	,	// PB 4 ** 23 ** OC2A-PWM, PCINT4
	PB	,	// PB 5 ** 24 ** OC1A-PWM, PCINT5
	PB	,	// PB 6 ** 25 ** OC1B-PWM, PCINT6
	PB	,	// PB 7 ** 26 ** OC0A/OC1C-PWM, PCINT7
	PH	,	// PH 7 ** 27 **
	PG	,	// PG 3 ** 28 **
	PG	,	// PG 4 ** 29 **	
	NOT_USED,	//	** 30 ** RESET
	NOT_USED,	//	** 31 ** VCC
	NOT_USED,	//	** 32 ** GND
	NOT_USED,	//	** 33 ** XTAL2
	NOT_USED,	//	** 34 ** XTAL1
	PL	,	// PL 0 ** 35 **
	PL	,	// PL 1 ** 36 **
	PL	,	// PL 2 ** 37 **
	PL	,	// PL 3 ** 38 ** OC5A-PWM
	PL	,	// PL 4 ** 39 ** OC5B-PWM
	PL	,	// PL 5 ** 40 ** OC5C-PWM
	PL	,	// PL 6 ** 41 **
	PL	,	// PL 7 ** 42 **
	PD	,	// PD 0 ** 43 ** I2C_SCL, INT0
	PD	,	// PD 1 ** 44 ** I2C_SDA, INT1
	PD	,	// PD 2 ** 45 ** USART1_RX, INT2
	PD	,	// PD 3 ** 46 ** USART1_TX, INT3
	PD	,	// PD 4 ** 47 **
	PD	,	// PD 5 ** 48 **
	PD	,	// PD 6 ** 49 **
	PD	,	// PD 7 ** 50 **
	PG	,	// PG 0 ** 51 **
	PG	,	// PG 1 ** 52 **
	PC	,	// PC 0 ** 53 **
	PC	,	// PC 1 ** 54 **
	PC	,	// PC 2 ** 55 **
	PC	,	// PC 3 ** 56 **
	PC	,	// PC 4 ** 57 **
	PC	,	// PC 5 ** 58 **
	PC	,	// PC 6 ** 59 **
	PC	,	// PC 7 ** 60 **
	NOT_USED,	//	** 61 ** VCC
	NOT_USED,	//	** 62 ** GND
	PJ	,	// PJ 0 ** 63 ** USART3_RX
	PJ	,	// PJ 1 ** 64 ** USART3_TX
	PJ	,	// PJ 2 ** 65 ** PCINT11
	PJ	,	// PJ 3 ** 66 ** PCINT12
	PJ	,	// PJ 4 ** 67 ** PCINT13
	PJ	,	// PJ 5 ** 68 ** PCINT14
	PJ	,	// PJ 6 ** 69 ** PCINT15
	PG	,	// PG 2 ** 70 ** 
	PA	,	// PA 7 ** 71 **
	PA	,	// PA 6 ** 72 **
	PA	,	// PA 5 ** 73 **
	PA	,	// PA 4 ** 74 **
	PA	,	// PA 3 ** 75 **
	PA	,	// PA 2 ** 76 **
	PA	,	// PA 1 ** 77 **
	PA	,	// PA 0 ** 78 **
	PJ	,	// PJ 7 ** 79 **
	NOT_USED,	//	** 80 ** VCC
	NOT_USED,	//	** 81 ** GND
	PK	,	// PK 7 ** 82 ** ADC15, PCINT23
	PK	,	// PK 6 ** 83 ** ADC14, PCINT22
	PK	,	// PK 5 ** 84 ** ADC13, PCINT21
	PK	,	// PK 4 ** 85 ** ADC12, PCINT20
	PK	,	// PK 3 ** 86 ** ADC11, PCINT19
	PK	,	// PK 2 ** 87 ** ADC10, PCINT18
	PK	,	// PK 1 ** 88 ** ADC9, PCINT17
	PK	,	// PK 0 ** 89 ** ADC8, PCINT16
	PF	,	// PF 7 ** 90 ** ADC7
	PF	,	// PF 6 ** 91 ** ADC6
	PF	,	// PF 5 ** 92 ** ADC5
	PF	,	// PF 4 ** 93 ** ADC4
	PF	,	// PF 3 ** 94 ** ADC3
	PF	,	// PF 2 ** 95 ** ADC2
	PF	,	// PF 1 ** 96 ** ADC1
	PF	,	// PF 0 ** 97 ** ADC0
	NOT_USED,	//	** 98 ** AREF
	NOT_USED,	//	** 99 ** GND
	NOT_USED,	//	** 100 ** AVCC

};


const PROGMEM uint8_t  pin_to_bit_mask_PGM[] = {
	// PIN IN PORT
	// -------------------------------------------
	NOT_USED,   // 0
	_BV(5)	,	// PG 5 ** 1 ** OC0B - PWM
	_BV(0)	,	// PE 0 ** 2 ** USART0_RX
	_BV(1)	,	// PE 1 ** 3 ** USART0_TX
	_BV(2)	,	// PE 2 ** 4 **
	_BV(3)	,	// PE 3 ** 5 ** OC3A-PWM
	_BV(4)	,	// PE 4 ** 6 ** OC3B-PWM, INT4
	_BV(5)	,	// PE 5 ** 7 ** OC3C-PWM, INT5
	_BV(6)	,	// PE 6 ** 8 ** INT6
	_BV(7)	,	// PE 7 ** 9 ** INT7
	NOT_USED,	//		** 10 ** VCC
	NOT_USED,	//		** 11 ** GND
	_BV(0)	,	// PH 0 ** 12 ** USART2_RX
	_BV(1)	,	// PH 1 ** 13 ** USART2_TX
	_BV(2)	,	// PH 2 ** 14 **
	_BV(3)	,	// PH 3 ** 15 ** OC4A-PWM
	_BV(4)	,	// PH 4 ** 16 ** OC4B-PWM
	_BV(5)	,	// PH 5 ** 17 ** OC4C-PWM
	_BV(6)	,	// PH 6 ** 18 ** OC2B-PWM
	_BV(0)	,	// PB 0 ** 19 ** SPI_SS
	_BV(1)	,	// PB 1 ** 20 ** SPI_SCK
	_BV(2)	,	// PB 2 ** 21 ** SPI_MOSI
	_BV(3)	,	// PB 3 ** 22 ** SPI_MISO
	_BV(4)	,	// PB 4 ** 23 ** OC2A-PWM, PCINT4
	_BV(5)	,	// PB 5 ** 24 ** OC1A-PWM, PCINT5
	_BV(6)	,	// PB 6 ** 25 ** OC1B-PWM, PCINT6
	_BV(7)	,	// PB 7 ** 26 ** OC0A/OC1C-PWM, PCINT7
	_BV(7)	,	// PH 7 ** 27 **
	_BV(3)	,	// PG 3 ** 28 **
	_BV(4)	,	// PG 4 ** 29 **
	NOT_USED,	//		** 30 ** RESET
	NOT_USED,	//		** 31 ** VCC
	NOT_USED,	//		** 32 ** GND
	NOT_USED,	//		** 33 ** XTAL2
	NOT_USED,	//		** 34 ** XTAL1
	_BV(0)	,	// PL 0 ** 35 **
	_BV(1)	,	// PL 1 ** 36 **
	_BV(2)	,	// PL 2 ** 37 **
	_BV(3)	,	// PL 3 ** 38 ** OC5A-PWM
	_BV(4)	,	// PL 4 ** 39 ** OC5B-PWM
	_BV(5)	,	// PL 5 ** 40 ** OC5C-PWM
	_BV(6)	,	// PL 6 ** 41 **
	_BV(7)	,	// PL 7 ** 42 **
	_BV(0)	,	// PD 0 ** 43 ** I2C_SCL, INT0
	_BV(1)	,	// PD 1 ** 44 ** I2C_SDA, INT1
	_BV(2)	,	// PD 2 ** 45 ** USART1_RX, INT2
	_BV(3)	,	// PD 3 ** 46 ** USART1_TX, INT3
	_BV(4)	,	// PD 4 ** 47 **
	_BV(5)	,	// PD 5 ** 48 **
	_BV(6)	,	// PD 6 ** 49 **
	_BV(7)	,	// PD 7 ** 50 **
	_BV(0)	,	// PG 0 ** 51 **
	_BV(1)	,	// PG 1 ** 52 **
	_BV(0)	,	// PC 0 ** 53 **
	_BV(1)	,	// PC 1 ** 54 **
	_BV(2)	,	// PC 2 ** 55 **
	_BV(3)	,	// PC 3 ** 56 **
	_BV(4)	,	// PC 4 ** 57 **
	_BV(5)	,	// PC 5 ** 58 **
	_BV(6)	,	// PC 6 ** 59 **
	_BV(7)	,	// PC 7 ** 60 **
	NOT_USED,	//		** 61 ** VCC
	NOT_USED,	//		** 62 ** GND
	_BV(0)	,	// PJ 0 ** 63 ** USART3_RX
	_BV(1)	,	// PJ 1 ** 64 ** USART3_TX
	_BV(2)	,	// PJ 2 ** 65 ** PCINT11
	_BV(3)	,	// PJ 3 ** 66 ** PCINT12
	_BV(4)	,	// PJ 4 ** 67 ** PCINT13
	_BV(5)	,	// PJ 5 ** 68 ** PCINT14
	_BV(6)	,	// PJ 6 ** 69 ** PCINT15
	_BV(2)	,	// PG 2 ** 70 **
	_BV(7)	,	// PA 7 ** 71 **
	_BV(6)	,	// PA 6 ** 72 **
	_BV(5)	,	// PA 5 ** 73 **
	_BV(4)	,	// PA 4 ** 74 **
	_BV(3)	,	// PA 3 ** 75 **
	_BV(2)	,	// PA 2 ** 76 **
	_BV(1)	,	// PA 1 ** 77 **
	_BV(0)	,	// PA 0 ** 78 **
	_BV(7)	,	// PJ 7 ** 79 **
	NOT_USED,	//		** 80 ** VCC
	NOT_USED,	//		** 81 ** GND
	_BV(7)	,	// PK 7 ** 82 ** ADC15, PCINT23
	_BV(6)	,	// PK 6 ** 83 ** ADC14, PCINT22
	_BV(5)	,	// PK 5 ** 84 ** ADC13, PCINT21
	_BV(4)	,	// PK 4 ** 85 ** ADC12, PCINT20
	_BV(3)	,	// PK 3 ** 86 ** ADC11, PCINT19
	_BV(2)	,	// PK 2 ** 87 ** ADC10, PCINT18
	_BV(1)	,	// PK 1 ** 88 ** ADC9, PCINT17
	_BV(0)	,	// PK 0 ** 89 ** ADC8, PCINT16
	_BV(7)	,	// PF 7 ** 90 ** ADC7
	_BV(6)	,	// PF 6 ** 91 ** ADC6
	_BV(5)	,	// PF 5 ** 92 ** ADC5
	_BV(4)	,	// PF 4 ** 93 ** ADC4
	_BV(3)	,	// PF 3 ** 94 ** ADC3
	_BV(2)	,	// PF 2 ** 95 ** ADC2
	_BV(1)	,	// PF 1 ** 96 ** ADC1
	_BV(0)	,	// PF 0 ** 97 ** ADC0
	NOT_USED,	//		** 98 ** AREF
	NOT_USED,	//		** 99 ** GND
	NOT_USED,	//		** 100 ** AVCC
};