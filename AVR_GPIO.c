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

#include "AVR_GPIO.h"

void AVR_GPIO_External_Interrupt_Enable(uint8_t int_num, uint8_t int_trig_type)
{
	//ENABLE THE SPECIFIED EXTERNAL INTERRUPT AND SET THE 
	//TRIGGER TO THE SPECIFIED TYPE
	//
	//NOTE : ONLY ENABLES THE INTERRUPT. THE CORRESPONDING ISR NEEDS
	//TO BE WRITTEN BY THE USER IN APPLICATION CODE !

	#if defined(__AVR_ATmega8__)
	{
		MCUCR |= (int_trig_type << int_num);
		if(int_num == AVR_GPIO_EXTERNAL_INT_0)
		{
			SET_PORT_BIT(GICR, 6);
		}
		else if(int_num == AVR_GPIO_EXTERNAL_INT_1)
		{
			SET_PORT_BIT(GICR, 7);
		}
	}
	#endif

	#if defined(__AVR_ATmega88__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega328p__)
	{
		EICRA |= (int_trig_type << int_num);
		if(int_num == AVR_GPIO_EXTERNAL_INT_0)
		{
			SET_PORT_BIT(EIMSK, 0);
		}
		else if(int_num == AVR_GPIO_EXTERNAL_INT_1)
		{
			SET_PORT_BIT(EIMSK, 1);
		}
	}
	#endif
}

void AVR_GPIO_External_Interrupt_Disable(uint8_t int_num)
{
	//DISABLE THE SPECIFIED INTERRUPT TYPE

	#if defined(__AVR_ATmega8__)
	{
		if(int_num == AVR_GPIO_EXTERNAL_INT_0)
		{
			CLEAR_PORT_BIT(GICR, 6);
		}
		else if(int_num == AVR_GPIO_EXTERNAL_INT_1)
		{
			CLEAR_PORT_BIT(GICR, 7);
		}
	}
	#endif

	#if defined(__AVR_ATmega88__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega328p__)
	{



	}
	#endif
}
