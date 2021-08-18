/*
 * pinChangeInterrupts.h
 *
 * Created: 17/08/2021 14:36:04
 *  Author: OBED
 */ 
#include "tk2560.h"
#include "pinChangeInterruptPins.h"

#ifndef PINCHANGEINTERRUPTS_H_
#define PINCHANGEINTERRUPTS_H_

//================================================================================
// Suggested Settings
//================================================================================
/* Port1 is structured a bit more complicated
Disabling Port1 gives more speed and uses less flash
*/
// #if defined(PCINT_ENABLE_PORT1)
// #undef PCINT_ENABLE_PORT1 // better performance
// #endif

// definition used by the user to create custom LowLevel PCINT Events
#define PinChangeInterruptEvent_Wrapper(n) PinChangeInterruptEventPCINT ## n
#define PinChangeInterruptEvent(n) PinChangeInterruptEvent_Wrapper(n)

// alias for shorter writing
#define PCINTEvent(n) PinChangeInterruptEvent_Wrapper(n)
#define pinToPCINT pinToPinChangeInterrupt
#define attachPCINT attachPinChangeInterrupt
#define enablePCINT enablePinChangeInterrupt
#define detachPCINT detachPinChangeInterrupt
#define disablePCINT disablePinChangeInterrupt
#define getPCINTTrigger getPinChangeInterruptTrigger

//================================================================================
// Function Prototypes + Variables
//================================================================================

// typedef for our callback function pointers
typedef void(*callback)(void);

// useless function for weak implemented/not used functions
void pcint_null_callback(void);

void PinChangeInterruptEventPCINT0(void);
void PinChangeInterruptEventPCINT1(void);
void PinChangeInterruptEventPCINT2(void);
void PinChangeInterruptEventPCINT3(void);
void PinChangeInterruptEventPCINT4(void);
void PinChangeInterruptEventPCINT5(void);
void PinChangeInterruptEventPCINT6(void);
void PinChangeInterruptEventPCINT7(void);
void PinChangeInterruptEventPCINT8(void);
void PinChangeInterruptEventPCINT9(void);
void PinChangeInterruptEventPCINT10(void);
void PinChangeInterruptEventPCINT11(void);
void PinChangeInterruptEventPCINT12(void);
void PinChangeInterruptEventPCINT13(void);
void PinChangeInterruptEventPCINT14(void);
void PinChangeInterruptEventPCINT15(void);
void PinChangeInterruptEventPCINT16(void);
void PinChangeInterruptEventPCINT17(void);
void PinChangeInterruptEventPCINT18(void);
void PinChangeInterruptEventPCINT19(void);
void PinChangeInterruptEventPCINT20(void);
void PinChangeInterruptEventPCINT21(void);
void PinChangeInterruptEventPCINT22(void);
void PinChangeInterruptEventPCINT23(void);


extern uint8_t oldPorts[PCINT_NUM_USED_PORTS];
extern uint8_t fallingPorts[PCINT_NUM_USED_PORTS];
extern uint8_t risingPorts[PCINT_NUM_USED_PORTS];

static inline uint8_t getArrayPosPCINT(uint8_t pcintPort) __attribute__((always_inline));
uint8_t getArrayPosPCINT(uint8_t pcintPort) {
	/*
	Maps the port to the array.
	This is needed since you can deactivate ports and the array will dynamically resize to save ram.

	The function does not need that much flash since the if and else are known at compile time, 
	so the compiler removes all the complex logic.
	The return is is the input if all pins are activated for example.
	That's why the function is inline.
	*/
	if (PCINT_NUM_USED_PORTS == 1){
		return 0; // only the first element is used for a single port
	}else if (PCINT_NUM_USED_PORTS == PCINT_NUM_PORTS){
		// use all ports and down remap the array position.
		return pcintPort;
	}else if(PCINT_NUM_PORTS - PCINT_NUM_USED_PORTS == 1){
		// one port is not used
		if(PCINT_USE_PORT0 == 0){
			// first port is not used, decrease all port numbers
			return (pcintPort - 1);
		}else{
			// 3 ports (standard)
			if (PCINT_USE_PORT2 == 0) {
				// last port not used, no mapping needed
				return pcintPort;
			}else {
				// worst case, port in the middle not used, remap
				return ((pcintPort >> 1) & 0x01);
			}
		}
	}else if(PCINT_NUM_PORTS - PCINT_NUM_USED_PORTS == 2){
		if (PCINT_USE_PORT2 == 0 ) {
			// no need for mapping
			return pcintPort;
		}
		else if (PCINT_USE_PORT0 == 0) {
			// 1 offset
			return (pcintPort - 1);
		}
		else if (PCINT_USE_PORT0 == 0 && PCINT_USE_PORT1 == 0) {
			// 2 offset
			return (pcintPort - 2);
		}
		else if (PCINT_USE_PORT0 == 0 && PCINT_USE_PORT2 == 0) {
			// 2 -> 1
			return (pcintPort >> 1);
		}
		else if (PCINT_USE_PORT1 == 0) {
			// 3 -> 1, 1 -> 0
			return (pcintPort >> 1);
		}
	}
	//error
	return 0;
}

//================================================================================
// Attach Function
//================================================================================
void enablePinChangeInterruptHelper(const uint8_t pcintPort, const uint8_t pcintMask, const uint8_t arrayPos);
void attachPinChangeInterrupt(const uint8_t pcintNum, void(*userFunc)(void), const uint8_t mode);

//================================================================================
// Detach Function
//================================================================================
void disablePinChangeInterruptHelper(const uint8_t pcintPort, const uint8_t pcintMask);
void detachPinChangeInterrupt(const uint8_t pcintNum);


static inline void disablePinChangeInterrupt(const uint8_t pcintNum) __attribute__((always_inline));
void disablePinChangeInterrupt(const uint8_t pcintNum) {
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

	// get bitmask
	uint8_t pcintMask = (1 << pcintBit);

	// Do not delete mode settings nor detach the user function
	// Just turn off interrupts

	// call the actual hardware disable function
	disablePinChangeInterruptHelper(pcintPort, pcintMask);
}

//================================================================================
// getTrigger Function (inlined)
//================================================================================
static inline uint8_t getPinChangeInterruptTrigger(const uint8_t pcintNum) __attribute__((always_inline));
uint8_t getPinChangeInterruptTrigger(const uint8_t pcintNum) {
	// get PCINT registers
	uint8_t pcintPort = pcintNum / 8;
	uint8_t pcintBit = pcintNum % 8;

	// check if pcint is a valid pcint, exclude deactivated ports
	if (pcintPort == 0) {
		if (PCINT_USE_PORT0 == false)
			return CHANGE;
	}
	else if (pcintPort == 1) {
		if (PCINT_USE_PORT1 == false)
			return CHANGE;
	}
	else if (pcintPort == 2) {
		if (PCINT_USE_PORT2 == false)
			return CHANGE;
	}
	else return CHANGE;

	uint8_t arrayPos = getArrayPosPCINT(pcintPort);

	// Check if no mode was set, return an error
	if(!(risingPorts[arrayPos] & (1 << pcintBit)) && !(fallingPorts[arrayPos] & (1 << pcintBit)))
		return CHANGE;

	// specify the CHANGE mode
	if (oldPorts[arrayPos] & (1 << pcintBit))
		return RISING;
	else
		return FALLING;
}

#endif /* PINCHANGEINTERRUPTS_H_ */