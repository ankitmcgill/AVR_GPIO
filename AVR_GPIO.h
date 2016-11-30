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

#define AVR_GPIO_PIN_DIR_INPUT 	0
#define AVR_GPIO_PIN_DIR_OUTPUT 1

#define AVR_GPIO_PIN_VAL_HIGH 	1
#define AVR_GPIO_PIN_VAL_LOW 	0

#define AVR_GPIO_PORTB_DIR_REGISTER DDRB
#define AVR_GPIO_PORTC_DIR_REGISTER DDRC
#define AVR_GPIO_PORTD_DIR_REGISTER DDRD

#define AVR_GPIO_PORTB_VAL_REGISTER PORTB
#define AVR_GPIO_PORTC_VAL_REGISTER PORTC
#define AVR_GPIO_PORTD_VAL_REGISTER PORTD

#define AVR_GPIO_PORTB_PIN_REGISTER PINB
#define AVR_GPIO_PORTC_PIN_REGISTER PINC
#define AVR_GPIO_PORTD_PIN_REGISTER PIND

void AVR_GPIO_pin_set_direction(uint8_t pin, uint8_t direction_register, uint8_t dir);
void AVR_GPIO_pin_set_value(uint8_t pin, uint8_t value_register, uint8_t val);
void AVR_GPIO_pin_toggle_value(uint8_t pin, uint8_t pin_register);

#endif
