/*
 * pins.h
 *
 * Created: 02/08/2021 08:31:36
 *  Author: OBED
 */ 


#ifndef PINS_H_
#define PINS_H_

#include "pin_remap.h"

#include <avr/io.h>
#include <avr/pgmspace.h>

//SPI Pins definition
#define PIN_SPI_SS    PB0
#define PIN_SPI_MOSI  PB2
#define PIN_SPI_MISO  PB3
#define PIN_SPI_SCK   PB1

static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

const uint16_t PROGMEM port_to_ddr_PGM[] = {
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

const uint16_t PROGMEM port_to_output_PGM[] = {
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

const uint16_t PROGMEM port_to_input_PGM[] = {
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
	(uint16_t) &PINL,
};

const uint8_t PROGMEM pin_to_port_PGM[] = {
	// PORTLIST
	// -------------------------------------------
	PE	, // PE 0 ** 0 ** USART0_RX
	PE	, // PE 1 ** 1 ** USART0_TX
	PE	, // PE 4 ** 2 ** PWM2
	PE	, // PE 5 ** 3 ** PWM3
	PG	, // PG 5 ** 4 ** PWM4
	PE	, // PE 3 ** 5 ** PWM5
	PH	, // PH 3 ** 6 ** PWM6
	PH	, // PH 4 ** 7 ** PWM7
	PH	, // PH 5 ** 8 ** PWM8
	PH	, // PH 6 ** 9 ** PWM9
	PB	, // PB 4 ** 10 ** PWM10
	PB	, // PB 5 ** 11 ** PWM11
	PB	, // PB 6 ** 12 ** PWM12
	PB	, // PB 7 ** 13 ** PWM13
	PJ	, // PJ 1 ** 14 ** USART3_TX
	PJ	, // PJ 0 ** 15 ** USART3_RX
	PH	, // PH 1 ** 16 ** USART2_TX
	PH	, // PH 0 ** 17 ** USART2_RX
	PD	, // PD 3 ** 18 ** USART1_TX
	PD	, // PD 2 ** 19 ** USART1_RX
	PD	, // PD 1 ** 20 ** I2C_SDA
	PD	, // PD 0 ** 21 ** I2C_SCL
	PA	, // PA 0 ** 22 ** D22
	PA	, // PA 1 ** 23 ** D23
	PA	, // PA 2 ** 24 ** D24
	PA	, // PA 3 ** 25 ** D25
	PA	, // PA 4 ** 26 ** D26
	PA	, // PA 5 ** 27 ** D27
	PA	, // PA 6 ** 28 ** D28
	PA	, // PA 7 ** 29 ** D29
	PC	, // PC 7 ** 30 ** D30
	PC	, // PC 6 ** 31 ** D31
	PC	, // PC 5 ** 32 ** D32
	PC	, // PC 4 ** 33 ** D33
	PC	, // PC 3 ** 34 ** D34
	PC	, // PC 2 ** 35 ** D35
	PC	, // PC 1 ** 36 ** D36
	PC	, // PC 0 ** 37 ** D37
	PD	, // PD 7 ** 38 ** D38
	PG	, // PG 2 ** 39 ** D39
	PG	, // PG 1 ** 40 ** D40
	PG	, // PG 0 ** 41 ** D41
	PL	, // PL 7 ** 42 ** D42
	PL	, // PL 6 ** 43 ** D43
	PL	, // PL 5 ** 44 ** D44
	PL	, // PL 4 ** 45 ** D45
	PL	, // PL 3 ** 46 ** D46
	PL	, // PL 2 ** 47 ** D47
	PL	, // PL 1 ** 48 ** D48
	PL	, // PL 0 ** 49 ** D49
	PB	, // PB 3 ** 50 ** SPI_MISO
	PB	, // PB 2 ** 51 ** SPI_MOSI
	PB	, // PB 1 ** 52 ** SPI_SCK
	PB	, // PB 0 ** 53 ** SPI_SS
	PF	, // PF 0 ** 54 ** A0
	PF	, // PF 1 ** 55 ** A1
	PF	, // PF 2 ** 56 ** A2
	PF	, // PF 3 ** 57 ** A3
	PF	, // PF 4 ** 58 ** A4
	PF	, // PF 5 ** 59 ** A5
	PF	, // PF 6 ** 60 ** A6
	PF	, // PF 7 ** 61 ** A7
	PK	, // PK 0 ** 62 ** A8
	PK	, // PK 1 ** 63 ** A9
	PK	, // PK 2 ** 64 ** A10
	PK	, // PK 3 ** 65 ** A11
	PK	, // PK 4 ** 66 ** A12
	PK	, // PK 5 ** 67 ** A13
	PK	, // PK 6 ** 68 ** A14
	PK	, // PK 7 ** 69 ** A15
};

const uint8_t PROGMEM pin_to_bit_mask_PGM[] = {
	// PIN IN PORT
	// -------------------------------------------
	_BV( 0 )	, // PE 0 ** 0 ** USART0_RX
	_BV( 1 )	, // PE 1 ** 1 ** USART0_TX
	_BV( 4 )	, // PE 4 ** 2 ** PWM2
	_BV( 5 )	, // PE 5 ** 3 ** PWM3
	_BV( 5 )	, // PG 5 ** 4 ** PWM4
	_BV( 3 )	, // PE 3 ** 5 ** PWM5
	_BV( 3 )	, // PH 3 ** 6 ** PWM6
	_BV( 4 )	, // PH 4 ** 7 ** PWM7
	_BV( 5 )	, // PH 5 ** 8 ** PWM8
	_BV( 6 )	, // PH 6 ** 9 ** PWM9
	_BV( 4 )	, // PB 4 ** 10 ** PWM10
	_BV( 5 )	, // PB 5 ** 11 ** PWM11
	_BV( 6 )	, // PB 6 ** 12 ** PWM12
	_BV( 7 )	, // PB 7 ** 13 ** PWM13
	_BV( 1 )	, // PJ 1 ** 14 ** USART3_TX
	_BV( 0 )	, // PJ 0 ** 15 ** USART3_RX
	_BV( 1 )	, // PH 1 ** 16 ** USART2_TX
	_BV( 0 )	, // PH 0 ** 17 ** USART2_RX
	_BV( 3 )	, // PD 3 ** 18 ** USART1_TX
	_BV( 2 )	, // PD 2 ** 19 ** USART1_RX
	_BV( 1 )	, // PD 1 ** 20 ** I2C_SDA
	_BV( 0 )	, // PD 0 ** 21 ** I2C_SCL
	_BV( 0 )	, // PA 0 ** 22 ** D22
	_BV( 1 )	, // PA 1 ** 23 ** D23
	_BV( 2 )	, // PA 2 ** 24 ** D24
	_BV( 3 )	, // PA 3 ** 25 ** D25
	_BV( 4 )	, // PA 4 ** 26 ** D26
	_BV( 5 )	, // PA 5 ** 27 ** D27
	_BV( 6 )	, // PA 6 ** 28 ** D28
	_BV( 7 )	, // PA 7 ** 29 ** D29
	_BV( 7 )	, // PC 7 ** 30 ** D30
	_BV( 6 )	, // PC 6 ** 31 ** D31
	_BV( 5 )	, // PC 5 ** 32 ** D32
	_BV( 4 )	, // PC 4 ** 33 ** D33
	_BV( 3 )	, // PC 3 ** 34 ** D34
	_BV( 2 )	, // PC 2 ** 35 ** D35
	_BV( 1 )	, // PC 1 ** 36 ** D36
	_BV( 0 )	, // PC 0 ** 37 ** D37
	_BV( 7 )	, // PD 7 ** 38 ** D38
	_BV( 2 )	, // PG 2 ** 39 ** D39
	_BV( 1 )	, // PG 1 ** 40 ** D40
	_BV( 0 )	, // PG 0 ** 41 ** D41
	_BV( 7 )	, // PL 7 ** 42 ** D42
	_BV( 6 )	, // PL 6 ** 43 ** D43
	_BV( 5 )	, // PL 5 ** 44 ** D44
	_BV( 4 )	, // PL 4 ** 45 ** D45
	_BV( 3 )	, // PL 3 ** 46 ** D46
	_BV( 2 )	, // PL 2 ** 47 ** D47
	_BV( 1 )	, // PL 1 ** 48 ** D48
	_BV( 0 )	, // PL 0 ** 49 ** D49
	_BV( 3 )	, // PB 3 ** 50 ** SPI_MISO
	_BV( 2 )	, // PB 2 ** 51 ** SPI_MOSI
	_BV( 1 )	, // PB 1 ** 52 ** SPI_SCK
	_BV( 0 )	, // PB 0 ** 53 ** SPI_SS
	_BV( 0 )	, // PF 0 ** 54 ** A0
	_BV( 1 )	, // PF 1 ** 55 ** A1
	_BV( 2 )	, // PF 2 ** 56 ** A2
	_BV( 3 )	, // PF 3 ** 57 ** A3
	_BV( 4 )	, // PF 4 ** 58 ** A4
	_BV( 5 )	, // PF 5 ** 59 ** A5
	_BV( 6 )	, // PF 6 ** 60 ** A6
	_BV( 7 )	, // PF 7 ** 61 ** A7
	_BV( 0 )	, // PK 0 ** 62 ** A8
	_BV( 1 )	, // PK 1 ** 63 ** A9
	_BV( 2 )	, // PK 2 ** 64 ** A10
	_BV( 3 )	, // PK 3 ** 65 ** A11
	_BV( 4 )	, // PK 4 ** 66 ** A12
	_BV( 5 )	, // PK 5 ** 67 ** A13
	_BV( 6 )	, // PK 6 ** 68 ** A14
	_BV( 7 )	, // PK 7 ** 69 ** A15
};

//USART pins


//I2C Pins

//PWM pins



#endif /* PINS_H_ */