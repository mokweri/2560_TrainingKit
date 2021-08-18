/*
 * pinChangeInterrupts.c
 *
 * Created: 18/08/2021 11:11:29
 *  Author: OBED
 */ 
#include "pinChangeInterrupts.h"

//================================================================================
// Makro Definitions
//================================================================================
// generates the callback for easier reordering in Settings
#define PCINT_MACRO_BRACKETS ()
#define PCINT_MACRO_TRUE == true)
#define PCINT_CALLBACK(bit, pcint) \
if (PCINT_USE_PCINT ## pcint PCINT_MACRO_TRUE \
if (trigger & (1 << bit)) \
PinChangeInterruptEventPCINT ## pcint PCINT_MACRO_BRACKETS

//================================================================================
// Suggested Settings
//================================================================================

/* Reordering interrupt callbacks priority
Port0 has SPI on lower pins, move the priority down
Its more likely the user will use pin B23-26
Port1 by default deactivated, ordering is fine
Port2 only has ADCs, ordering is fine
*/
#if !defined(PCINT_CALLBACK_PORT0)
#define PCINT_CALLBACK_PORT0 \
PCINT_CALLBACK(4, 4); \
PCINT_CALLBACK(5, 5); \
PCINT_CALLBACK(6, 6); \
PCINT_CALLBACK(7, 7); \
PCINT_CALLBACK(0, 0); /* SPI SS */ \
PCINT_CALLBACK(1, 1); /* SPI SCK */ \
PCINT_CALLBACK(2, 2); /* SPI MISO */ \
PCINT_CALLBACK(3, 3); /* SPI MOSI */
#endif



void pcint_null_callback(void) {
	// useless
}

#if (PCINT_USE_PCINT0 == true)
volatile callback callbackPCINT0;
#endif
#if (PCINT_USE_PCINT1 == true)
volatile callback callbackPCINT1;
#endif
#if (PCINT_USE_PCINT2 == true)
volatile callback callbackPCINT2;
#endif
#if (PCINT_USE_PCINT3 == true)
volatile callback callbackPCINT3;
#endif
#if (PCINT_USE_PCINT4 == true)
volatile callback callbackPCINT4;
#endif
#if (PCINT_USE_PCINT5 == true)
volatile callback callbackPCINT5;
#endif
#if (PCINT_USE_PCINT6 == true)
volatile callback callbackPCINT6;
#endif
#if (PCINT_USE_PCINT7 == true)
volatile callback callbackPCINT7;
#endif
#if (PCINT_USE_PCINT8 == true)
volatile callback callbackPCINT8;
#endif
#if (PCINT_USE_PCINT9 == true)
volatile callback callbackPCINT9;
#endif
#if (PCINT_USE_PCINT10 == true)
volatile callback callbackPCINT10;
#endif
#if (PCINT_USE_PCINT11 == true)
volatile callback callbackPCINT11;
#endif
#if (PCINT_USE_PCINT12 == true)
volatile callback callbackPCINT12;
#endif
#if (PCINT_USE_PCINT13 == true)
volatile callback callbackPCINT13;
#endif
#if (PCINT_USE_PCINT14 == true)
volatile callback callbackPCINT14;
#endif
#if (PCINT_USE_PCINT15 == true)
volatile callback callbackPCINT15;
#endif
#if (PCINT_USE_PCINT16 == true)
volatile callback callbackPCINT16;
#endif
#if (PCINT_USE_PCINT17 == true)
volatile callback callbackPCINT17;
#endif
#if (PCINT_USE_PCINT18 == true)
volatile callback callbackPCINT18;
#endif
#if (PCINT_USE_PCINT19 == true)
volatile callback callbackPCINT19;
#endif
#if (PCINT_USE_PCINT20 == true)
volatile callback callbackPCINT20;
#endif
#if (PCINT_USE_PCINT21 == true)
volatile callback callbackPCINT21;
#endif
#if (PCINT_USE_PCINT22 == true)
volatile callback callbackPCINT22;
#endif
#if (PCINT_USE_PCINT23 == true)
volatile callback callbackPCINT23;
#endif
	
//================================================================================
// PinChangeInterrupt User Functions
//================================================================================
// variables to save the last port states and the interrupt settings
uint8_t oldPorts[PCINT_NUM_USED_PORTS] = {0};
uint8_t fallingPorts[PCINT_NUM_USED_PORTS] = {0};
uint8_t risingPorts[PCINT_NUM_USED_PORTS] = {0};
	
void attachPinChangeInterrupt(const uint8_t pcintNum, void(*userFunc)(void), const uint8_t mode)
{
	// check if pcint is a valid pcint, exclude deactivated ports
	uint8_t pcintPort = pcintNum / 8;
	uint8_t pcintBit = pcintNum % 8;
	sei();
	
	//Port 0
	if (pcintPort == 0 && PCINT_USE_PORT0 == true) {
#if (PCINT_USE_PCINT0 == true)
		if (pcintNum == 0)
			callbackPCINT0 = userFunc;
#endif
#if (PCINT_USE_PCINT1 == true)
		if (pcintNum == 1)
			callbackPCINT1 = userFunc;
#endif
#if (PCINT_USE_PCINT2 == true)
		if (pcintNum == 2)
			callbackPCINT2 = userFunc;
#endif
#if (PCINT_USE_PCINT3 == true)
		if (pcintNum == 3)
			callbackPCINT3 = userFunc;
#endif
#if (PCINT_USE_PCINT4 == true)
		if (pcintNum == 4)
			callbackPCINT4 = userFunc;
#endif
#if (PCINT_USE_PCINT5 == true)
		if (pcintNum == 5)
			callbackPCINT5 = userFunc;
#endif
#if (PCINT_USE_PCINT6 == true)
		if (pcintNum == 6)
			callbackPCINT6 = userFunc;
#endif
#if (PCINT_USE_PCINT7 == true)
		if (pcintNum == 7)
			callbackPCINT7 = userFunc;
#endif
		
		//Port 1
	}else if(pcintPort == 1 && PCINT_USE_PORT1 == true){
#if (PCINT_USE_PCINT8 == true)
		if (pcintNum == 8)
			callbackPCINT8 = userFunc;
#endif
#if (PCINT_USE_PCINT9 == true)
		if (pcintNum == 9)
			callbackPCINT9 = userFunc;
#endif
#if (PCINT_USE_PCINT10 == true)
		if (pcintNum == 10)
			callbackPCINT10 = userFunc;
#endif
#if (PCINT_USE_PCINT11 == true)
		if (pcintNum == 11)
			callbackPCINT11 = userFunc;
#endif
#if (PCINT_USE_PCINT12 == true)
		if (pcintNum == 12)
			callbackPCINT12 = userFunc;
#endif
#if (PCINT_USE_PCINT13 == true)
		if (pcintNum == 13)
			callbackPCINT13 = userFunc;
#endif
#if (PCINT_USE_PCINT14 == true)
		if (pcintNum == 14)
			callbackPCINT14 = userFunc;
#endif
#if (PCINT_USE_PCINT15 == true)
		if (pcintNum == 15)
			callbackPCINT15 = userFunc;
#endif

	//Port 2
	}else if (pcintPort == 2 && PCINT_USE_PORT2 == true) {
#if (PCINT_USE_PCINT16 == true)
		if (pcintNum == 16)
			callbackPCINT16 = userFunc;
#endif
#if (PCINT_USE_PCINT17 == true)
		if (pcintNum == 17)
			callbackPCINT17 = userFunc;
#endif
#if (PCINT_USE_PCINT18 == true)
		if (pcintNum == 18)
			callbackPCINT18 = userFunc;
#endif
#if (PCINT_USE_PCINT19 == true)
		if (pcintNum == 19)
			callbackPCINT19 = userFunc;
#endif
#if (PCINT_USE_PCINT20 == true)
		if (pcintNum == 20)
			callbackPCINT20 = userFunc;
#endif
#if (PCINT_USE_PCINT21 == true)
		if (pcintNum == 21)
			callbackPCINT21 = userFunc;
#endif
#if (PCINT_USE_PCINT22 == true)
		if (pcintNum == 22)
			callbackPCINT22 = userFunc;
#endif
#if (PCINT_USE_PCINT23 == true)
		if (pcintNum == 23)
			callbackPCINT23 = userFunc;
#endif
	}else return;
	
	// get bitmask and array position
	uint8_t pcintMask = (1 << pcintBit);
	uint8_t arrayPos = getArrayPosPCINT(pcintPort);

	// save settings related to mode and registers
	if (mode == CHANGE || mode == RISING)
		risingPorts[arrayPos] |= pcintMask;
	if (mode == CHANGE || mode == FALLING)
		fallingPorts[arrayPos] |= pcintMask;
	
	// call the actual hardware attach function
	enablePinChangeInterruptHelper(pcintPort, pcintMask, arrayPos);
}

void detachPinChangeInterrupt(const uint8_t pcintNum) {
	// get PCINT registers
	uint8_t pcintPort = pcintNum / 8;
	uint8_t pcintBit = pcintNum % 8;
	
	// check if pcint is a valid pcint, exclude deactivated ports
	// port 0
	if (pcintPort == 0 && PCINT_USE_PORT0 == true) {
#if (PCINT_USE_PCINT0 == true)
		if (pcintNum == 0)
			callbackPCINT0 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT1 == true)
		if (pcintNum == 1)
			callbackPCINT1 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT2 == true)
		if (pcintNum == 2)
			callbackPCINT2 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT3 == true)
		if (pcintNum == 3)
			callbackPCINT3 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT4 == true)
		if (pcintNum == 4)
			callbackPCINT4 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT5 == true)
		if (pcintNum == 5)
			callbackPCINT5 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT6 == true)
		if (pcintNum == 6)
			callbackPCINT6 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT7 == true)
		if (pcintNum == 7)
			callbackPCINT7 = pcint_null_callback;
#endif
		
		//Port1
		}else if (pcintPort == 1 && PCINT_USE_PORT1 == true){
#if (PCINT_USE_PCINT8 == true)
		if (pcintNum == 8)
			callbackPCINT8 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT9 == true)
		if (pcintNum == 9)
			callbackPCINT9 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT10 == true)
		if (pcintNum == 10)
			callbackPCINT10 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT11 == true)
		if (pcintNum == 11)
			callbackPCINT11 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT12 == true)
		if (pcintNum == 12)
			callbackPCINT12 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT13 == true)
		if (pcintNum == 13)
			callbackPCINT13 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT14 == true)
		if (pcintNum == 14)
			callbackPCINT14 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT15 == true)
		if (pcintNum == 15)
			callbackPCINT15 = pcint_null_callback;
#endif
		
		//Port2
		}else if (pcintPort == 2 && PCINT_USE_PORT2 == true){
#if (PCINT_USE_PCINT16 == true)
		if (pcintNum == 16)
			callbackPCINT16 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT17 == true)
		if (pcintNum == 17)
			callbackPCINT17 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT18 == true)
		if (pcintNum == 18)
			callbackPCINT18 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT19 == true)
		if (pcintNum == 19)
			callbackPCINT19 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT20 == true)
		if (pcintNum == 20)
			callbackPCINT20 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT21 == true)
		if (pcintNum == 21)
			callbackPCINT21 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT22 == true)
		if (pcintNum == 22)
			callbackPCINT22 = pcint_null_callback;
#endif
#if (PCINT_USE_PCINT23 == true)
		if (pcintNum == 23)
			callbackPCINT23 = pcint_null_callback;
#endif
	}
	else return;
	// get bitmask and array position
	uint8_t pcintMask = (1 << pcintBit);
	uint8_t arrayPos = getArrayPosPCINT(pcintPort);

	// delete setting
	risingPorts[arrayPos] &= ~pcintMask;
	fallingPorts[arrayPos] &= ~pcintMask;

	// call the actual hardware disable function
	disablePinChangeInterruptHelper(pcintPort, pcintMask);
}

// enable interrupt again if temporary disabled
static inline void enablePinChangeInterrupt(const uint8_t pcintNum) __attribute__((always_inline));
void enablePinChangeInterrupt(const uint8_t pcintNum) {
	// get PCINT registers
	uint8_t pcintPort = pcintNum / 8;
	uint8_t pcintBit = pcintNum % 8;

	// check if pcint is a valid pcint, exclude deactivated ports
	if (pcintPort == 0) {
		if (PCINT_USE_PORT0 == false)
		return;
	}
	else if (pcintPort == 1) {
		if (PCINT_USE_PORT1 == false)
		return;
	}
	else if (pcintPort == 2) {
		if (PCINT_USE_PORT2 == false)
		return;
	}
	else return;

	// call the actual hardware attach function
	uint8_t pcintMask = (1 << pcintBit);
	uint8_t arrayPos = getArrayPosPCINT(pcintPort);
	enablePinChangeInterruptHelper(pcintPort, pcintMask, arrayPos);
}

void enablePinChangeInterruptHelper(const uint8_t pcintPort, const uint8_t pcintMask, const uint8_t arrayPos){
	
	switch(pcintPort){
#ifdef PCINT_INPUT_PORT0_USED
		case 0:
			oldPorts[arrayPos] = PCINT_INPUT_PORT0;
		break;
#endif
#ifdef PCINT_INPUT_PORT1_USED
		case 1:
			oldPorts[arrayPos] = PCINT_INPUT_PORT1;
		break;
#endif
#ifdef PCINT_INPUT_PORT2_USED
		case 2:
			oldPorts[arrayPos] = PCINT_INPUT_PORT2;
		break;
#endif
	}
	
	// Pin change mask registers decide which pins are ENABLE as triggers
	switch(pcintPort){
		case 0:
			PCMSK0 |= pcintMask;
		break;
		case 1:
			PCMSK1 |= pcintMask;
		break;
		case 2:
			PCMSK2 |= pcintMask;
		break;
	}
	
	// PCICR: Pin Change Interrupt Control Register - enables interrupt vectors
	PCICR |= (1  << (pcintPort + PCIE0));
	
}

void disablePinChangeInterruptHelper(const uint8_t pcintPort, const uint8_t pcintMask) {
	bool disable = false;
	
	switch(pcintPort){
		case 0:
			// disable the mask.
			PCMSK0 &= ~pcintMask;

			// if that's the last one, disable the interrupt.
			if (!PCMSK0)
				disable = true;
		break;
		case 1:
			// disable the mask.
			PCMSK1 &= ~pcintMask;

			// if that's the last one, disable the interrupt.
			if (!PCMSK1)
				disable = true;
			break;
		case 2:
			// disable the mask.
			PCMSK2 &= ~pcintMask;

			// if that's the last one, disable the interrupt.
			if (!PCMSK2)
				disable = true;
		break;
	}
	
	if(disable){
		PCICR &= ~(1  << (pcintPort + PCIE0));
	}
	
}

//================================================================================
// Interrupt Handler
//================================================================================
//============= PORT0 ===================================
#if (PCINT_USE_PORT0 == true)

ISR (PCINT0_vect){
	// get the new and old pin states for port
	uint8_t newPort = PCINT_INPUT_PORT0;
	
	// compare with the old value to detect a rising or falling
	uint8_t arrayPos = getArrayPosPCINT(0);
	uint8_t change = newPort ^ oldPorts[arrayPos]; //XOR detects change
	uint8_t rising = change & newPort;
	uint8_t falling = change & oldPorts[arrayPos];
	
	// check which pins are triggered, compared with the settings
	uint8_t risingTrigger = rising & risingPorts[arrayPos];
	uint8_t fallingTrigger = falling & fallingPorts[arrayPos];
	uint8_t trigger = risingTrigger | fallingTrigger;
	
	// save the new state for next comparison
	oldPorts[arrayPos] = newPort;
	
	// Execute all functions that should be triggered
	// This way we can exclude a single function and the calling is also much faster
	// We may also reorder the pins for different priority
#if !defined(PCINT_CALLBACK_PORT0)
	PCINT_CALLBACK(0, 0);
	PCINT_CALLBACK(1, 1);
	PCINT_CALLBACK(2, 2);
	PCINT_CALLBACK(3, 3);
	PCINT_CALLBACK(4, 4);
	PCINT_CALLBACK(5, 5);
	PCINT_CALLBACK(6, 6);
	PCINT_CALLBACK(7, 7);
#else
	PCINT_CALLBACK_PORT0
#endif
	
}

//============= PORT1 ===================================
#if (PCINT_USE_PORT1)
ISR(PCINT1_vect) {
	// get the new and old pin states for port
	uint8_t newPort = PCINT_INPUT_PORT1;

	// compare with the old value to detect a rising or falling
	uint8_t arrayPos = getArrayPosPCINT(1);
	uint8_t change = newPort ^ oldPorts[arrayPos];
	uint8_t rising = change & newPort;
	uint8_t falling = change & oldPorts[arrayPos];

	// check which pins are triggered, compared with the settings
	uint8_t risingTrigger = rising & risingPorts[arrayPos];
	uint8_t fallingTrigger = falling & fallingPorts[arrayPos];
	uint8_t trigger = risingTrigger | fallingTrigger;

	// save the new state for next comparison
	oldPorts[arrayPos] = newPort;

	// Execute all functions that should be triggered
	// This way we can exclude a single function
	// and the calling is also much faster
	// We may also reorder the pins for different priority
	#if !defined(PCINT_CALLBACK_PORT1)
	PCINT_CALLBACK(0, 8);
	PCINT_CALLBACK(1, 9);
	PCINT_CALLBACK(2, 10);
	PCINT_CALLBACK(3, 11);
	PCINT_CALLBACK(4, 12);
	PCINT_CALLBACK(5, 13);
	PCINT_CALLBACK(6, 14);
	PCINT_CALLBACK(7, 15);
	#else
	PCINT_CALLBACK_PORT1
	#endif
}
#endif
//============= PORT2 ===================================
#if (PCINT_USE_PORT2)
ISR(PCINT2_vect) {
	// get the new and old pin states for port
	uint8_t newPort = PCINT_INPUT_PORT2;

	// compare with the old value to detect a rising or falling
	uint8_t arrayPos = getArrayPosPCINT(2);
	uint8_t change = newPort ^ oldPorts[arrayPos];
	uint8_t rising = change & newPort;
	uint8_t falling = change & oldPorts[arrayPos];

	// check which pins are triggered, compared with the settings
	uint8_t risingTrigger = rising & risingPorts[arrayPos];
	uint8_t fallingTrigger = falling & fallingPorts[arrayPos];
	uint8_t trigger = risingTrigger | fallingTrigger;

	// save the new state for next comparison
	oldPorts[arrayPos] = newPort;

	// Execute all functions that should be triggered
	// This way we can exclude a single function
	// and the calling is also much faster
	// We may also reorder the pins for different priority
	#if !defined(PCINT_CALLBACK_PORT2)
	PCINT_CALLBACK(0, 16);
	PCINT_CALLBACK(1, 17);
	PCINT_CALLBACK(2, 18);
	PCINT_CALLBACK(3, 19);
	PCINT_CALLBACK(4, 20);
	PCINT_CALLBACK(5, 21);
	PCINT_CALLBACK(6, 22);
	PCINT_CALLBACK(7, 23);
	#else
	PCINT_CALLBACK_PORT2
	#endif
}
#endif



//============callbacks==============

#if (PCINT_USE_PCINT0 == true)
void PinChangeInterruptEventPCINT0(void) {
	callbackPCINT0();
}
#endif
#if (PCINT_USE_PCINT1 == true)
void PinChangeInterruptEventPCINT1(void) {
	callbackPCINT1();
}
#endif
#if (PCINT_USE_PCINT2 == true)
void PinChangeInterruptEventPCINT2(void) {
	callbackPCINT2();
}
#endif
#if (PCINT_USE_PCINT3 == true)
void PinChangeInterruptEventPCINT3(void) {
	callbackPCINT3();
}
#endif
#if (PCINT_USE_PCINT4 == true)
void PinChangeInterruptEventPCINT4(void) {
	callbackPCINT4();
}
#endif
#if (PCINT_USE_PCINT5 == true)
void PinChangeInterruptEventPCINT5(void) {
	callbackPCINT5();
}
#endif
#if (PCINT_USE_PCINT6 == true)
void PinChangeInterruptEventPCINT6(void) {
	callbackPCINT6();
}
#endif
#if (PCINT_USE_PCINT7 == true)
void PinChangeInterruptEventPCINT7(void) {
	callbackPCINT7();
}
#endif

#if (PCINT_USE_PCINT8 == true)
void PinChangeInterruptEventPCINT8(void) {
	callbackPCINT8();
}
#endif
#if (PCINT_USE_PCINT9 == true)
void PinChangeInterruptEventPCINT9(void) {
	callbackPCINT9();
}
#endif
#if (PCINT_USE_PCINT10 == true)
void PinChangeInterruptEventPCINT10(void) {
	callbackPCINT10();
}
#endif
#if (PCINT_USE_PCINT11 == true)
void PinChangeInterruptEventPCINT11(void) {
	callbackPCINT11();
}
#endif
#if (PCINT_USE_PCINT12 == true)
void PinChangeInterruptEventPCINT12(void) {
	callbackPCINT12();
}
#endif
#if (PCINT_USE_PCINT13 == true)
void PinChangeInterruptEventPCINT13(void) {
	callbackPCINT13();
}
#endif
#if (PCINT_USE_PCINT14 == true)
void PinChangeInterruptEventPCINT14(void) {
	callbackPCINT14();
}
#endif
#if (PCINT_USE_PCINT15 == true)
void PinChangeInterruptEventPCINT15(void) {
	callbackPCINT15();
}
#endif

#if (PCINT_USE_PCINT16 == true)
void PinChangeInterruptEventPCINT16(void) {
	callbackPCINT16();
}
#endif
#if (PCINT_USE_PCINT17 == true)
void PinChangeInterruptEventPCINT17(void) {
	callbackPCINT17();
}
#endif
#if (PCINT_USE_PCINT18 == true)
void PinChangeInterruptEventPCINT18(void) {
	callbackPCINT18();
}
#endif
#if (PCINT_USE_PCINT19 == true)
void PinChangeInterruptEventPCINT19(void) {
	callbackPCINT19();
}
#endif
#if (PCINT_USE_PCINT20 == true)
void PinChangeInterruptEventPCINT20(void) {
	callbackPCINT20();
}
#endif
#if (PCINT_USE_PCINT21 == true)
void PinChangeInterruptEventPCINT21(void) {
	callbackPCINT21();
}
#endif
#if (PCINT_USE_PCINT22 == true)
void PinChangeInterruptEventPCINT22(void) {
	callbackPCINT22();
}
#endif
#if (PCINT_USE_PCINT23 == true)
void PinChangeInterruptEventPCINT23(void) {
	callbackPCINT23();
}
#endif


#endif //PCINT_USE_PORT0