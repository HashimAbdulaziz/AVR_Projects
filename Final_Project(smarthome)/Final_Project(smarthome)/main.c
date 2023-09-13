/*
 * main.c
 *
 * Created: 9/12/2023 7:13:10 PM
 *  Author: Hashim Abdulaziz Hashim
 */ 

#include "App/App.h"

#include <xc.h>



int main(void)
{
	Init_peripherals();
	
    while(1)
    {
		if( Check_Password() )
			break;
		System_Locked();
    }
	
	Monitor_Options();
	
	while(1)
	{
		LED_OFF_ON();
		Conrol_Motor();
	}
}
