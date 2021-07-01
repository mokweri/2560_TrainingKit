/*
 * pwm.h
 *
 * Created: 7/15/2019 10:36:27 AM
 *  Author: OBED
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>

// initialize timer2 in PWM mode
void pwm_Init(){
	
	TCNT2 = 0;
	TCCR2A |=(1<<WGM20)|(1<<WGM21)|(1<<COM2A1); //Fast PWM, Non-inverting mode, 
	TCCR2B |=(1<<CS20); //No prescalling
	
	
 	DDRB |=(1<<PB4); //OC2A pin (pin PB4 for atmega2560) as output pin
	DDRH |=(1<<PH6); //OC2B pin (pin PH6 for atmega2560) as output pin
	
}

void pwm_out(int x,int val){
	
	if(x==0)
	{
		OCR2A = val;
	}else if(x==1)
	{
		OCR2B = val;
	}
	
}



#endif /* PWM_H_ */