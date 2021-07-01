/*
 * keypad.h
 *
 * Created: 5/5/2017 4:54:08 PM
 *  Author: OBED
 */ 

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>


#ifndef KEYPAD_PORT
# define KEYPAD_PORT	PORTC
#define  KEYPAD_DDR		DDRC
#endif

#ifndef KEYPAD_PIN
# define KEYPAD_PIN	PINC
#endif


unsigned char read_keypad(void);
void keypad_Init(void);

void keypad_Init(void)
{
		 KEYPAD_DDR = 0x0f;  //Initialize Keypad Port
		 KEYPAD_PORT = 0xff;
}


unsigned char read_keypad(void)
{
	unsigned char keypad_input=0xff,keypad_output=0xff;
	KEYPAD_PORT=0xfe;
	_delay_us(2);
	keypad_input=KEYPAD_PIN & 0xf0;

	if(keypad_input==0xe0)
	keypad_output=0x01;
	else if(keypad_input==0xd0)
	keypad_output=0x02;
	else if(keypad_input==0xb0)
	keypad_output=0x03;
	else if(keypad_input==0x70)
	keypad_output=0x0c;
	else
	;

	KEYPAD_PORT=0xfd;
	_delay_us(2);
	keypad_input=KEYPAD_PIN & 0xf0;

	if(keypad_input==0xe0)
	keypad_output=0x04;
	else if(keypad_input==0xd0)
	keypad_output=0x05;
	else if(keypad_input==0xb0)
	keypad_output=0x06;
	else if(keypad_input==0x70)
	keypad_output=0x0d;
	else
	;

	KEYPAD_PORT=0xfb;
	_delay_us(2);
	keypad_input=KEYPAD_PIN & 0xf0;

	if(keypad_input==0xe0)
	keypad_output=0x07;
	else if(keypad_input==0xd0)
	keypad_output=0x08;
	else if(keypad_input==0xb0)
	keypad_output=0x09;
	else if(keypad_input==0x70)
	keypad_output=0x0e;
	else
	;
	
	KEYPAD_PORT=0xf7;
	_delay_us(2);
	keypad_input=KEYPAD_PIN & 0xf0;

	if(keypad_input==0xe0)
	keypad_output=0x0a;
	else if(keypad_input==0xd0)
	keypad_output=0x00;
	else if(keypad_input==0xb0)
	keypad_output=0x0b;
	else if(keypad_input==0x70)
	keypad_output=0x0f;
	else
	;
//	return keypad_output;
//}

	if(keypad_output !=0xff)
	{
		LCD_PrintString("KeyPress: ",0,3);
 		switch(keypad_output)
 		{
 			case 0:
 			LCD_PrintString("A",9,3);//A
 			break;
 			case 1:
 			LCD_PrintString("9",9,3);///9
 			break;
 			case 2:
 			LCD_PrintString("C",9,3);//C
 			break;
 			case 3:
 			LCD_PrintString("8",9,3);//8
 			break;
 			case 4:
 			LCD_PrintString("#",9,3);//#
 			break;
 			case 5:
 			LCD_PrintString("D",9,3);//D
 			break;
 			case 6:
 			LCD_PrintString("0",9,3);//0
 			break;
 			case 7:
 			LCD_PrintString("6",9,3);//6
 			break;
 			case 8:
 			LCD_PrintString("B",9,3);//B
 			break;
 			case 9:
 			LCD_PrintString("5",9,3);//5
 			break;
 			case 10:
 			LCD_PrintString("3",9,3);//3
 			break;
 			case 11:
 			LCD_PrintString("2",9,3);//2
 			break;
 			case 12:
 			LCD_PrintString("7",9,3);//7
 			break;
 			case 13:
 			LCD_PrintString("*",9,3);//*
 			break;
 			case 14:
 			LCD_PrintString("4",9,3);//4
 			break;
 			case 15:
 			LCD_PrintString("1",9,3);//1
 			break;
 		} //end switch
		 
 	}else {
 		;				/*Null statement*/

 	}
}
#endif /* KEYPAD_H_ */