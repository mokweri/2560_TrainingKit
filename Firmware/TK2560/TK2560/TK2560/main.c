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

// void delay_ms(uint16_t count) {
// 	while(count--) {
// 		_delay_ms(1);
// 
// 	}
// }

unsigned long period = 1000000;
unsigned long time_now = 0;

// notes in the melody:
int melody[] = {
	NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
	4, 8, 8, 4, 4, 4, 4, 4
};

void sdDetected(void);
void Button1(void);
void Button2(void);
void Button3(void);

int main(void)
{
	millis_init();
	pwm_init();
	
	lcd_init();
	lcd_clear();
	LCD_PrintString("MCU TRAINING KIT",0,0);

	//User LEDs
	pinMode(Pin_PK0, OUTPUT);
	pinMode(Pin_PK1, OUTPUT);
	pinMode(Pin_PK2, OUTPUT);
	
	//Buttons - Pin change
	pinMode(Pin_PJ2, INPUT);
	pinMode(Pin_PJ3, INPUT);
	pinMode(Pin_PJ4, INPUT);
	attachPCINT(pinToPCINT(Pin_PJ2), Button1, RISING);
	attachPCINT(pinToPCINT(Pin_PJ3), Button2, RISING);
	attachPCINT(pinToPCINT(Pin_PJ4), Button3, RISING);
	
	attachInterrupt(EXTERNAL_INT_5,sdDetected, RISING);
	
	analogWrite(Pin_PH3,255/4);
	

	//Tone Example	
	for (int thisNote = 0; thisNote < 8; thisNote++) 
	{
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

    while (1) 
    {
		
		/*
		if (digitalRead(Pin_PJ2))
		{
			_delay_ms(70);
			togglePin(Pin_PK0);
		}
		*/
		
		
    }
}

void sdDetected(void)
{
	LCD_PrintString("SD Detected",0,1);
}

void Button1(void)
{
	togglePin(Pin_PK0);
}
void Button2(void)
{
	togglePin(Pin_PK1);
}
void Button3(void)
{
	togglePin(Pin_PK2);
	
}
