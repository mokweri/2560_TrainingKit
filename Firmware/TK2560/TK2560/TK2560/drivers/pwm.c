/*
 * pwm.c
 *
 * Created: 16/08/2021 14:38:15
 *  Author: OBED
 */ 
#include "tk2560.h"

/*
 timers 1 and 2 are used for phase-correct hardware PWM
 this is better for motors as it ensures an even waveform
 note, however, that fast PWM mode can achieve a frequency of up 8 MHz (with a 16 MHz clock) at 50% duty cycle
*/

void pwm_init(void)
{
	// Configure Timer1
	TCCR1B = 0;
	bitSet(TCCR1B, CS11); 
	bitSet(TCCR1B, CS10);	// set clk/64 prescaler
	bitSet(TCCR1A, WGM10);	// PWM, Phase Correct, 8-bit
	
	// Configure Timer2
	bitSet(TCCR2B, CS22);	// clk/64 prescaler
	bitSet(TCCR2A, WGM20);	// PWM, Phase Correct
	
	// Configure Timer3
	bitSet(TCCR3B, CS31);	
	bitSet(TCCR3B, CS30);	// clk/64 prescaler
	bitSet(TCCR3A, WGM30);	// PWM, Phase Correct
	
	// Configure Timer4
	bitSet(TCCR4B, CS41);	
	bitSet(TCCR4B, CS40);	// clk/64 prescaler
	bitSet(TCCR4A, WGM40);	// PWM, Phase Correct
	
	// Configure Timer5
	bitSet(TCCR5B, CS51);
	bitSet(TCCR5B, CS50);	// clk/64 prescaler
	bitSet(TCCR5A, WGM50);	// PWM, Phase Correct
	 
}

// PWM output
void analogWrite(uint8_t pin, int val)
{
	
	pinMode(pin, OUTPUT);
	if (val == 0)
	{
		digitalWrite(pin, LOW);
	}
	else if (val == 255)
	{
		digitalWrite(pin, HIGH);
	}
	else{
		switch(pinToTimer(pin))
		{
			//Timer 0
			case TIMER0A:
				//connect pwm to pin on timer 0, channel A
				bitSet(TCCR0A, COM0A1); //clear OC0A on compare match
				OCR0A = val; //set pwm duty
			break;
			
			case TIMER0B:
				//connect pwm to pin on timer 0, channel B
				bitSet(TCCR0B, COM0B1); //clear OC0A on compare match
				OCR0B = val; //set pwm duty
			break;
			
			//Timer 1
			case TIMER1A:
				// connect pwm to pin on timer 1, channel A
				bitSet(TCCR1A, COM1A1);
				OCR1A = val; // set pwm duty
			break;
			case TIMER1B:
				// connect pwm to pin on timer 1, channel B
				bitSet(TCCR1A, COM1B1);
				OCR1B = val; // set pwm duty
			break;
			case TIMER1C:
				// connect pwm to pin on timer 1, channel C
				bitSet(TCCR1A, COM1C1);
				OCR1C = val; // set pwm duty
			break;
			
			//Timer 2
			case TIMER2A:
				// connect pwm to pin on timer 2, channel A
				bitSet(TCCR2A, COM2A1);
				OCR2A = val; // set pwm duty
			break;
			case TIMER2B:
				// connect pwm to pin on timer 2, channel B
				bitSet(TCCR2A, COM2B1);
				OCR2B = val; // set pwm duty
			break;
			
			//Timer 3
			case TIMER3A:
				// connect pwm to pin on timer 3, channel A
				bitSet(TCCR3A, COM3A1);
				OCR3A = val; // set pwm duty
			break;
			case TIMER3B:
				// connect pwm to pin on timer 3, channel B
				bitSet(TCCR3A, COM3B1);
				OCR3B = val; // set pwm duty
			break;
			case TIMER3C:
				// connect pwm to pin on timer 3, channel C
				bitSet(TCCR3A, COM3C1);
				OCR3C = val; // set pwm duty
			break;
			
			//Timer 4
			case TIMER4A:
				//connect pwm to pin on timer 4, channel A
				bitSet(TCCR4A, COM4A1);
				OCR4A = val;	// set pwm duty
			break;
			case TIMER4B:
				// connect pwm to pin on timer 4, channel B
				bitSet(TCCR4A, COM4B1);
				OCR4B = val; // set pwm duty
			break;
			case TIMER4C:
				// connect pwm to pin on timer 4, channel C
				bitSet(TCCR4A, COM4C1);
				OCR4C = val; // set pwm duty
			break;
			//timer 5
			case TIMER5A:
				// connect pwm to pin on timer 5, channel A
				bitSet(TCCR5A, COM5A1);
				OCR5A = val; // set pwm duty
			break;
			case TIMER5B:
				// connect pwm to pin on timer 5, channel B
				bitSet(TCCR5A, COM5B1);
				OCR5B = val; // set pwm duty
			break;
			case TIMER5C:
				// connect pwm to pin on timer 5, channel C
				bitSet(TCCR5A, COM5C1);
				OCR5C = val; // set pwm duty
			break;
			case NOT_ON_TIMER:
			
			default:
				if (val < 128) {
					digitalWrite(pin, LOW);
				} else {
					digitalWrite(pin, HIGH);
				}
		}
	}
}