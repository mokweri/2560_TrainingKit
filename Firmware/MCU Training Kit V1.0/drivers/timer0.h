/*
 * timer0.h
 *
 * Created: 30/07/2021 11:36:23
 *  Author: OBED
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
/*
-----File Inclusions----------
*/
#include <stdint.h>

/************************************************************************/
/* PUBLIC DATA TYPA                                                     */
/************************************************************************/
typedef enum{
	TIMER0_NORMAL_MODE=0,
	TIMER0_CTC_MODE,
	TIMER0_FAST_PWM_MODE,
	TIMER0_PHASE_CORRECT_PWM_MODE,
	}timer_mode_t;

typedef enum{
	TIMER0_NO_CLK=0,						//No clock source (Timer/Counter stopped).
	TIMER0_NO_PRESCALAR,					//clk / (No prescaling)
	TIMER0_PRESCALAR8,						//clk / 8
	TIMER0_PRESCALAR64,						//clk / 64
	TIMER0_PRESCALAR256,					//clk / 256
	TIMER0_PRESCALAR1024,					//clk / 1024
	TIMER0_EXTERNAL_CLOCK_FALLING_EDGE,		//
	TIMER0_EXTERNAL_CLOCK_RISING_EDGE		//
}timer_prescalar_t;

/************************************************************************/
/*      Public Function Prototypes                                                                */
/************************************************************************/
extern void timer0_mode_set(timer_mode_t timer_mode);

extern void timer0_prescalar_set(timer_prescalar_t timer_prescalar);

extern void timer0_interrupt_enable(timer_mode_t timer_mode);

extern void timer0_interrupt_disable(void);

extern void timer0_TCNT0_load(uint8_t value_to_load);

extern void timer0_OCR0_load( uint8_t value_to_load);

extern void timer0_create_delay_us(uint8_t value_to_load_ocr0, timer_prescalar_t timer_prescalar);

extern void timer0_pwm_duty_cycle_set(uint8_t duty_cycle_percentage);


#endif /* TIMER0_H_ */