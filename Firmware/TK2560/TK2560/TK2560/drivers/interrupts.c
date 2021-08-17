/*
 * interrupts.c
 *
 * Created: 8/16/2021 20:06:51
 *  Author: Obed
 */ 
#include "tk2560.h"

typedef void (*voidFuncPtr)(void);

static void nothing(void) {
}

static volatile voidFuncPtr intFunc[EXTERNAL_NUM_INTERRUPTS] = {
#if EXTERNAL_NUM_INTERRUPTS > 8
//#warning There are more than 8 external interrupts. Some callbacks may not be initialized.
nothing,
#endif
#if EXTERNAL_NUM_INTERRUPTS > 7
nothing,
#endif
#if EXTERNAL_NUM_INTERRUPTS > 6
nothing,
#endif
#if EXTERNAL_NUM_INTERRUPTS > 5
nothing,
#endif
#if EXTERNAL_NUM_INTERRUPTS > 4
nothing,
#endif
#if EXTERNAL_NUM_INTERRUPTS > 3
nothing,
#endif
#if EXTERNAL_NUM_INTERRUPTS > 2
nothing,
#endif
#if EXTERNAL_NUM_INTERRUPTS > 1
nothing,
#endif
#if EXTERNAL_NUM_INTERRUPTS > 0
nothing,
#endif
};

void attachInterrupt(uint8_t interruptNum, void (*callbackFunc)(void), int mode)
{
	if(interruptNum < EXTERNAL_NUM_INTERRUPTS)
	{
		intFunc[interruptNum] = callbackFunc;
		
		//configure interrupt mode: CHANGE,RISING,FALING
		//Enable the interrupt
		switch(interruptNum)
		{
			case 0:
				EICRA = (EICRA & ~((1<<ISC00) | (1<<ISC01))) | (mode << ISC00); //Mode select
				EIMSK |= (1<<INT0); // Mask register		
			break;
			case 1:
				EICRA = (EICRA & ~((1<<ISC10) | (1<<ISC11))) | (mode << ISC10);
				EIMSK |= (1<<INT1);
			break;
			case 2:
				EICRA = (EICRA & ~((1<<ISC20) | (1<<ISC21))) | (mode << ISC20);
				EIMSK |= (1<<INT2);
			break;
			case 3:
				EICRA = (EICRA & ~((1<<ISC30) | (1<<ISC31))) | (mode << ISC30);
				EIMSK |= (1<<INT3);
			break;
			case 4:
				EICRB = (EICRB & ~((1 << ISC40) | (1 << ISC41))) | (mode << ISC40);
				EIMSK |= (1 << INT4);
			break;
			case 5:
				EICRB = (EICRB & ~((1 << ISC50) | (1 << ISC51))) | (mode << ISC50);
				EIMSK |= (1 << INT5);
			break;
			case 6:
				EICRB = (EICRB & ~((1 << ISC60) | (1 << ISC61))) | (mode << ISC60);
				EIMSK |= (1 << INT6);
			break;
			case 7:
				EICRB = (EICRB & ~((1 << ISC70) | (1 << ISC71))) | (mode << ISC70);
				EIMSK |= (1 << INT7);
			break;
		}		
	}
}

void detachInterrupt(uint8_t interruptNum)
{
	if(interruptNum < EXTERNAL_NUM_INTERRUPTS)
	{
		// Disable the interrupt.
		switch(interruptNum){
			case 0:
				EIMSK &= ~(1<<INT0);
			break;
			case 1:
				EIMSK &= ~(1<<INT1);
			break;
			case 2:
				EIMSK &= ~(1<<INT2);
			break;
			case 3:
				EIMSK &= ~(1<<INT3);
			break;
			case 4:
				EIMSK &= ~(1<<INT4);
			break;
			case 5:
				EIMSK &= ~(1<<INT5);
			break;
			case 6:
				EIMSK &= ~(1<<INT6);
			break;
			case 7:
				EIMSK &= ~(1<<INT7);
			break;
		}
		intFunc[interruptNum] = nothing;
		
	}
}


#define IMPLEMENT_ISR(vect, interrupt) \
	ISR(vect) { \
		intFunc[interrupt](); \
	}
	
IMPLEMENT_ISR(INT0_vect, EXTERNAL_INT_0)
IMPLEMENT_ISR(INT1_vect, EXTERNAL_INT_1)
IMPLEMENT_ISR(INT2_vect, EXTERNAL_INT_2)
IMPLEMENT_ISR(INT3_vect, EXTERNAL_INT_3)
IMPLEMENT_ISR(INT4_vect, EXTERNAL_INT_4)
IMPLEMENT_ISR(INT5_vect, EXTERNAL_INT_5)
IMPLEMENT_ISR(INT6_vect, EXTERNAL_INT_6)
IMPLEMENT_ISR(INT7_vect, EXTERNAL_INT_7)


/************************************************************************/
/*			         << USAGE >>                                        */
/************************************************************************/
/*
void user_callback(void);

int main(void)
{
	attachInterrupt(EXTERNAL_INT_5,user_callback, RISING);
	
    while (1) 
    {	
    }
}

void user_callback(void)
{
	//do something
}
*/