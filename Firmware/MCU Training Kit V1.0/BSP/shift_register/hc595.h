/*
 * hc595.h
 *
 * Created: 10/3/2018 5:26:05 PM
 *  Author: OBED
 */ 


#ifndef HC595_H_
#define HC595_H_

/***************************************
Configure Connections
****************************************/
#define HC595_PORT   PORTD
#define HC595_DDR    DDRD

#define HC595_DS_POS	PD4      //Data pin (DS) pin location
#define HC595_ST_CP_POS PD5      //Store Clock (ST_CP) pin location
#define HC595_SH_CP_POS PD6      //Shift Clock (SH_CP) pin location
#define HC595_MR_POS	PD7      //Master Reclear, active low


//Low level macros to change data (DS)lines
#define HC595DataHigh() (HC595_PORT|=(1<<HC595_DS_POS))
#define HC595DataLow() (HC595_PORT&=(~(1<<HC595_DS_POS)))

void HC595Init();
void HC595Pulse();
void HC595Latch();
void HC595Write(uint8_t data);

/*
//common cathode
uint8_t numbers[12]={
	0b00111111,	 	 //0 B00111111
	0b00000110,	 	 //1
	0b01011011,	 	 //2
	0b01001111,	 	 //3
	0b01100110,	 	 //4
	0b01101101,	 	 //5
	0b01111101,	 	 //6
	0b00000111,	 	 //7
	0b01111111,	 	 //8
	0b01101111,	 	 //9
	0b10000000,	 	 //db
	0b01000000		 //-
};
*/
uint8_t numbers[12]={
	0b11000000,	 	 //0 B00111111
	0b11111001,	 	 //1
	0b10100100,	 	 //2
	0b10110000,	 	 //3
	0b10011001,	 	 //4
	0b10010010,	 	 //5
	0b10000010,	 	 //6
	0b11111000,	 	 //7
	0b10000000,	 	 //8
	0b10010000,	 	 //9
	0b01111111,	 	 //db
	0b10111111		 //-
};

//Initialize HC595 System
void HC595Init()
{
	//Make the Data(DS), Shift clock (SH_CP), Store Clock (ST_CP) lines output
	HC595_DDR|=((1<<HC595_SH_CP_POS)|(1<<HC595_ST_CP_POS)|(1<<HC595_DS_POS)|(1<<HC595_MR_POS));
	HC595_PORT |=(1<<HC595_MR_POS);
}
//Sends a clock pulse on SH_CP line
void HC595Pulse()
{
   //Pulse the Shift Clock
   HC595_PORT|=(1<<HC595_SH_CP_POS);//HIGH
   HC595_PORT&=(~(1<<HC595_SH_CP_POS));//LOW
}

//Sends a clock pulse on ST_CP line
void HC595Latch()
{
   //Pulse the Store Clock
   HC595_PORT|=(1<<HC595_ST_CP_POS);//HIGH
   _delay_loop_1(1);
   HC595_PORT&=(~(1<<HC595_ST_CP_POS));//LOW
   _delay_loop_1(1);
}


/*
Main High level function to write a single byte to
Output shift register 74HC595. 

Arguments:
   single byte to write to the 74HC595 IC

Returns:
   NONE

Description:
   The byte is serially transfered to 74HC595
   and then latched. The byte is then available on
   output line Q0 to Q7 of the HC595 IC.

*/
void HC595Write(uint8_t data)
{
  //Send each 8 bits serially
  //Order is MSB first
  //Output the data on DS line according to the
  //Value of MSB
  for(uint8_t i=0;i<8;i++){
	  if(data & 0b10000000)
	  {
		  //MSB is 1 so output high
		  HC595DataHigh();
	  }
	  else
	  {
		  //MSB is 0 so output high
		  HC595DataLow();
	  }
	  HC595Pulse();  //Pulse the Clock line
	  data=data<<1;  //Now bring next bit at MSB position
  }
 
  //Move them to output latch at one
  HC595Latch();
}

// void Segment_Print(uint8_t n){
// 	if (n > 9){
// 		HC595Write(numbers[11]);
// 	}else{
// 		HC595Write(numbers[n]);
// 	}
// }

void Segment_Print(uint8_t n){
	if (n > 9){
		HC595Write(numbers[11]);
//		} else if (n > 10){
// 		uint8_t x = n/10;
// 		uint8_t r = n-(x*10);
// 		HC595Write(numbers[r],numbers[n]);
		}else{
		HC595Write(numbers[n]);
	}
}
#endif /* HC595_H_ */