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

//birthday---------------------------------------------
int speakerPin = Pin_PE3; // Buzzer pin Pin_PE3
int length = 28; // the number of notes
char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";
int beats[] = {2,2,8,8,8,16,1,2,2,8,8,8,16,1,2,2,8,8,8,8,16,1,2,2,8,8,8,16};
int tempo = 200;// time delay between notes

void playTone(int tone, int duration) {
	for (long i = 0; i < duration * 1000L; i += tone * 2) {
		digitalWrite(speakerPin, HIGH);
		delay_ms(tone);
		digitalWrite(speakerPin, LOW);
		delay_ms(tone);
	}
}

void playNote(char note, int duration) {
	char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B', 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'x', 'y' };

	int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956,  834,  765,  593,  468,  346,  224, 655 , 715 };

	int SPEE = 5;

	// play the tone corresponding to the note name

	for (int i = 0; i < 16; i++) 
	{
		if (names[i] == note) {
			int newduration = duration/SPEE;
			playTone(tones[i], newduration);
		}
	}
}

void birthday()
{
	#define buzz Pin_PE3
	delay_ms(100);
	tone(buzz, 131,250);
	//delay_ms(250);
	noTone(buzz);
	delay_ms(125);
	tone(buzz, 131,250);
	//delay_ms(250);
	tone(buzz, 147,500);
	//delay_ms(500);
	tone(buzz, 131,500);
	//delay_ms(500);
	tone(buzz, 175,500);
	//delay_ms(500);
	tone(buzz, 165,1000);
	//delay_ms(1000);
	tone(buzz, 131,250);
	//delay_ms(250);
	noTone(buzz);
	delay_ms(125);
	tone(buzz, 131,250);
	//delay_ms(250);
	tone(buzz, 147,500);
	//delay_ms(500);
	tone(buzz, 131,500);
	//delay_ms(500);
	tone(buzz, 196,500);
	//delay_ms(500);
	tone(buzz, 175,1000);
	//delay_ms(1000);
	tone(buzz, 131,250);
	//delay_ms(250);
	noTone(buzz);
	delay_ms(125);
	tone(buzz, 131,250);
	//delay_ms(250);
	tone(buzz, 262,500);
	//delay_ms(500);
	tone(buzz, 220,500);
	//delay_ms(500);
	tone(buzz, 175,500);
	//delay_ms(500);
	tone(buzz, 165,500);
	//delay_ms(500);
	tone(buzz, 147,500);
	//delay_ms(500);
	tone(buzz, 233,250);
	//delay_ms(250);
	noTone(buzz);
	delay_ms(125);
	tone(buzz, 233,250);
	//delay_ms(250);
	tone(buzz, 220,500);
	//delay_ms(500);
	tone(buzz, 175,500);
	//delay_ms(500);
	tone(buzz, 196,500);
	//delay_ms(500);
	tone(buzz, 175,1000);
	//delay_ms(1000);
	noTone(buzz);
	delay_ms(100);
}
//-----------------------------------------

void sdDetected(void);
void Button1(void);
void Button2(void);
void Button3(void);
void LCD_PrintInt(uint16_t n,uint8_t x,uint8_t y);



int main(void)
{
	millis_init();
	pwm_init();
	adc_init();
	Serial0_begin(9600, SERIAL_8N1);
	
	lcd_init();
	lcd_clear();
	LCD_PrintString("MCU TRAINING KIT",0,0);
	
	ClockInit();

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
	
	//buzzerpin
	//pinMode(Pin_PE3, OUTPUT);
	
	birthday();
// 	//Tone Example	
// 	for (int thisNote = 0; thisNote < 8; thisNote++) 
// 	{
// 		// to calculate the note duration, take one second divided by the note type.
// 		//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
// 		int noteDuration = 1000 / noteDurations[thisNote];
// 		tone(Pin_PE3, melody[thisNote], noteDuration);
// 		// to distinguish the notes, set a minimum time between them.
// 		// the note's duration + 30% seems to work well:
// 		int pauseBetweenNotes = noteDuration * 1.30;
// 		delay_ms(pauseBetweenNotes);		
// 		// stop the tone playing:
// 		noTone(Pin_PE3);
// 	}

const int BUFFER_SIZE = 10;
char buf[BUFFER_SIZE];
char time_string[11];
	
    while (1) 
    {
		/*
		int pot_val = analogRead(Pin_PF0);
		
		LCD_PrintInt(pot_val,4,1);
		delay_ms(50);
		LCD_PrintString("ADC:    ",0,1);//clear line
		*/
		
		GetTimeString(time_string);
		LCD_PrintString(time_string,2,1);
		
		/*
		if (digitalRead(Pin_PJ2))
		{
			_delay_ms(70);
			togglePin(Pin_PK0);
		}
		*/
		lcd_setCursor(0,1);
		if (Serial0_available())
		{
// 			int r = Serial2_timedRead();
// 			LCD_PrintInt(r,0,1);
// 			Serial2_write(r);

			delay_ms(1000);//wait for all data
			Serial0_readAllBytes(buf, BUFFER_SIZE);
			Serial0_print(buf);		
			
		}
		
// 		for (int i = 0; i < length; i++) {
// 			if (notes[i] == ' ') {
// 				delay_ms(beats[i] * tempo); // delay between notes
// 				} else {
// 				playNote(notes[i], beats[i] * tempo);
// 			}
// 			// time delay between notes
// 			delay_ms(tempo);
// 		}
		
    }
}

void sdDetected(void)
{
	LCD_PrintString("SD Detected",0,1);
}

void Button1(void)
{
	//char str[] = "Good";
	togglePin(Pin_PK0);
// 	Serial2_write('G');
// 	Serial2_write('o');
// 	Serial2_write('o');
// 	Serial2_write('o');
// 	Serial2_write('o');
// 	Serial2_write('o');
// 	Serial2_write('d');
	Serial0_print("Good stuff");

}
void Button2(void)
{
	togglePin(Pin_PK1);
}
void Button3(void)
{
	togglePin(Pin_PK2);
	
}

void LCD_PrintInt(uint16_t n,uint8_t x,uint8_t y){
	char buffer[10];
	itoa(n,buffer,10);
	LCD_PrintString(buffer,x,y);
	
}

