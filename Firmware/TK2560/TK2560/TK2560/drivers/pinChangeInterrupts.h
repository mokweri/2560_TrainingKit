/*
 * pinChangeInterrupts.h
 *
 * Created: 17/08/2021 14:36:04
 *  Author: OBED
 */ 
#include "tk2560.h"

#ifndef PINCHANGEINTERRUPTS_H_
#define PINCHANGEINTERRUPTS_H_


//For ATMega2560 Ports
#define PCINT_INPUT_PORT0	PINB //0-7//8 is on PE0
#define PCINT_INPUT_PORT1	((PINE & 0x01) | (PINJ << 1)) //PINJ //9-15
#define PCINT_INPUT_PORT2	PINK //16-23

#define PCINT_ENABLE_PORT0
#define PCINT_ENABLE_PORT1
#define PCINT_ENABLE_PORT2
/* Port1 is structured a bit more complicated
Disabling Port1 gives more speed and uses less flash
*/
#if defined(PCINT_ENABLE_PORT1)
#undef PCINT_ENABLE_PORT1 // better performance
#endif

//================================================================================
// Enabled Pins
//================================================================================
#define PCINT_ENABLE_PCINT0
#define PCINT_ENABLE_PCINT1
#define PCINT_ENABLE_PCINT2
#define PCINT_ENABLE_PCINT3
#define PCINT_ENABLE_PCINT4
#define PCINT_ENABLE_PCINT5
#define PCINT_ENABLE_PCINT6
#define PCINT_ENABLE_PCINT7
#define PCINT_ENABLE_PCINT8
#define PCINT_ENABLE_PCINT9
#define PCINT_ENABLE_PCINT10
#define PCINT_ENABLE_PCINT11
#define PCINT_ENABLE_PCINT12
#define PCINT_ENABLE_PCINT13
#define PCINT_ENABLE_PCINT14
#define PCINT_ENABLE_PCINT15
#define PCINT_ENABLE_PCINT16
#define PCINT_ENABLE_PCINT17
#define PCINT_ENABLE_PCINT18
#define PCINT_ENABLE_PCINT19
#define PCINT_ENABLE_PCINT20
#define PCINT_ENABLE_PCINT21
#define PCINT_ENABLE_PCINT22
#define PCINT_ENABLE_PCINT23

//================================================================================
// Hardware Definitions
//================================================================================
#define PCINT_HAS_PORT0 true
#define PCINT_HAS_PORT1 true
#define PCINT_HAS_PORT2 true

// number of available ports
#define PCINT_NUM_PORTS ( \
PCINT_HAS_PORT0 + \
PCINT_HAS_PORT1 + \
PCINT_HAS_PORT2)

#define PCINT_HAS_PCINT0	true
#define PCINT_HAS_PCINT1	true
#define PCINT_HAS_PCINT2	true
#define PCINT_HAS_PCINT3	true
#define PCINT_HAS_PCINT4	true
#define PCINT_HAS_PCINT5	true
#define PCINT_HAS_PCINT6	true
#define PCINT_HAS_PCINT7	true
#define PCINT_HAS_PCINT8	true
#define PCINT_HAS_PCINT9	true
#define PCINT_HAS_PCINT10	true
#define PCINT_HAS_PCINT11	true
#define PCINT_HAS_PCINT12	true
#define PCINT_HAS_PCINT13	true
#define PCINT_HAS_PCINT14	true
#define PCINT_HAS_PCINT15	true
#define PCINT_HAS_PCINT16	true
#define PCINT_HAS_PCINT17	true
#define PCINT_HAS_PCINT18	true
#define PCINT_HAS_PCINT19	true
#define PCINT_HAS_PCINT20	true
#define PCINT_HAS_PCINT21	true
#define PCINT_HAS_PCINT22	true
#define PCINT_HAS_PCINT23	true

// count numbers of available pins on each port
#define PCINT_NUM_PINS_PORT0 ( \
PCINT_HAS_PCINT0 + \
PCINT_HAS_PCINT1 + \
PCINT_HAS_PCINT2 + \
PCINT_HAS_PCINT3 + \
PCINT_HAS_PCINT4 + \
PCINT_HAS_PCINT5 + \
PCINT_HAS_PCINT6 + \
PCINT_HAS_PCINT7)

#define PCINT_NUM_PINS_PORT1 ( \
PCINT_HAS_PCINT8 + \
PCINT_HAS_PCINT9 + \
PCINT_HAS_PCINT10 + \
PCINT_HAS_PCINT11 + \
PCINT_HAS_PCINT12 + \
PCINT_HAS_PCINT13 + \
PCINT_HAS_PCINT14 + \
PCINT_HAS_PCINT15)

#define PCINT_NUM_PINS_PORT2 ( \
PCINT_HAS_PCINT16 + \
PCINT_HAS_PCINT17 + \
PCINT_HAS_PCINT18 + \
PCINT_HAS_PCINT19 + \
PCINT_HAS_PCINT20 + \
PCINT_HAS_PCINT21 + \
PCINT_HAS_PCINT22 + \
PCINT_HAS_PCINT23)

// number of available hardware pins
#define EXTERNAL_NUM_PINCHANGEINTERRUPT ( \
PCINT_NUM_PINS_PORT0 + \
PCINT_NUM_PINS_PORT1 + \
PCINT_NUM_PINS_PORT2)

//================================================================================
// Used Pins
//================================================================================
// check if pins are physically available and enabled

#if (PCINT_HAS_PCINT0 == true) && defined(PCINT_ENABLE_PCINT0)
#define PCINT_USE_PCINT0 true
#else
#define PCINT_USE_PCINT0 false
#endif
#if (PCINT_HAS_PCINT1 == true) && defined(PCINT_ENABLE_PCINT1)
#define PCINT_USE_PCINT1 true
#else
#define PCINT_USE_PCINT1 false
#endif
#if (PCINT_HAS_PCINT2 == true) && defined(PCINT_ENABLE_PCINT2)
#define PCINT_USE_PCINT2 true
#else
#define PCINT_USE_PCINT2 false
#endif
#if (PCINT_HAS_PCINT3 == true) && defined(PCINT_ENABLE_PCINT3)
#define PCINT_USE_PCINT3 true
#else
#define PCINT_USE_PCINT3 false
#endif
#if (PCINT_HAS_PCINT4 == true) && defined(PCINT_ENABLE_PCINT4)
#define PCINT_USE_PCINT4 true
#else
#define PCINT_USE_PCINT4 false
#endif
#if (PCINT_HAS_PCINT5 == true) && defined(PCINT_ENABLE_PCINT5)
#define PCINT_USE_PCINT5 true
#else
#define PCINT_USE_PCINT5 false
#endif
#if (PCINT_HAS_PCINT6 == true) && defined(PCINT_ENABLE_PCINT6)
#define PCINT_USE_PCINT6 true
#else
#define PCINT_USE_PCINT6 false
#endif
#if (PCINT_HAS_PCINT7 == true) && defined(PCINT_ENABLE_PCINT7)
#define PCINT_USE_PCINT7 true
#else
#define PCINT_USE_PCINT7 false
#endif
#if (PCINT_HAS_PCINT8 == true) && defined(PCINT_ENABLE_PCINT8)
#define PCINT_USE_PCINT8 true
#else
#define PCINT_USE_PCINT8 false
#endif
#if (PCINT_HAS_PCINT9 == true) && defined(PCINT_ENABLE_PCINT9)
#define PCINT_USE_PCINT9 true
#else
#define PCINT_USE_PCINT9 false
#endif
#if (PCINT_HAS_PCINT10 == true) && defined(PCINT_ENABLE_PCINT10)
#define PCINT_USE_PCINT10 true
#else
#define PCINT_USE_PCINT10 false
#endif
#if (PCINT_HAS_PCINT11 == true) && defined(PCINT_ENABLE_PCINT11)
#define PCINT_USE_PCINT11 true
#else
#define PCINT_USE_PCINT11 false
#endif
#if (PCINT_HAS_PCINT12 == true) && defined(PCINT_ENABLE_PCINT12)
#define PCINT_USE_PCINT12 true
#else
#define PCINT_USE_PCINT12 false
#endif
#if (PCINT_HAS_PCINT13 == true) && defined(PCINT_ENABLE_PCINT13)
#define PCINT_USE_PCINT13 true
#else
#define PCINT_USE_PCINT13 false
#endif
#if (PCINT_HAS_PCINT14 == true) && defined(PCINT_ENABLE_PCINT14)
#define PCINT_USE_PCINT14 true
#else
#define PCINT_USE_PCINT14 false
#endif
#if (PCINT_HAS_PCINT15 == true) && defined(PCINT_ENABLE_PCINT15)
#define PCINT_USE_PCINT15 true
#else
#define PCINT_USE_PCINT15 false
#endif
#if (PCINT_HAS_PCINT16 == true) && defined(PCINT_ENABLE_PCINT16)
#define PCINT_USE_PCINT16 true
#else
#define PCINT_USE_PCINT16 false
#endif
#if (PCINT_HAS_PCINT17 == true) && defined(PCINT_ENABLE_PCINT17)
#define PCINT_USE_PCINT17 true
#else
#define PCINT_USE_PCINT17 false
#endif
#if (PCINT_HAS_PCINT18 == true) && defined(PCINT_ENABLE_PCINT18)
#define PCINT_USE_PCINT18 true
#else
#define PCINT_USE_PCINT18 false
#endif
#if (PCINT_HAS_PCINT19 == true) && defined(PCINT_ENABLE_PCINT19)
#define PCINT_USE_PCINT19 true
#else
#define PCINT_USE_PCINT19 false
#endif
#if (PCINT_HAS_PCINT20 == true) && defined(PCINT_ENABLE_PCINT20)
#define PCINT_USE_PCINT20 true
#else
#define PCINT_USE_PCINT20 false
#endif
#if (PCINT_HAS_PCINT21 == true) && defined(PCINT_ENABLE_PCINT21)
#define PCINT_USE_PCINT21 true
#else
#define PCINT_USE_PCINT21 false
#endif
#if (PCINT_HAS_PCINT22 == true) && defined(PCINT_ENABLE_PCINT22)
#define PCINT_USE_PCINT22 true
#else
#define PCINT_USE_PCINT22 false
#endif
#if (PCINT_HAS_PCINT23 == true) && defined(PCINT_ENABLE_PCINT23)
#define PCINT_USE_PCINT23 true
#else
#define PCINT_USE_PCINT23 false
#endif


//================================================================================
// Number Used Pins
//================================================================================
#define PCINT_NUM_USED_PINS_PORT0 ( \
PCINT_USE_PCINT0 + \
PCINT_USE_PCINT1 + \
PCINT_USE_PCINT2 + \
PCINT_USE_PCINT3 + \
PCINT_USE_PCINT4 + \
PCINT_USE_PCINT5 + \
PCINT_USE_PCINT6 + \
PCINT_USE_PCINT7)

#define PCINT_NUM_USED_PINS_PORT1 ( \
PCINT_USE_PCINT8 + \
PCINT_USE_PCINT9 + \
PCINT_USE_PCINT10 + \
PCINT_USE_PCINT11 + \
PCINT_USE_PCINT12 + \
PCINT_USE_PCINT13 + \
PCINT_USE_PCINT14 + \
PCINT_USE_PCINT15)

#define PCINT_NUM_USED_PINS_PORT2 ( \
PCINT_USE_PCINT16 + \
PCINT_USE_PCINT17 + \
PCINT_USE_PCINT18 + \
PCINT_USE_PCINT19 + \
PCINT_USE_PCINT20 + \
PCINT_USE_PCINT21 + \
PCINT_USE_PCINT22 + \
PCINT_USE_PCINT23)

// number of used hardware pins
#define EXTERNAL_NUM_USED_PINCHANGEINTERRUPT ( \
PCINT_NUM_USED_PINS_PORT0 + \
PCINT_NUM_USED_PINS_PORT1 + \
PCINT_NUM_USED_PINS_PORT2)

//================================================================================
// Used Ports
//================================================================================
// check if ports are used
#if PCINT_NUM_USED_PINS_PORT0
#define PCINT_USE_PORT0 true
#else
#define PCINT_USE_PORT0 false
#endif
#if PCINT_NUM_USED_PINS_PORT1
#define PCINT_USE_PORT1 true
#else
#define PCINT_USE_PORT1 false
#endif
#if PCINT_NUM_USED_PINS_PORT2
#define PCINT_USE_PORT2 true
#else
#define PCINT_USE_PORT2 false
#endif


// number of used ports
#define PCINT_NUM_USED_PORTS ( \
PCINT_USE_PORT0 + \
PCINT_USE_PORT1 + \
PCINT_USE_PORT2)

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

// definition used by the user to create custom LowLevel PCINT Events
#define PinChangeInterruptEvent_Wrapper(n) PinChangeInterruptEventPCINT ## n
#define PinChangeInterruptEvent(n) PinChangeInterruptEvent_Wrapper(n)

// alias for shorter writing
#define PCINTEvent(n) PinChangeInterruptEvent_Wrapper(n)
#define digitalPinToPCINT digitalPinToPinChangeInterrupt
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

#endif /* PINCHANGEINTERRUPTS_H_ */