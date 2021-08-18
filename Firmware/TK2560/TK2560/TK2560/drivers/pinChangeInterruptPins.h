/*
 * pinChangeInterruptPins.h
 *
 * Created: 18/08/2021 12:30:44
 *  Author: OBED
 */ 

#ifndef PINCHANGEINTERRUPTPINS_H_
#define PINCHANGEINTERRUPTPINS_H_

//================================================================================
// Board Definitions
//================================================================================
//For ATMega2560 Ports
#define PCINT_INPUT_PORT0	PINB //0-7//8 is on PE0
#define PCINT_INPUT_PORT1	((PINE & 0x01) | (PINJ << 1)) //PINJ //9-15
#define PCINT_INPUT_PORT2	PINK //16-23

#define PCINT_ENABLE_PORT0
#define PCINT_ENABLE_PORT1
#define PCINT_ENABLE_PORT2

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
#define PCINT_ENABLE_PCINT24
#define PCINT_ENABLE_PCINT25
#define PCINT_ENABLE_PCINT26
#define PCINT_ENABLE_PCINT27
#define PCINT_ENABLE_PCINT28
#define PCINT_ENABLE_PCINT29
#define PCINT_ENABLE_PCINT30
#define PCINT_ENABLE_PCINT31

//================================================================================
// Enabled Pins
//================================================================================
#if !defined(PCINT_ENABLE_PORT0)
#if defined(PCINT_ENABLE_PCINT0)
#undef PCINT_ENABLE_PCINT0
#endif
#if defined(PCINT_ENABLE_PCINT1)
#undef PCINT_ENABLE_PCINT1
#endif
#if defined(PCINT_ENABLE_PCINT2)
#undef PCINT_ENABLE_PCINT2
#endif
#if defined(PCINT_ENABLE_PCINT3)
#undef PCINT_ENABLE_PCINT3
#endif
#if defined(PCINT_ENABLE_PCINT4)
#undef PCINT_ENABLE_PCINT4
#endif
#if defined(PCINT_ENABLE_PCINT5)
#undef PCINT_ENABLE_PCINT5
#endif
#if defined(PCINT_ENABLE_PCINT6)
#undef PCINT_ENABLE_PCINT6
#endif
#if defined(PCINT_ENABLE_PCINT7)
#undef PCINT_ENABLE_PCINT7
#endif
#endif

#if !defined(PCINT_ENABLE_PORT1)
#if defined(PCINT_ENABLE_PCINT8)
#undef PCINT_ENABLE_PCINT8
#endif
#if defined(PCINT_ENABLE_PCINT9)
#undef PCINT_ENABLE_PCINT9
#endif
#if defined(PCINT_ENABLE_PCINT10)
#undef PCINT_ENABLE_PCINT10
#endif
#if defined(PCINT_ENABLE_PCINT11)
#undef PCINT_ENABLE_PCINT11
#endif
#if defined(PCINT_ENABLE_PCINT12)
#undef PCINT_ENABLE_PCINT12
#endif
#if defined(PCINT_ENABLE_PCINT13)
#undef PCINT_ENABLE_PCINT13
#endif
#if defined(PCINT_ENABLE_PCINT14)
#undef PCINT_ENABLE_PCINT14
#endif
#if defined(PCINT_ENABLE_PCINT15)
#undef PCINT_ENABLE_PCINT15
#endif
#endif

#if !defined(PCINT_ENABLE_PORT2)
#if defined(PCINT_ENABLE_PCINT16)
#undef PCINT_ENABLE_PCINT16
#endif
#if defined(PCINT_ENABLE_PCINT17)
#undef PCINT_ENABLE_PCINT17
#endif
#if defined(PCINT_ENABLE_PCINT18)
#undef PCINT_ENABLE_PCINT18
#endif
#if defined(PCINT_ENABLE_PCINT19)
#undef PCINT_ENABLE_PCINT19
#endif
#if defined(PCINT_ENABLE_PCINT20)
#undef PCINT_ENABLE_PCINT20
#endif
#if defined(PCINT_ENABLE_PCINT21)
#undef PCINT_ENABLE_PCINT21
#endif
#if defined(PCINT_ENABLE_PCINT22)
#undef PCINT_ENABLE_PCINT22
#endif
#if defined(PCINT_ENABLE_PCINT23)
#undef PCINT_ENABLE_PCINT23
#endif
#endif

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

// add fakes if ports are not used
#ifndef PCINT_INPUT_PORT0
#define PCINT_INPUT_PORT0 0
#else
#define PCINT_INPUT_PORT0_USED
#endif
#ifndef PCINT_INPUT_PORT1
#define PCINT_INPUT_PORT1 0
#else
#define PCINT_INPUT_PORT1_USED
#endif
#ifndef PCINT_INPUT_PORT2
#define PCINT_INPUT_PORT2 0
#else
#define PCINT_INPUT_PORT2_USED
#endif


#endif /* PINCHANGEINTERRUPTPINS_H_ */