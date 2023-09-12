
#include "../../03_LIB/STD_TYPES.h"
#include "../../03_LIB/BIT_MATH.h"

#include "../../01_MCAL/DIO/DIO_interface.h"
#include "../../01_MCAL/DIO/DIO_private.h"

#include "LED_interface.h"





void LED_voidInit (LED_Type LED_Configuration)
{
	DIO_voidSetPinDirection(LED_Configuration.Port, LED_Configuration.Pin, DIO_PIN_OUTPUT);
}


void LED_voidOn (LED_Type LED_Configuration)
{
	if(LED_Configuration.Active_State == ACTIVE_HIGH)
	{
		DIO_voidSetPinValue(LED_Configuration.Port, LED_Configuration.Pin, DIO_PIN_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LED_Configuration.Port, LED_Configuration.Pin, DIO_PIN_LOW);
	}
}


void LED_voidOff (LED_Type LED_Configuration)
{
	if(LED_Configuration.Active_State == ACTIVE_HIGH)
	{
		DIO_voidSetPinValue(LED_Configuration.Port, LED_Configuration.Pin, DIO_PIN_LOW);
	}
	else
	{
		DIO_voidSetPinValue(LED_Configuration.Port, LED_Configuration.Pin, DIO_PIN_HIGH);
	}
}


void LED_voidToggle (LED_Type LED_Configuration)
{
	DIO_voidTogglePinValue(LED_Configuration.Port, LED_Configuration.Pin);
}