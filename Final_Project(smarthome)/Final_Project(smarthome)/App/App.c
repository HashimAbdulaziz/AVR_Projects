/*
 * App.c
 *
 * Created: 9/7/2023 10:08:39 PM
 *  Author: Hashim Abdulaziz Hashim
 */ 
#include <util/delay.h>

#include "../03_LIB/BIT_MATH.h"
#include "../03_LIB/STD_TYPES.h"

#include "../01_MCAL/ADC/ADC_interface.h"
#include "../01_MCAL/ADC/ADC_config.h"
#include "../01_MCAL/PWM/pmw.h"
#include "../01_MCAL/DIO/DIO_interface.h"

#include "../02_HAL/LED/LED_interface.h"
#include "../02_HAL/LED/LED_config.h"
#include "../02_HAL/CLCD/CLCD_interface.h"
#include "../02_HAL/CLCD/CLCD_config.h"
#include "../02_HAL/KYPD/KYPD_interface.h"
#include "../02_HAL/KYPD/KYPD_config.h"
#include "../02_HAL/LM35/LM35_interface.h"
#include "../02_HAL/LM35/LM35_config.h"

#include "App.h"

u8 pass[11] = {'9', '5', '1', '7', '5', '3', '6', '4', '8', '2', '0'};  // Main Password
u8 pass_copy[11] = {0};
u8 try = 1;		// number of tries until system lock
u16 Temp = 0;

/* Initialize LED*/
LED_Type LED1 = {LED_PORTC, LED_PIN4, ACTIVE_HIGH};

/* Initialize LM35:  Vref = 5v*/
LM35_CONFIG lm35 = {ADC_CHANNEL, 5, ADC_RESOLUTION_10_BIT};



void Init_peripherals(void)
{
		CLCD_voidInit();
		KYPD_voidInt();
		
		ADC_voidInit();
		ADC_voidEnable();
		
		PMW_voidInit();
		
		LED_voidInit(LED1);
		
		DIO_voidSetPinDirection(DIO_PORTC, DIO_PIN0, DIO_PIN_OUTPUT);
		DIO_voidSetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_HIGH);
		DIO_voidSetPinDirection(DIO_PORTC, DIO_PIN1, DIO_PIN_OUTPUT);
		DIO_voidSetPinValue(DIO_PORTC, DIO_PIN1, DIO_PIN_LOW);
}



void System_Locked(void)
{
	try++;
	if(try > 3)
	{
		try = 1;
		CLCD_voidClearScreen();
		CLCD_voidSendString("System is locked");
		CLCD_voidSetPosition(2, 1);
		CLCD_voidSendString("for 2 minutes");
		_delay_ms(120000);
	}
	if(try != 1)
	{
		CLCD_voidClearScreen();
		CLCD_voidSendString("wrong password,");
		CLCD_voidSetPosition(2, 1);
		CLCD_voidSendString("please Try again");
	}
}


void Monitor_Options(void)
{
	CLCD_voidClearScreen();
	CLCD_voidSendString("Welcome Mesho");
	_delay_ms(600);
	CLCD_voidClearScreen();
	
	CLCD_voidSendString("1-Led ON Temp: ");
	CLCD_voidSetPosition(2, 1);
	CLCD_voidSendString("2-Led OFF");
}


void LED_OFF_ON(void)
{	
	u8 val = KYPD_BUTTON_RELEASED;
	val = KYPD_u8GetPressedKey();
	if(val == '1')
		LED_voidOn(LED1);
	else if(val == '2')
		LED_voidOff(LED1);
}



u8 Check_Password(void)
{
	if(try == 1)
	{
		CLCD_voidClearScreen();
		CLCD_voidSendString("Please Enter");
		CLCD_voidSetPosition(2, 1);
		CLCD_voidSendString("Password");
	}
	u8 cont = 0;
	while(cont < 11)
	{
		u8 val = KYPD_BUTTON_RELEASED;
		while(val == KYPD_BUTTON_RELEASED)
		{
			val = KYPD_u8GetPressedKey();
		}
		if(cont == 0)
		CLCD_voidClearScreen();
		
		CLCD_voidSendData('*');
		pass_copy[cont] = val;
		cont++;
	}
	
	for(u8 indx = 0; indx < 11; indx++)
	{
		if(pass[indx] != pass_copy[indx])
		{
			return 0;
		}
	}
	return 1;
}



void Conrol_Motor(void)
{
	LM35_u8GetTemp(&lm35, &Temp);
	
	CLCD_voidSetPosition(1, 15);
	CLCD_voidSendNumber(Temp);
	if(Temp<=25)
	{
		PMW_voidSetDuty(0);
	}
	else if (Temp>25 && Temp<30)
	{
		PMW_voidSetDuty(127);
	}
	else
	{
		PMW_voidSetDuty(255);
	}
	_delay_ms(200);
}


