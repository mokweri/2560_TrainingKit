/*
 * timer1.h
 *
 * Created: 4/23/2019 1:35:47 PM
 *  Author: OBED
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#define CTC_MATCH_OVERFLOW ((F_CPU / 1000) / 8)

void timer1_Init(){
	cli();
	TCCR1A = 0;
	TCCR1B = 0;
	TCCR1B |=(1<<CS11)|(1<<WGM12);  //clk/8 waveform
		
	OCR1AH = (CTC_MATCH_OVERFLOW >> 8);
	OCR1AL = CTC_MATCH_OVERFLOW;
	TIMSK1 |= 1<<OCIE1A;
	TCNT1 =0;
	sei();
}

ISR(TIMER1_COMPA_vect){
	
	if (system_count%1000==0){ //every second
		//toggleLED(5);
	}
	if (system_count%50 == 0){ //keypress 50ms
	}
	
	system_count++; //millis
}



#endif /* TIMER1_H_ */