/*
 * ds1307.h
 *
 * Created: 23/08/2021 11:37:36
 *  Author: OBED
 */ 


#ifndef DS1307_H_
#define DS1307_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "drivers/twi.h"



/************************************************************************/
/*   APIs                                                               */
/************************************************************************/
uint8_t DS1307Read(uint8_t address,uint8_t *data);


uint8_t  ClockInit();

//Get Functions
uint8_t DS1307Read(uint8_t address,uint8_t *data);
uint8_t DS1307Write(uint8_t address,uint8_t data);
uint8_t GetSecond();
uint8_t GetMinute();
uint8_t GetHour();
uint8_t GetAmPm();

uint8_t GetDate();
uint8_t GetMonth();
uint8_t GetYear();


//Set Functions
uint8_t SetSecond(uint8_t sec);
uint8_t SetMinute(uint8_t min);
uint8_t SetHour(uint8_t hr);
uint8_t SetAmPm(uint8_t pm);

uint8_t SetDate(uint8_t date);
uint8_t SetMonth(uint8_t month);
uint8_t SetYear(uint8_t year);


//Time as string e.g. "12:45:33 PM"
uint8_t GetTimeString(char *Time);
//Date as string e.g. "12/03/2015"
uint8_t GetDateString(char *Date);

#endif /* DS1307_H_ */