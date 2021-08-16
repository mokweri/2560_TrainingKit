/*
 * interrupts.c
 *
 * Created: 8/16/2021 20:06:51
 *  Author: Obed
 */ 
#include "tk2560.h"


void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode)
{
	if(interruptNum < EXTERNAL_NUM_INTERRUPTS)
	{
		//configure interrupt mode: CHANGE,RISING,FALING
		//Enable the interrupt
		switch(interruptNum)
		{
			case 0:
			
				
			break;
		}
		
	}
	
	
}