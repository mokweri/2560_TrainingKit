/*
 * timer0.c
 *
 * Created: 30/07/2021 11:54:55
 *  Author: OBED
 */ 
/*
-----File Inclusions----------
*/
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "timer0.h"

void timer0_mode_set(timer_mode_t timer_mode)
{
	switch (timer_mode)
	{
		case TIMER0_NORMAL_MODE:
		TCCR0A &= ~((1<<WGM01)|(1<<WGM00));
		TCCR0B &= ~(1<<WGM02);
		break;
		
		case TIMER0_CTC_MODE:
		TCCR0A &= ~(1<<WGM00);
		TCCR0A |= (1<<WGM01);
		TCCR0B &= ~(1<<WGM02);
		break;
		
		case TIMER0_FAST_PWM_MODE:
		
		break;
		
	}
	
}