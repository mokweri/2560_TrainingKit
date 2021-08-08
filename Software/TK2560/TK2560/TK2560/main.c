/*
 * TK2560.c
 *
 * Created: 02/08/2021 08:12:34
 * Author : OBED
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "drivers/tk2560.h"



int main(void)
{
    /* Replace with your application code */
	pinMode(Pin_PK0, OUTPUT);
	pinMode(Pin_PJ2, INPUT);
	
    while (1) 
    {
		if (digitalRead(Pin_PJ2))
		{
			_delay_ms(70);
			togglePin(Pin_PK0);
		}
		
		
    }
}

