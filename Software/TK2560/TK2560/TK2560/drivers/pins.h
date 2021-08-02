// /*
//  * pins.h
//  *
//  * Created: 02/08/2021 08:31:36
//  *  Author: OBED
//  */ 
// 
// 
// #ifndef PINS_H_
// #define PINS_H_
// 
// 
// #include <avr/pgmspace.h>
// 
// /************************************************************************/
// /*                           OTHER DEFINITIONS                          */
// /************************************************************************/
// // Get the bit location within the hardware port of the given virtual pin.
// This comes from the pins.h file for the board configuration.
// // extern const uint16_t PROGMEM port_to_ddr_PGM[];
// // extern const uint16_t PROGMEM port_to_input_PGM[];
// // extern const uint16_t PROGMEM port_to_output_PGM[];
// // 
// // extern const uint8_t PROGMEM pin_to_port_PGM[];
// // extern const uint8_t PROGMEM pin_to_bit_mask_PGM[];
// 
// 
// 
// 
// /************************************************************************/
// /* PIN REMAP FOR TK2560                                                 */
// /************************************************************************/
// 
// #define Pin_PE0		0 // PE 0 ** 0 ** USART0_RX
// #define Pin_PE1		1 // PE 1 ** 1 ** USART0_RX
// #define Pin_PE4		2 // PE 4 ** 2 ** PWM2
// #define Pin_PE5		3 // PE 5 ** 3 ** PWM3
// #define Pin_PG5		4 // PG 5 ** 4 ** PWM4
// #define Pin_PE3		5 // PE 3 ** 5 ** PWM5
// #define Pin_PH3		6 // PH 3 ** 6 ** PWM6
// #define Pin_PH4		7 // PH 4 ** 7 ** PWM7
// #define Pin_PH5		8 // PH 5 ** 8 ** PWM8
// #define Pin_PH6		9 // PH 6 ** 9 ** PWM9
// #define Pin_PB4		10 // PB 4 ** 10 ** PWM10
// #define Pin_PB5		11 // PB 5 ** 11 ** PWM11
// #define Pin_PB6		12 // PB 6 ** 12 ** PWM12
// #define Pin_PB7		13 // PB 7 ** 13 ** PWM13
// #define Pin_PJ1		14 // PJ 1 ** 14 ** USART3_TX
// #define Pin_PJ0		15 // PJ 0 ** 15 ** USART3_RX
// #define Pin_PH1		16 // PH 1 ** 16 ** USART2_TX
// #define Pin_PH0		17 // PH 0 ** 17 ** USART2_RX
// #define Pin_PD3		18 // PD 3 ** 18 ** USART1_TX
// #define Pin_PD2		19 // PD 2 ** 19 ** USART1_RX
// #define Pin_PD1		20 // PD 1 ** 20 ** I2C_SDA
// #define Pin_PD0		21 // PD 0 ** 21 ** I2C_SCL
// #define Pin_PA0		22 // PA 0 ** 22 ** D22
// #define Pin_PA1		23 // PA 1 ** 23 ** D23
// #define Pin_PA2		24 // PA 2 ** 24 ** D24
// #define Pin_PA3		25 // PA 3 ** 25 ** D25
// #define Pin_PA4		26 // PA 4 ** 26 ** D26
// #define Pin_PA5		27 // PA 5 ** 27 ** D27
// #define Pin_PA6		28 // PA 6 ** 28 ** D28
// #define Pin_PA7		29 // PA 7 ** 29 ** D29
// #define Pin_PC7		30 // PC 7 ** 30 ** D30
// #define Pin_PC6		31 // PC 6 ** 31 ** D31
// #define Pin_PC5		32 // PC 5 ** 32 ** D32
// #define Pin_PC4		33 // PC 4 ** 33 ** D33
// #define Pin_PC3		34 // PC 3 ** 34 ** D34
// #define Pin_PC2		35 // PC 2 ** 35 ** D35
// #define Pin_PC1		36 // PC 1 ** 36 ** D36
// #define Pin_PC0		37 // PC 0 ** 37 ** D37
// #define Pin_PD7		38 // PD 7 ** 38 ** D38
// #define Pin_PG2		39 // PG 2 ** 39 ** D39
// #define Pin_PG1		40 // PG 1 ** 40 ** D40
// #define Pin_PG0		41 // PG 0 ** 41 ** D41
// #define Pin_PL7		42 // PL 7 ** 42 ** D42
// #define Pin_PL6		43 // PL 6 ** 43 ** D43
// #define Pin_PL5		44 // PL 5 ** 44 ** D44
// #define Pin_PL4		45 // PL 4 ** 45 ** D45
// #define Pin_PL3		46 // PL 3 ** 46 ** D46
// #define Pin_PL2		47 // PL 2 ** 47 ** D47
// #define Pin_PL1		48 // PL 1 ** 48 ** D48
// #define Pin_PL0		49 // PL 0 ** 49 ** D49
// #define Pin_PB3		50 // PB 3 ** 50 ** SPI_MISO
// #define Pin_PB2		51 // PB 2 ** 51 ** SPI_MOSI
// #define Pin_PB1		52 // PB 1 ** 52 ** SPI_SCK
// #define Pin_PB0		53 // PB 0 ** 53 ** SPI_SS
// #define Pin_PF0		54 // PF 0 ** 54 ** A0
// #define Pin_PF1		55 // PF 1 ** 55 ** A1
// #define Pin_PF2		56 // PF 2 ** 56 ** A2
// #define Pin_PF3		57 // PF 3 ** 57 ** A3
// #define Pin_PF4		58 // PF 4 ** 58 ** A4
// #define Pin_PF5		59 // PF 5 ** 59 ** A5
// #define Pin_PF6		60 // PF 6 ** 60 ** A6
// #define Pin_PF7		61 // PF 7 ** 61 ** A7
// #define Pin_PK0		62 // PK 0 ** 62 ** A8
// #define Pin_PK1		63 // PK 1 ** 63 ** A9
// #define Pin_PK2		64 // PK 2 ** 64 ** A10
// #define Pin_PK3		65 // PK 3 ** 65 ** A11
// #define Pin_PK4		66 // PK 4 ** 66 ** A12
// #define Pin_PK5		67 // PK 5 ** 67 ** A13
// #define Pin_PK6		68 // PK 6 ** 68 ** A14
// #define Pin_PK7		69 // PK 7 ** 69 ** A15
// 
// //SPI Pins definition
// #define PIN_SPI_SS    Pin_PB0
// #define PIN_SPI_MOSI  Pin_PB2
// #define PIN_SPI_MISO  Pin_PB3
// #define PIN_SPI_SCK   Pin_PB1
// 
// static const uint8_t SS   = PIN_SPI_SS;
// static const uint8_t MOSI = PIN_SPI_MOSI;
// static const uint8_t MISO = PIN_SPI_MISO;
// static const uint8_t SCK  = PIN_SPI_SCK;
// 
// const PROGMEM uint16_t  port_to_ddr_PGM[] = {
// 	NOT_A_PORT,
// 	(uint16_t) &DDRA,
// 	(uint16_t) &DDRB,
// 	(uint16_t) &DDRC,
// 	(uint16_t) &DDRD,
// 	(uint16_t) &DDRE,
// 	(uint16_t) &DDRF,
// 	(uint16_t) &DDRG,
// 	(uint16_t) &DDRH,
// 	NOT_A_PORT,
// 	(uint16_t) &DDRJ,
// 	(uint16_t) &DDRK,
// 	(uint16_t) &DDRL,
// };
// const PROGMEM uint16_t  port_to_output_PGM[] = {
// 	NOT_A_PORT,
// 	(uint16_t) &PORTA,
// 	(uint16_t) &PORTB,
// 	(uint16_t) &PORTC,
// 	(uint16_t) &PORTD,
// 	(uint16_t) &PORTE,
// 	(uint16_t) &PORTF,
// 	(uint16_t) &PORTG,
// 	(uint16_t) &PORTH,
// 	NOT_A_PORT,
// 	(uint16_t) &PORTJ,
// 	(uint16_t) &PORTK,
// 	(uint16_t) &PORTL,
// };
// 
// const PROGMEM uint16_t  port_to_input_PGM[] = {
// 	NOT_A_PIN,
// 	(uint16_t) &PINA,
// 	(uint16_t) &PINB,
// 	(uint16_t) &PINC,
// 	(uint16_t) &PIND,
// 	(uint16_t) &PINE,
// 	(uint16_t) &PINF,
// 	(uint16_t) &PING,
// 	(uint16_t) &PINH,
// 	NOT_A_PIN,
// 	(uint16_t) &PINJ,
// 	(uint16_t) &PINK,
// 	(uint16_t) &PINL,
// };
// const PROGMEM uint8_t  pin_to_port_PGM[] = {
// 	// PORTLIST
// 	// -------------------------------------------
// 	PE	, // PE 0 ** 0 ** USART0_RX
// 	PE	, // PE 1 ** 1 ** USART0_TX
// 	PE	, // PE 4 ** 2 ** PWM2
// 	PE	, // PE 5 ** 3 ** PWM3
// 	PG	, // PG 5 ** 4 ** PWM4
// 	PE	, // PE 3 ** 5 ** PWM5
// 	PH	, // PH 3 ** 6 ** PWM6
// 	PH	, // PH 4 ** 7 ** PWM7
// 	PH	, // PH 5 ** 8 ** PWM8
// 	PH	, // PH 6 ** 9 ** PWM9
// 	PB	, // PB 4 ** 10 ** PWM10
// 	PB	, // PB 5 ** 11 ** PWM11
// 	PB	, // PB 6 ** 12 ** PWM12
// 	PB	, // PB 7 ** 13 ** PWM13
// 	PJ	, // PJ 1 ** 14 ** USART3_TX
// 	PJ	, // PJ 0 ** 15 ** USART3_RX
// 	PH	, // PH 1 ** 16 ** USART2_TX
// 	PH	, // PH 0 ** 17 ** USART2_RX
// 	PD	, // PD 3 ** 18 ** USART1_TX
// 	PD	, // PD 2 ** 19 ** USART1_RX
// 	PD	, // PD 1 ** 20 ** I2C_SDA
// 	PD	, // PD 0 ** 21 ** I2C_SCL
// 	PA	, // PA 0 ** 22 ** D22
// 	PA	, // PA 1 ** 23 ** D23
// 	PA	, // PA 2 ** 24 ** D24
// 	PA	, // PA 3 ** 25 ** D25
// 	PA	, // PA 4 ** 26 ** D26
// 	PA	, // PA 5 ** 27 ** D27
// 	PA	, // PA 6 ** 28 ** D28
// 	PA	, // PA 7 ** 29 ** D29
// 	PC	, // PC 7 ** 30 ** D30
// 	PC	, // PC 6 ** 31 ** D31
// 	PC	, // PC 5 ** 32 ** D32
// 	PC	, // PC 4 ** 33 ** D33
// 	PC	, // PC 3 ** 34 ** D34
// 	PC	, // PC 2 ** 35 ** D35
// 	PC	, // PC 1 ** 36 ** D36
// 	PC	, // PC 0 ** 37 ** D37
// 	PD	, // PD 7 ** 38 ** D38
// 	PG	, // PG 2 ** 39 ** D39
// 	PG	, // PG 1 ** 40 ** D40
// 	PG	, // PG 0 ** 41 ** D41
// 	PL	, // PL 7 ** 42 ** D42
// 	PL	, // PL 6 ** 43 ** D43
// 	PL	, // PL 5 ** 44 ** D44
// 	PL	, // PL 4 ** 45 ** D45
// 	PL	, // PL 3 ** 46 ** D46
// 	PL	, // PL 2 ** 47 ** D47
// 	PL	, // PL 1 ** 48 ** D48
// 	PL	, // PL 0 ** 49 ** D49
// 	PB	, // PB 3 ** 50 ** SPI_MISO
// 	PB	, // PB 2 ** 51 ** SPI_MOSI
// 	PB	, // PB 1 ** 52 ** SPI_SCK
// 	PB	, // PB 0 ** 53 ** SPI_SS
// 	PF	, // PF 0 ** 54 ** A0
// 	PF	, // PF 1 ** 55 ** A1
// 	PF	, // PF 2 ** 56 ** A2
// 	PF	, // PF 3 ** 57 ** A3
// 	PF	, // PF 4 ** 58 ** A4
// 	PF	, // PF 5 ** 59 ** A5
// 	PF	, // PF 6 ** 60 ** A6
// 	PF	, // PF 7 ** 61 ** A7
// 	PK	, // PK 0 ** 62 ** A8
// 	PK	, // PK 1 ** 63 ** A9
// 	PK	, // PK 2 ** 64 ** A10
// 	PK	, // PK 3 ** 65 ** A11
// 	PK	, // PK 4 ** 66 ** A12
// 	PK	, // PK 5 ** 67 ** A13
// 	PK	, // PK 6 ** 68 ** A14
// 	PK	, // PK 7 ** 69 ** A15
// };
// const PROGMEM uint8_t  pin_to_bit_mask_PGM[] = {
// 	// PIN IN PORT
// 	// -------------------------------------------
// 	_BV( 0 )	, // PE 0 ** 0 ** USART0_RX
// 	_BV( 1 )	, // PE 1 ** 1 ** USART0_TX
// 	_BV( 4 )	, // PE 4 ** 2 ** PWM2
// 	_BV( 5 )	, // PE 5 ** 3 ** PWM3
// 	_BV( 5 )	, // PG 5 ** 4 ** PWM4
// 	_BV( 3 )	, // PE 3 ** 5 ** PWM5
// 	_BV( 3 )	, // PH 3 ** 6 ** PWM6
// 	_BV( 4 )	, // PH 4 ** 7 ** PWM7
// 	_BV( 5 )	, // PH 5 ** 8 ** PWM8
// 	_BV( 6 )	, // PH 6 ** 9 ** PWM9
// 	_BV( 4 )	, // PB 4 ** 10 ** PWM10
// 	_BV( 5 )	, // PB 5 ** 11 ** PWM11
// 	_BV( 6 )	, // PB 6 ** 12 ** PWM12
// 	_BV( 7 )	, // PB 7 ** 13 ** PWM13
// 	_BV( 1 )	, // PJ 1 ** 14 ** USART3_TX
// 	_BV( 0 )	, // PJ 0 ** 15 ** USART3_RX
// 	_BV( 1 )	, // PH 1 ** 16 ** USART2_TX
// 	_BV( 0 )	, // PH 0 ** 17 ** USART2_RX
// 	_BV( 3 )	, // PD 3 ** 18 ** USART1_TX
// 	_BV( 2 )	, // PD 2 ** 19 ** USART1_RX
// 	_BV( 1 )	, // PD 1 ** 20 ** I2C_SDA
// 	_BV( 0 )	, // PD 0 ** 21 ** I2C_SCL
// 	_BV( 0 )	, // PA 0 ** 22 ** D22
// 	_BV( 1 )	, // PA 1 ** 23 ** D23
// 	_BV( 2 )	, // PA 2 ** 24 ** D24
// 	_BV( 3 )	, // PA 3 ** 25 ** D25
// 	_BV( 4 )	, // PA 4 ** 26 ** D26
// 	_BV( 5 )	, // PA 5 ** 27 ** D27
// 	_BV( 6 )	, // PA 6 ** 28 ** D28
// 	_BV( 7 )	, // PA 7 ** 29 ** D29
// 	_BV( 7 )	, // PC 7 ** 30 ** D30
// 	_BV( 6 )	, // PC 6 ** 31 ** D31
// 	_BV( 5 )	, // PC 5 ** 32 ** D32
// 	_BV( 4 )	, // PC 4 ** 33 ** D33
// 	_BV( 3 )	, // PC 3 ** 34 ** D34
// 	_BV( 2 )	, // PC 2 ** 35 ** D35
// 	_BV( 1 )	, // PC 1 ** 36 ** D36
// 	_BV( 0 )	, // PC 0 ** 37 ** D37
// 	_BV( 7 )	, // PD 7 ** 38 ** D38
// 	_BV( 2 )	, // PG 2 ** 39 ** D39
// 	_BV( 1 )	, // PG 1 ** 40 ** D40
// 	_BV( 0 )	, // PG 0 ** 41 ** D41
// 	_BV( 7 )	, // PL 7 ** 42 ** D42
// 	_BV( 6 )	, // PL 6 ** 43 ** D43
// 	_BV( 5 )	, // PL 5 ** 44 ** D44
// 	_BV( 4 )	, // PL 4 ** 45 ** D45
// 	_BV( 3 )	, // PL 3 ** 46 ** D46
// 	_BV( 2 )	, // PL 2 ** 47 ** D47
// 	_BV( 1 )	, // PL 1 ** 48 ** D48
// 	_BV( 0 )	, // PL 0 ** 49 ** D49
// 	_BV( 3 )	, // PB 3 ** 50 ** SPI_MISO
// 	_BV( 2 )	, // PB 2 ** 51 ** SPI_MOSI
// 	_BV( 1 )	, // PB 1 ** 52 ** SPI_SCK
// 	_BV( 0 )	, // PB 0 ** 53 ** SPI_SS
// 	_BV( 0 )	, // PF 0 ** 54 ** A0
// 	_BV( 1 )	, // PF 1 ** 55 ** A1
// 	_BV( 2 )	, // PF 2 ** 56 ** A2
// 	_BV( 3 )	, // PF 3 ** 57 ** A3
// 	_BV( 4 )	, // PF 4 ** 58 ** A4
// 	_BV( 5 )	, // PF 5 ** 59 ** A5
// 	_BV( 6 )	, // PF 6 ** 60 ** A6
// 	_BV( 7 )	, // PF 7 ** 61 ** A7
// 	_BV( 0 )	, // PK 0 ** 62 ** A8
// 	_BV( 1 )	, // PK 1 ** 63 ** A9
// 	_BV( 2 )	, // PK 2 ** 64 ** A10
// 	_BV( 3 )	, // PK 3 ** 65 ** A11
// 	_BV( 4 )	, // PK 4 ** 66 ** A12
// 	_BV( 5 )	, // PK 5 ** 67 ** A13
// 	_BV( 6 )	, // PK 6 ** 68 ** A14
// 	_BV( 7 )	, // PK 7 ** 69 ** A15
// };// These perform slightly better as macros compared to inline functions
// #define pinToPort(P) ( pgm_read_byte( pin_to_port_PGM + (P) ) )
// #define pinToBitMask(P) ( pgm_read_byte( pin_to_bit_mask_PGM + (P) ) )
// //#define pinToTimer(P) ( pgm_read_byte( digital_pin_to_timer_PGM + (P) ) )
// #define portOutputRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_output_PGM + (P))) )
// #define portInputRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_input_PGM + (P))) )
// #define portDDRRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_ddr_PGM + (P))) )
// 
// //USART pins
// //I2C Pins
// //PWM pins
// #endif /* PINS_H_ */