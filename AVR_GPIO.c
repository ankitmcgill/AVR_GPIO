//////////////////////////////////////////////
// AVR GPIO LIBRARY
//
// NOVEMBER 30, 2016
//
// ANKIT BHATNAGAR
// ANKIT.BHATNAGARINDIA@GMAIL.COM
//////////////////////////////////////////////

#include "AVR_GPIO.h"

void AVR_GPIO_pin_set_direction(uint8_t pin, uint8_t direction_register, uint8_t dir)
{
	//SET THE DIRECTION OF THE SPECIFIED PIN WITH THE SPECIFIED DIRECTION
	//REGISTER

	if(dir == AVR_GPIO_PIN_DIR_OUTPUT)
	{
		//OUTPUT
		direction_register |= (1 << pin);
	}
	else
	{
		//INPUT
		direction_register &= ~(1 << pin);
	}
}

void AVR_GPIO_pin_set_value(uint8_t pin, uint8_t value_register, uint8_t val)
{
	//SET THE VALUE OF THE PIN IN IT'S VALUE REGISTER
	//THIS MAY HAVE DIFFERENT EFFECTS DEPENDING ON IF THE PIN IS CONFIGURED
	//AS AN INPUT OR OUTPUT

	if(val == AVR_GPIO_PIN_VAL_HIGH)
	{
		value_register |= (1 << pin);
	}
	else
	{
		value_register &= ~(1 << pin);
	}
}

void AVR_GPIO_pin_toggle_value(uint8_t pin, uint8_t pin_register)
{
	//TOGGLE THE VALUE OF THE SPECIFIED PINS OUTPUT (IN THE PORT REGISTER)
	//FINAL EFFECT DEPENDS ON WEATHER THE PIN IS SPECIFIED AS INPUT OR OUTPUT

	pin_register |= (1 << pin);
}
