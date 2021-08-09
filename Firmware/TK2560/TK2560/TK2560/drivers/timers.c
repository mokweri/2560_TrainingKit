/*
 * timers.c
 *
 * Created: 09/08/2021 11:26:26
 *  Author: OBED
 */ 
#define F_CPU 1000000UL
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "tk2560.h"

//Timer0
volatile long timer0_toggle_count;
volatile uint8_t *timer0_pin_port;
volatile uint8_t timer0_pin_mask;
//TIMSK1
volatile long timer1_toggle_count;
volatile uint8_t *timer1_pin_port;
volatile uint8_t timer1_pin_mask;
//TIMSK3
volatile long timer2_toggle_count;
volatile uint8_t *timer2_pin_port;
volatile uint8_t timer2_pin_mask;

#if defined(TIMSK3)
volatile long timer3_toggle_count;
volatile uint8_t *timer3_pin_port;
volatile uint8_t timer3_pin_mask;
#endif

#if defined(TIMSK4)
volatile long timer4_toggle_count;
volatile uint8_t *timer4_pin_port;
volatile uint8_t timer4_pin_mask;
#endif

#if defined(TIMSK5)
volatile long timer5_toggle_count;
volatile uint8_t *timer5_pin_port;
volatile uint8_t timer5_pin_mask;
#endif


//For __AVR_ATmega2560
#define AVAILABLE_TONE_PINS 1
#define USE_TIMER3

const uint8_t PROGMEM tone_pin_to_timer_PGM[] = { 3 /*, 2, 4, 5, 1, 0 */ };
static uint8_t tone_pins[AVAILABLE_TONE_PINS] = { 255 /*, 255, 255, 255, 255, 255 */ };


//Generates a square wave of the specified frequency (and 50% duty cycle) on a pin
//INITIALIZATION	
static int8_t toneBegin(uint8_t _pin)
{
	int8_t _timer = -1;
	
	// if we're already using the pin, the timer should be configured.
	for (int i = 0; i < AVAILABLE_TONE_PINS; i++) {
		if (tone_pins[i] == _pin) {
			return pgm_read_byte(tone_pin_to_timer_PGM + i);
		}
	}
	  
	// search for an unused timer.
	for (int i = 0; i < AVAILABLE_TONE_PINS; i++) {
		if (tone_pins[i] == 255) {
			tone_pins[i] = _pin;
			_timer = pgm_read_byte(tone_pin_to_timer_PGM + i);
			break;
		}
	}
	
	//Found timer
	if (_timer != -1)
	{
		// Set timer specific stuff
		// All timers in CTC mode
		// 8 bit timers will require changing prescalar values,
		// whereas 16 bit timers are set to either clk/1 or clk/64 prescalar
		switch(_timer)
		{
			//TIMER 0 - 8 bit timer
			case 0:
				TCCR0A = 0;
				TCCR0B = 0;
				bitWrite(TCCR0A, WGM01, 1); // set CTC mode
				bitWrite(TCCR0B, CS00, 1);  // No prescaling
				timer0_pin_port = portOutputRegister(pinToPort(_pin));
				timer0_pin_mask = pinToBitMask(_pin);
			break;			
			//TIMER 1 - 16 bit timer
			case 1:
				TCCR1A = 0;
				TCCR1B = 0;
				bitWrite(TCCR1B, WGM12, 1); // Set CTC mode
				bitWrite(TCCR1B, CS10, 1) ; // No prescaling
				timer1_pin_port = portOutputRegister(pinToPort(_pin));
				timer1_pin_mask = pinToBitMask(_pin);
			break;			
			//TIMER 2 - 8 bit timer
			case 2:
				TCCR2A = 0;
				TCCR2B = 0;
				bitWrite(TCCR2A, WGM21, 1); //Set CTC mode
				bitWrite(TCCR2B, CS20, 1); // No prescaling
				timer2_pin_port = portOutputRegister(pinToPort(_pin));
				timer2_pin_mask = pinToBitMask(_pin);
			break;			
			//TIMER 3 - 16 bit timer
			case 3:
				TCCR3A = 0;
				TCCR3B = 0;
				bitWrite(TCCR3B, WGM32, 1); //CTC Mode
				bitWrite(TCCR3B, CS30, 1);	//No prescaling
				timer3_pin_port = portOutputRegister(pinToPort(_pin));
				timer3_pin_mask = pinToBitMask(_pin);
			break;		
			//TIMER 4 - 16 bit timer
			case 4:
				TCCR4A = 0;
				TCCR4B = 0;
				bitWrite(TCCR4B, WGM42, 1); //CTC Mode
				bitWrite(TCCR4B, CS40, 1);  //No prescaling
				timer4_pin_port = portOutputRegister(pinToPort(_pin));
				timer4_pin_mask = pinToBitMask(_pin);
			break;	
			//TIMER 5 - 16 bit timer
			case 5:
				TCCR5A = 0;
				TCCR5B = 0;
				bitWrite(TCCR5B, WGM52, 1);
				bitWrite(TCCR5B, CS50, 1);
				timer5_pin_port = portOutputRegister(pinToPort(_pin));
				timer5_pin_mask = pinToBitMask(_pin);
			break;
		}
	}
	
	return _timer;	
}


//Generate frequency (in hertz) and duration (in milliseconds)
void tone(uint8_t _pin, unsigned int frequency, unsigned long duration)
{
	uint8_t prescalarbits = 0b001; // No Prescaling
	long toggle_count = 0;
	uint32_t ocr = 0;
	int8_t _timer;
	
	_timer = toneBegin(_pin);
	
	if (_timer >= 0)
	{
		//1. set the pin as OUTPUT
		pinMode(_pin, OUTPUT);
		
		//2. if we are using an 8 bit timer, scan through prescalers to find the best fit
		if (_timer == 0 || _timer == 2)
		{
			ocr = F_CPU / frequency / 2 - 1;
			prescalarbits = 0b001; // clk/1 prescaler (No prescaling) : For both timers
			
			if (ocr > 255) // above prescaler failed
			{
				ocr = (F_CPU / (frequency * 2 * 8)) - 1;
				prescalarbits = 0b010; // clk/8 prescaler : For both timers
				
				if (_timer == 2 && ocr > 255)
				{
					ocr = (F_CPU / frequency / 2 / 32) - 1;
					prescalarbits = 0b011; // clk/32
				}
					
				if(ocr > 255)
				{
					ocr = (F_CPU / (frequency * 2 * 64)) - 1;
					prescalarbits = _timer == 0 ? 0b011 : 0b100; // clk/32 for timer 1: clk/64 for timer 2
					
					if (_timer == 2 && ocr > 255)
					{
						ocr = (F_CPU / (frequency * 2 * 128)) - 1;
						prescalarbits = 0b101; //clk/128
					}

					if (ocr > 255)
					{
						ocr = (F_CPU / (frequency * 2 * 256))- 1;
						prescalarbits = _timer == 0 ? 0b100 : 0b110;  // clk/64 for timer 1: clk/256 for timer 2
						if (ocr > 255)
						{
							// can't do any better than /1024
							ocr = (F_CPU / (frequency * 2 * 1024)) - 1;
							prescalarbits = _timer == 0 ? 0b101 : 0b111; // clk/128 for timer 1: clk/1024 for timer 2
						}
					}				
				}
			}
				
			
			//2(b) Set the prescaler for 8 bit timers
			      //TIMER 0
			if (_timer == 0)
			{
				TCCR0B = (TCCR0B & 0b11111000) | prescalarbits;
			}
			else   //TIMER 2
			{
				TCCR2B = (TCCR2B & 0b11111000) | prescalarbits;
			}
			
		}else{
			//3. Prescaling for 16 bit timers
			// two choices for the 16 bit timers: clk/1 or clk/64
			ocr = (F_CPU / (frequency * 2)) - 1;
			
			prescalarbits = 0b001; //clk1
			if(ocr > 0xffff) //>65535
			{
				ocr = (F_CPU / (frequency * 2 * 64 ))- 1;
				prescalarbits = 0b011; //clk/64
			}
			
			//3(b) Set the prescaler for 16 bit timers
			if (_timer == 1)
			{
				TCCR1B = (TCCR1B & 0b11111000) | prescalarbits;
			}
			else if (_timer == 3)
			{
				TCCR3B = (TCCR3B & 0b11111000) | prescalarbits;
			}
			else if (_timer == 4)
			{
				TCCR4B = (TCCR4B & 0b11111000) | prescalarbits;
			}
			else if (_timer == 5)
			{
				TCCR5B = (TCCR5B & 0b11111000) | prescalarbits;
			}
		}
		
		//4. Calculate the toggle count
		if (duration > 0)
		{
			toggle_count = (2 * frequency * duration)/ 1000;
		}else{
			toggle_count = -1;
		}
		
		//5.Set the OCR for the given timer
		//Set the toggle count and then turn on the interrupts
		switch(_timer)
		{
			case 0:
				OCR0A = ocr;
				timer0_toggle_count = toggle_count;
				bitWrite(TIMSK0, OCIE0A, 1); //turn on interrupt
			break;
			
			case 1:
				OCR1A = ocr;
				timer1_toggle_count = toggle_count;
				bitWrite(TIMSK1, OCIE1A, 1);
			break;
			
			case 2:
				OCR2A = ocr;
				timer2_toggle_count = toggle_count;
				bitWrite(TIMSK2, OCIE2A, 1);
			break;
			
			case 3:
				OCR3A = ocr;
				timer3_toggle_count = toggle_count;
				bitWrite(TIMSK3, OCIE3A, 1);
			break;
			
			case 4:
				OCR4A = ocr;
				timer4_toggle_count = toggle_count;
				bitWrite(TIMSK4, OCIE4A, 1);
			break;
			
			case 5:
				OCR5A = ocr;
				timer5_toggle_count = toggle_count;
				bitWrite(TIMSK5, OCIE5A, 1);
			break;
		}		
	}
}


/* 
This function only works properly for timer 2 (the only one we use currently).  
for the others, it should end the tone, but won't restore proper PWM functionality for the timer. TODO
*/
void disableTimer(uint8_t _timer)
{
	switch(_timer)
	{
		case 0:
		TIMSK0 = 0;
		break;
		case 1:
			bitWrite(TIMSK1, OCIE1A, 0);
		break;
		case 2:
			bitWrite(TIMSK2, OCIE2A, 0); // disable interrupt
			TCCR2A = (1 << WGM20);		 // restore normal  PWM mode
			TCCR2B = (TCCR2B & 0b11111000) | (1 << CS22); //clk/64 prescaler
			OCR2A = 0;
		break;
		case 3:
			bitWrite(TIMSK3, OCIE3A, 0);
		break;
		case 4:
			bitWrite(TIMSK4, OCIE4A, 0);
		break;
		case 5:
			bitWrite(TIMSK5, OCIE5A, 0);
		break;
	}
}


void noTone(uint8_t _pin)
{
	int8_t _timer = -1;
	  
	for (int i = 0; i < AVAILABLE_TONE_PINS; i++)
	{
		if (tone_pins[i] == _pin) {
			_timer = pgm_read_byte(tone_pin_to_timer_PGM + i);
			tone_pins[i] = 255;
			break;
		}
	}
	  
	disableTimer(_timer);
	digitalWrite(_pin, 0);
}

/************************************************************************/
/*       Interrupt Service Routines (ISRs)                              */
/************************************************************************/
#ifdef USE_TIMER0
ISR(TIMER0_COMPA_vect)
{
	if (timer0_toggle_count != 0)
	{
		// toggle the pin
		*timer0_pin_port ^= timer0_pin_mask;

		if (timer0_toggle_count > 0)
			timer0_toggle_count--;
	}
	else
	{
		disableTimer(0);
		*timer0_pin_port &= ~(timer0_pin_mask);  // keep pin low after stop
	}
}
#endif

#ifdef USE_TIMER1
ISR(TIMER1_COMPA_vect)
{
	if (timer1_toggle_count != 0)
	{
		// toggle the pin
		*timer1_pin_port ^= timer1_pin_mask;

		if (timer1_toggle_count > 0)
			timer1_toggle_count--;
	}
	else
	{
		disableTimer(1);
		*timer1_pin_port &= ~(timer1_pin_mask);  // keep pin low after stop
	}
}
#endif

#ifdef USE_TIMER2
ISR(TIMER2_COMPA_vect)
{

	if (timer2_toggle_count != 0)
	{
		// toggle the pin
		*timer2_pin_port ^= timer2_pin_mask;

		if (timer2_toggle_count > 0)
			timer2_toggle_count--;
	}
	else
	{
		// need to call noTone() so that the tone_pins[] entry is reset, so the
		// timer gets initialized next time we call tone().
		// XXX: this assumes timer 2 is always the first one used.
		noTone(tone_pins[0]);
	}
}
#endif

#ifdef USE_TIMER3
ISR(TIMER3_COMPA_vect)
{
	if (timer3_toggle_count != 0)
	{
		// toggle the pin
		*timer3_pin_port ^= timer3_pin_mask;

		if (timer3_toggle_count > 0)
			timer3_toggle_count--;
	}
	else
	{
		disableTimer(3);
		*timer3_pin_port &= ~(timer3_pin_mask);  // keep pin low after stop
	}
}
#endif

#ifdef USE_TIMER4
ISR(TIMER4_COMPA_vect)
{
	if (timer4_toggle_count != 0)
	{
		// toggle the pin
		*timer4_pin_port ^= timer4_pin_mask;

		if (timer4_toggle_count > 0)
			timer4_toggle_count--;
	}
	else
	{
		disableTimer(4);
		*timer4_pin_port &= ~(timer4_pin_mask);  // keep pin low after stop
	}
}
#endif


#ifdef USE_TIMER5
ISR(TIMER5_COMPA_vect)
{
	if (timer5_toggle_count != 0)
	{
		// toggle the pin
		*timer5_pin_port ^= timer5_pin_mask;

		if (timer5_toggle_count > 0)
		{
			timer5_toggle_count--;
		}
			
	}
	else
	{
		disableTimer(5);
		*timer5_pin_port &= ~(timer5_pin_mask);  // keep pin low after stop
	}
}
#endif