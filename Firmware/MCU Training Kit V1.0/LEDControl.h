/*
 * LEDControl.h
 *
 * Created: 4/23/2019 12:45:10 PM
 *  Author: OBED
 */ 


#ifndef LEDCONTROL_H_
#define LEDCONTROL_H_

#define ON  1
#define OFF 0

#ifndef LED_PORT1
# define LED_PORT	PORTK
#define  LED_DDR    DDRK
#endif


//Port Pins for the LEDs
#define LED1 0
#define LED2 1
#define LED3 2
#define LED4 3
#define LED5 4
#define LED6 5
#define LED7 6

void LED_Init(){
	//Output
	LED_DDR |=(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6); // Pins 0,4,5,6 and 7
	
}

void LED(int led,int ONOFF){
	switch (led){
		case 1:
			if (ONOFF == ON) { LED_PORT |=(1<<LED1);} else { LED_PORT &=~(1<<LED1);}
		break;
		case 2:
			if (ONOFF == ON) { LED_PORT |=(1<<LED2);} else { LED_PORT &=~(1<<LED2);}
		break;
		case 3:
			if (ONOFF == ON) { LED_PORT |=(1<<LED3);} else { LED_PORT &=~(1<<LED3);}
		break;		
		case 4:
			if (ONOFF == ON) { LED_PORT |=(1<<LED4);} else { LED_PORT &=~(1<<LED4);}
		break;		
		case 5:
			if (ONOFF == ON) { LED_PORT |=(1<<LED5);} else { LED_PORT &=~(1<<LED5);}
		break;		
		case 6:
			if (ONOFF == ON) { LED_PORT |=(1<<LED6);} else { LED_PORT &=~(1<<LED7);}
		break;
		case 7:
			if (ONOFF == ON) { LED_PORT |=(1<<LED7);} else { LED_PORT &=~(1<<LED7);}
		break;
		default:
		break;
	}
}

void toggleLED(int led){
	switch (led){
		case 1:
			LED_PORT ^=(1<<LED1);
		break;
		case 2:
			LED_PORT ^=(1<<LED2);
		break;
		case 3:
			LED_PORT ^=(1<<LED3);
		break;
		case 4:
			LED_PORT ^=(1<<LED4);
		break;
		case 5:
			LED_PORT ^=(1<<LED5);
		break;
		case 6:
			LED_PORT ^=(1<<LED6);
		break;
		case 7:
			LED_PORT ^=(1<<LED7);
		break;
		default:
		break;
	}
}


#endif /* LEDCONTROL_H_ */