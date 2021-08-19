/*
 * adc.c
 *
 * Created: 19/08/2021 08:40:14
 *  Author: OBED
 */ 
#include "tk2560.h"

uint8_t analog_reference = DEFAULT;

void analogReference(uint8_t mode)
{
	// can't actually set the register here because the default setting
	// will connect AVCC and the AREF pin, which would cause a short if
	// there's something connected to AREF.
	analog_reference = mode;
}

void adc_init(void)
{
	// set ADC prescaler so we are inside the desired 50-200 KHz range.
#if F_CPU >= 16000000 // 16 MHz / 128 = 125 KHz
	bitSet(ADCSRA, ADPS2);
	bitSet(ADCSRA, ADPS1);
	bitSet(ADCSRA, ADPS0);
#elif F_CPU >= 8000000 // 8 MHz / 64 = 125 KHz
	bitSet(ADCSRA, ADPS2);
	bitSet(ADCSRA, ADPS1);
	bitSet(ADCSRA, ADPS0);
#elif F_CPU >= 4000000 // 4 MHz / 32 = 125 KHz
	bitSet(ADCSRA, ADPS2);
	bitSet(ADCSRA, ADPS1);
	bitSet(ADCSRA, ADPS0);
#elif F_CPU >= 2000000 // 2 MHz / 16 = 125 KHz
	bitSet(ADCSRA, ADPS2);
	bitSet(ADCSRA, ADPS1);
	bitSet(ADCSRA, ADPS0);
#elif F_CPU >= 1000000 // 1 MHz / 8 = 125 KHz
	bitSet(ADCSRA, ADPS2);
	bitSet(ADCSRA, ADPS1);
	bitSet(ADCSRA, ADPS0);
#else // 128 kHz / 2 = 64 KHz -> This is the closest you can get, the prescaler is 2
	bitSet(ADCSRA, ADPS2);
	bitSet(ADCSRA, ADPS1);
	bitSet(ADCSRA, ADPS0);
#endif

	//Enable ADC conversions
	bitSet(ADCSRA, ADEN);
	
}

int analogRead(uint8_t pin)
{
	uint8_t channel = pinToADCChannel(pin);
	
	if(channel != NOT_ADC_PIN){
		// the MUX5 bit of ADCSRB selects whether we're reading from channels
		// 0 to 7 (MUX5 low) or 8 to 15 (MUX5 high).
		ADCSRB = (ADCSRB & ~(1 << MUX5)) | (((channel >> 3) & 0x01) << MUX5);
		
		// set the analog reference (high two bits of ADMUX) and select the channel (low 4 bits).  
		// this also sets ADLAR (left-adjust result) to 0 (the default- right adjusted).
		ADMUX = (analog_reference << 6) | (channel & 0x0F );
		
		//Start the conversion
		ADCSRA |= (1<<ADSC);
		// Wait completion of ADC
		while (bit_is_set(ADCSRA, ADSC));
		
		return (ADC);
	}else{
		return 0;
	}
}