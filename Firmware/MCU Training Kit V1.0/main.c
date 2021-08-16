/*
 * MCU Training Kit V1.0
 * Created: April,2019
 * Author : OBED, EmbedSystems
 */ 

#define F_CPU 16000000UL

//Global variables
volatile unsigned long system_count = 0;
unsigned char keys= 0xFF;

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

//User-defined header files 
#include "BSP/lcd/LiquidCrystal.h"
#include "BSP/rtc/DS1307.h"
#include "BSP/shift_register/hc595.h"

#include "drivers/timer1.h"
#include "drivers/adc.h"
#include "drivers/pwm.h"

#include "keypad.h"
#include "LEDControl.h"
#include "tinudht.h"

void LCD_PrintInt(uint16_t n,uint8_t x,uint8_t y);

int main(void)
{
	/*---Initialization---------*/
	//LCDinit();		//LCD Functionality
	lcd_init();
	keypad_Init();	//KEYPAD Functionality
	LED_Init();		//LED Control
	timer1_Init();	//Timer1 Setup
	//ADC_init();		//Analog to Digital Conversion
	ClockInit();
	HC595Init();
	//pwm_Init();
	
// 	SetHour(7);
// 	SetMinute(26);
// 	SetAmPm(1);
	
	
	/*---------Button Setup-Pin Change Interrupt------------------*/
	cli();
	DDRJ = 0;
	PORTJ = 0xFF;
	PCICR |=(1<<PCIE1); //PinChange interrupt Enable 1
	PCIFR |=(1<<PCIF1); //Pin Change Interrupt Flag 1
	PCMSK1 |=(1<<PCINT11)|(1<<PCINT12)|(1<<PCINT13)|(1<<PCINT14); // Mask-pins 2,3,4,5 on Port J will interrupt
	sei();
	
	//LCDclr();
	lcd_clear();
	
	char time_string[11];	
	int8_t temperature = 0;
	int8_t humidity = 0;
	
	//buzzer
// 	DDRE |=(1<<PE3);
// 	PORTE |=(1<<PE3);
	
	//DHT11_Init();
// 	#define TINUDHT_PIN PE4
// 	_delay_ms(2000);
	
	DDRE |=(1<<7); //relay
	PORTE |=(1<<7);
	_delay_ms(2000);
	PORTE &=~(1<<7);

	
	while (1)
	{
				
		//uint16_t pot = ADC_read(0);
		//--------------------
		// pwm_out(0,pot/4);
		//-----------------------
		LCD_PrintString("MCU TRAINING KIT",0,0);
		GetTimeString(time_string);
		LCD_PrintString(time_string,2,1);
		
		//LCD_PrintString("       ",0,2);		
		//LCD_PrintInt(pot,0,2);
		
		Segment_Print(GetSecond()/10);


			
		/*---Keypad--------------*/
		read_keypad();
		
		
		//HC595Write(numbers[2],numbers[3]);
		
// 		TinuDHT tinudht;
// 		uint8_t tinudht_result = tinudht_read(&tinudht, TINUDHT_PIN);
// 		if (tinudht_result == TINUDHT_OK) {
// 			LCD_PrintInt(tinudht.humidity,8,1);
// 			LCD_PrintInt(tinudht.temperature,10,1);
// 			} else {
// 			LCD_PrintString("ERR  ",8,1);
// 		}
// 		_delay_ms(2000);
		
	}
}

ISR(PCINT1_vect){
		
	if (PINJ & 1<<PINJ2) {toggleLED(1); }
	if (PINJ & 1<<PINJ3) {toggleLED(2); }
	if (PINJ & 1<<PINJ4) {toggleLED(3); }
	//if (PINJ & 1<<PINJ5) {toggleLED(4); }
	
}

void LCD_PrintInt(uint16_t n,uint8_t x,uint8_t y){
	char buffer[10];
	itoa(n,buffer,10);
	LCD_PrintString(buffer,x,y);
}

