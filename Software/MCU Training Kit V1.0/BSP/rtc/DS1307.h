/*
 * rtc.h
 *
 * Created: 1/27/2017 7:25:56 AM
 *  Author: Obed
 */ 


#ifndef RTC_H_
#define RTC_H_

#include <avr/io.h>
#include "i2c.h"


///////////////////////////////////////////////////////////////
uint8_t  ClockInit();

uint8_t DS1307Read(uint8_t address,uint8_t *data);
uint8_t DS1307Write(uint8_t address,uint8_t data);
uint8_t GetSecond();
uint8_t GetMinute();
uint8_t GetHour();
uint8_t GetAmPm();

uint8_t GetDate();
uint8_t GetMonth();
uint8_t GetYear();


//Set Function
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

////////****RTC********///////////////////////////////

uint8_t ClockInit()
{
	//Initialize I2C Bus
	I2CInit();

	//Clear CH bit of RTC
	#define CH 7

	uint8_t temp;
	if(!DS1307Read(0x00,&temp)) return 0;

	//Clear CH Bit
	temp&=(~(1<<CH));

	if(!DS1307Write(0x00,temp)) return 0;

	//Set 12 Hour Mode
	if(!DS1307Read(0x02,&temp)) return 0;

	//Set 12Hour BIT
	temp|=(0b01000000);

	//Write Back to DS1307
	if(!DS1307Write(0x02,temp)) return 0;

	return 1;

}
/***************************************************
Function To Read Internal Registers of DS1307
---------------------------------------------
address : Address of the register
data: value of register is copied to this.

Returns: 0= Failure 1= Success
***************************************************/

uint8_t DS1307Read(uint8_t address,uint8_t *data)
{
	uint8_t res;	//result
	
	//Start
	I2CStart();
	
	//SLA+W (for dummy write to set register pointer)
	res=I2CWriteByte(0b11010000);	//DS1307 address + W
	
	//Error
	if(!res)	return 0;
	
	//Now send the address of required register
	res=I2CWriteByte(address);
	
	//Error
	if(!res)	return 0;
	
	//Repeat Start
	I2CStart();	
	//SLA + R
	res=I2CWriteByte(0b11010001);	//DS1307 Address + R	
	//Error
	if(!res)	return 0;	
	//Now read the value with NACK
	res=I2CReadByte(data,0);	
	//Error
	if(!res)	return 0;	
	//STOP
	I2CStop();
	
	return 1;
}

/***************************************************
Function To Write Internal Registers of DS1307
---------------------------------------------
address : Address of the register
data: value to write.
Returns: 0= Failure 1= Success
***************************************************/

uint8_t DS1307Write(uint8_t address,uint8_t data)
{
	uint8_t res;	//result
	
	//Start
	I2CStart();
	
	//SLA+W
	res=I2CWriteByte(0b11010000);	//DS1307 address + W
	
	//Error
	if(!res)	return 0;
	
	//Now send the address of required register
	res=I2CWriteByte(address);
	
	//Error
	if(!res)	return 0;
	
	//Now write the value
	res=I2CWriteByte(data);
	
	//Error
	if(!res)	return 0;
	
	//STOP
	I2CStop();
	
	return 1;
}


/***************************************
Get second No Parameters
----------
Return Value :the "second" part of time.
****************************************/
uint8_t GetSecond()
{
	uint8_t sec,temp;

	//Read the Second Register
	DS1307Read(0x00,&temp);
	sec=(((temp & 0b01110000)>>4)*10)+(temp & 0b00001111);

	return sec;

	
}
/***************************************
Get minute No Parameters
----------
Return Value: the "minute" part of time.
****************************************/

uint8_t GetMinute()
{
	uint8_t min,temp;

	//Read the Minute Register
	DS1307Read(0x01,&temp);
	min=(((temp & 0b01110000)>>4)*10)+(temp & 0b00001111);

	return min;
	
}

/***************************************
Get hour No Parameters
----------
Return Value :the "hour" part of time.
****************************************/

uint8_t GetHour()
{
	uint8_t hr,temp;

	//Read the Hour Register
	DS1307Read(0x02,&temp);
	hr=(((temp & 0b00010000)>>4)*10)+(temp & 0b00001111);

	return hr;
}

/***************************************
Get am/pm No Parameters
----------
Return Value:0=am 1=pm
****************************************/

uint8_t GetAmPm()
{
	uint8_t am_pm,temp;

	//Read the Hour Register
	DS1307Read(0x02,&temp);

	am_pm=(temp & 0b00100000)>>4;

	return am_pm;

}
/***************************************
Set the second No Parameters
----------
Return Value: 0=failure 1=success
****************************************/

uint8_t SetSecond(uint8_t sec)
{
	uint8_t temp,result;

	temp=((sec/10)<<4)|(sec%10);
	result=DS1307Write(0x00,temp);

	return result;
}

/***************************************
Set the minutes Parameters:minutes
Return Value: 0=failure 1=success
****************************************/

uint8_t SetMinute(uint8_t min)
{
	uint8_t temp,result;

	temp=((min/10)<<4)|(min%10);
	result=DS1307Write(0x01,temp);

	return result;
	
}

/***************************************

Set the hour Parameters:hour
Return Value: 0=failure 1=success
****************************************/

uint8_t SetHour(uint8_t hr)
{
	uint8_t temp,result,am_pm;

	am_pm=GetAmPm();

	temp=((hr/10)<<4)|(hr%10);
	temp|=0b01000000; //12 Hr Mode
	
	if(am_pm)
	{
		temp|=0b00100000;
	}
	result=DS1307Write(0x02,temp);

	return result;
}

/***************************************
Set the second Parameters:0=am,1=pm
Return Value: 0=failure 1=success
****************************************/

uint8_t SetAmPm(uint8_t pm)
{
	uint8_t temp,result;

	DS1307Read(0x02,&temp);

	if(pm)
	temp|=0b00100000;//SET
	else
	temp&=0b11011111;//CLEAR

	result=DS1307Write(0x02,temp);

	return result;
	
}

/***************************************
Gets the current time as a ascii/text string. Example 12:49:22 PM (HH:MM:SS: PM)
Parameters:Pointer to a string.
Return Value: 0=failure 1=success
Example Usage
-------------
char time[12];			//The string must be at least 12bytes long
GetTimeString(time);	//Now the string time contains the current time
****************************************/

uint8_t GetTimeString(char *Time)
{
	uint8_t data;

	if(!DS1307Read(0x00,&data))
	{
		//I/O Error
		return 0;
	}

	Time[11]='\0';
	Time[10]='M';
	Time[8]=' ';

	Time[7]=48+(data & 0b00001111);
	Time[6]=48+((data & 0b01110000)>>4);
	Time[5]=':';

	if(!DS1307Read(0x01,&data))
	{
		//I/O Error
		return 0;
	}
	
	Time[4]=48+(data & 0b00001111);
	Time[3]=48+((data & 0b01110000)>>4);
	Time[2]=':';
	
	if(!DS1307Read(0x02,&data))
	{
		//I/O Error
		return 0;
	}
	
	Time[1]=48+(data & 0b00001111);
	Time[0]=48+((data & 0b00010000)>>4);

	//AM/PM
	if(data & 0b00100000)
	{
		Time[9]='P';
	}
	else
	{
		Time[9]='A';
	}

	return 1;//Success

}
uint8_t GetDate()
{
	uint8_t dt,temp;

	//Read the Hour Register
	DS1307Read(0x04,&temp);
	dt=(((temp & 0b00010000)>>4)*10)+(temp & 0b00001111);

	return dt;
}
uint8_t GetMonth()
{
	uint8_t month,temp;

	//Read the Month Register
	DS1307Read(0x05,&temp);
	month=(((temp & 0b00010000)>>4)*10)+(temp & 0b00001111);

	return month;
}
uint8_t GetYear()
{
	uint8_t yr,temp;

	//Read the Year Register
	DS1307Read(0x06,&temp);
	yr=(temp & 0x0F) + ((temp >> 4) * 10);

	return yr;
}
uint8_t SetDate(uint8_t date)
{
	uint8_t temp,result;

	temp=((date/10)<<4)|(date%10);
	result=DS1307Write(0x04,temp);

	return result;
	
}
uint8_t SetMonth(uint8_t month)
{
	uint8_t temp,result;

	temp=((month/10)<<4)|(month%10);
	result=DS1307Write(0x05,temp);

	return result;
	
}
uint8_t SetYear(uint8_t year)
{
	uint8_t temp,result;

	temp=((year/10)<<4)|(year%10);
	result=DS1307Write(0x06,temp);

	return result;
	
}

uint8_t GetDateString(char *Date)
{
	uint8_t data;

	if(!DS1307Read(0x06,&data))
	{
		//I/O Error
		return 0;
	}
	
	Date[10]='\0';
	Date[9]=48+(data & 0b00001111);
	Date[8]=48+((data & 0b01110000)>>4);
	Date[7]='0';
	Date[6]='2';
	Date[5]='/';

	if(!DS1307Read(0x05,&data))
	{
		//I/O Error
		return 0;
	}
	
	Date[4]=48+(data & 0b00001111);
	Date[3]=48+((data & 0b01110000)>>4);
	Date[2]='/';
	
	if(!DS1307Read(0x04,&data))
	{
		//I/O Error
		return 0;
	}
	
	Date[1]=48+(data & 0b00001111);
	Date[0]=48+((data & 0b00010000)>>4);

	
	return 1;//Success

}

#endif /* RTC_H_ */