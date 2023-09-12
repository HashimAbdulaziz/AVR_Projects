/*
 * main.c
 *
 * Created: 9/12/2023 7:13:10 PM
 *  Author: HashimAbdulAzizHashi
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
	
	
	LED_OFF_ON();
	
	while(1)
	{
		Conrol_Motor();
	}
}