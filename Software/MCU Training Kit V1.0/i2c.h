/*
 * i2c.h
 *
 * Created: 5/14/2019 10:33:00 PM
 *  Author: OBED
 */ 


#ifndef I2C_H_
#define I2C_H_

///////////********I2C******** //////////////////////////
void I2CInit();
void I2CClose();

void I2CStart();
void I2CStop();

uint8_t I2CWriteByte(uint8_t data);
uint8_t I2CReadByte(uint8_t *data,uint8_t ack);

/////I2C///////////////////////////////////////////////
void I2CInit()
{
	//Set up TWI Module
	TWBR = 2;
	TWSR |=((1<<TWPS1)|(1<<TWPS0));

	//Enable the TWI Module
	TWCR|=(1<<TWEN);

}

void I2CClose()
{
	//Disable the module
	TWCR&=(~(1<<TWEN));
}


void I2CStart()
{
	//Put Start Condition on Bus
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);

	//Poll Till Done
	while(!(TWCR & (1<<TWINT)));
}

void I2CStop()
{
	//Put Stop Condition on bus
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	
	//Wait for STOP to finish
	while(TWCR & (1<<TWSTO));
	//_delay_loop_2(250);
}

uint8_t I2CWriteByte(uint8_t data)
{
	
	TWDR=data;

	//Initiate Transfer
	TWCR=(1<<TWEN)|(1<<TWINT);

	//Poll Till Done
	while(!(TWCR & (1<<TWINT)));

	//Check Status
	if((TWSR & 0xF8) == 0x18 || (TWSR & 0xF8) == 0x28 || (TWSR & 0xF8) == 0x40)
	{
		//SLA+W Transmitted and ACK received
		//or
		//SLA+R Transmitted and ACK received
		//or
		//DATA Transmitted and ACK recived

		return 1;
	}
	else
	return 0;	//Error
}

uint8_t I2CReadByte(uint8_t *data,uint8_t ack)
{
	//Set up ACK
	if(ack)
	{
		//return ACK after reception
		TWCR|=(1<<TWEA);
	}
	else
	{
		//return NACK after reception
		//Signals slave to stop giving more data
		//usually used for last byte read.
		TWCR&=(~(1<<TWEA));
	}

	//Now enable Reception of data by clearing TWINT
	TWCR|=(1<<TWINT);

	//Wait till done
	while(!(TWCR & (1<<TWINT)));

	//Check status
	if((TWSR & 0xF8) == 0x58 || (TWSR & 0xF8) == 0x50)
	{
		//Data received and ACK returned
		//	or
		//Data received and NACK returned

		//Read the data
		*data=TWDR;
		return 1;
	}
	else
	return 0;	//Error
	
}

#endif /* I2C_H_ */