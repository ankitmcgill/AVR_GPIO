//////////////////////////////////////////////
// AVR GPIO LIBRARY
//
// NOVEMBER 30, 2016
//
// ANKIT BHATNAGAR
// ANKIT.BHATNAGARINDIA@GMAIL.COM
//////////////////////////////////////////////

#ifndef _AVR_GPIO_H_
#define _AVR_GPIO_H_

#include <stdio.h>
#include <avr/io.h>

/* INTERNAL FUNCTIONS / DEFINES */

#define BIT(p,b)							(b)

#define PORT(p,b)							(PORT ## p)
#define PIN(p,b)							(PIN ## p)
#define DDR(p,b)							(DDR ## p)

#define SET_PORT_BIT(p,b)					((p) |= (1 << b))
#define CLEAR_PORT_BIT(p,b)					((p) &= ~(1 << b))
#define TOGGLE_PORT_BIT(p,b)				((p) ^= (1 << b))

#define GET_PORT_BIT(p,b)					(((p) & (1 << b)) != 0)

/* USER CALLABLE FUNCTIONS / DEFINES */

#define AVR_GPIO_BIT(io)					BIT(io)
#define AVR_GPIO_PORT(io)					PORT(io)

#define AVR_GPIO_PIN_HIGH(io)				SET_PORT_BIT(PORT(io),BIT(io))
#define AVR_GPIO_PIN_LOW(io)				CLEAR_PORT_BIT(PORT(io),BIT(io))
#define AVR_GPIO_PIN_TOGGLE(io)				TOGGLE_PORT_BIT(PORT(io),BIT(io))

#define AVR_GPIO_PIN_GET_OUTPUT(io)			GET_PORT_BIT(PORT(io),BIT(io))
#define AVR_GPIO_PIN_GET_INPUT(io)			GET_PORT_BIT(PIN(io),BIT(io))

#define AVR_GPIO_PIN_SET_DIRECTION_IN(io)		CLEAR_PORT_BIT(DDR(io),BIT(io))
#define AVR_GPIO_PIN_SET_DIRECTION_OUT(io)		SET_PORT_BIT(DDR(io),BIT(io))
#define AVR_GPIO_PIN_SET_DIRECTION_TOGGLE(io)	TOGGLE_PORT_BIT(DDR(io),BIT(io))


#endif
