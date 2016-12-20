////////////////////////////////////////////////////////////////
// AVR GPIO LIBRARY
//
// NOVEMBER 30, 2016
//
// ANKIT BHATNAGAR
// ANKIT.BHATNAGARINDIA@GMAIL.COM
//
// REFERENCE:
// http://www.avrfreaks.net/forum/macros-ddr-and-port-pin-name
////////////////////////////////////////////////////////////////

#ifndef _AVR_GPIO_H_
#define _AVR_GPIO_H_

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/* INTERNAL FUNCTIONS / DEFINES */

#define BIT(p,b)							(b)

#define PORT(p,b)							(PORT ## p)
#define PIN(p,b)							(PIN ## p)
#define DDR(p,b)							(DDR ## p)

#define SET_PORT_BIT(p,b)					((p) |= (1 << b))
#define CLEAR_PORT_BIT(p,b)					((p) &= ~(1 << b))
#define TOGGLE_PORT_BIT(p,b)				((p) ^= (1 << b))

#define GET_PORT_BIT(p,b)					(((p) & (1 << b)) != 0)

/* USER CALLABLE DEFINES */
#define AVR_GPIO_EXTERNAL_INT_0	0
#define AVR_GPIO_EXTERNAL_INT_1	2

#define AVR_GPIO_EXTERNAL_INT_LOW_LEVEL		0
#define AVR_GPIO_EXTERNAL_INT_LOGIC_CHANGE	1
#define AVR_GPIO_EXTERNAL_INT_FALLING_EDGE	2
#define AVR_GPIO_EXTERNAL_INT_RISING_EDGE	3

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

/* USER CALLABLE DEFINES*/
void AVR_GPIO_External_Interrupt_Enable(uint8_t int_num, uint8_t int_trig_type);
void AVR_GPIO_External_Interrupt_Disable(uint8_t int_num);

#endif
