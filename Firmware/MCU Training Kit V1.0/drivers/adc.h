/*
 * adc.h
 *
 * Created: 4/29/2019 10:32:21 PM
 *  Author: OBED
 */ 


#ifndef ADC_H_
#define ADC_H_

void ADC_init()
{
	ADMUX |=(1<<REFS0);  // VCC Reference
	//For 16MHz clock
	//ADCSRA |=(1<<ADEN) |(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2); // 128 prescaler, ADC enable
	
	//For 1MHz clock
	ADCSRA |=(1<<ADEN) |(1<<ADPS0)|(1<<ADPS1); // 8 prescaler, ADC enable
	
	//sei();
}

uint16_t ADC_read(uint8_t channel)
{
	ADMUX = (ADMUX & 0xF0)| (channel & 0x0F);
	
	ADCSRA |=( 1<<ADSC ) ; //Start conversion	
	while(ADCSRA & (1<<ADSC)); //wait completion of ADC
	
	return (ADC);
}


#endif /* ADC_H_ */