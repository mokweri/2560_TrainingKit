/*
 * TK2560.c
 *
 * Created: 02/08/2021 08:12:34
 * Author : OBED
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "drivers/tk2560.h"
#include "drivers/pitches.h"

void delay_ms(uint16_t count) {
	while(count--) {
		_delay_ms(1);

	}
}

// notes in the melody:
int melody[] = {
	NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
	4, 8, 8, 4, 4, 4, 4, 4
};

int main(void)
{
    /* Replace with your application code */
	pinMode(Pin_PK0, OUTPUT);
	pinMode(Pin_PK3, OUTPUT);
	pinMode(Pin_PJ2, INPUT);
	
	for (int thisNote = 0; thisNote < 8; thisNote++) {
		// to calculate the note duration, take one second divided by the note type.
		//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

		int noteDuration = 1000 / noteDurations[thisNote];
		tone(Pin_PE3, melody[thisNote], noteDuration);
		// to distinguish the notes, set a minimum time between them.
		// the note's duration + 30% seems to work well:
		int pauseBetweenNotes = noteDuration * 1.30;
		delay_ms(pauseBetweenNotes);
		
		// stop the tone playing:
		noTone(Pin_PE3);

	}
// 	  for(int i=0; i<8; i++)
// 	  {
// 		  tone(Pin_PE3,432, 300);
// 		  _delay_ms(350);
// 		  noTone(Pin_PE3);
// 		  //togglePin(Pin_PK3);
// 	  }
// 	
	
    while (1) 
    {
		
		/*
		if (digitalRead(Pin_PJ2))
		{
			_delay_ms(70);
			togglePin(Pin_PK0);
		}
		*/
		
		_delay_ms(1000);
		togglePin(Pin_PK3);
		
		
    }
}

