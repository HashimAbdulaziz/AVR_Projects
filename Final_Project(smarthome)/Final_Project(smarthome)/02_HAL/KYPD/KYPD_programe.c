#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../03_LIB/STD_TYPES.h"
#include "../../03_LIB/BIT_MATH.h"

#include "../../01_MCAL/DIO/DIO_private.h"
#include "../../01_MCAL/DIO/DIO_interface.h"
#include "../../01_MCAL/DIO/DIO_config.h"

#include "KYPD_interface.h"
#include "KYPD_config.h"




void KYPD_voidInt			(void)
{
	DIO_voidSetPinDirection(KYPD_ROW_PORT, KYPD_ROW_PIN0, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KYPD_ROW_PORT, KYPD_ROW_PIN1, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KYPD_ROW_PORT, KYPD_ROW_PIN2, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KYPD_ROW_PORT, KYPD_ROW_PIN3, DIO_PIN_INPUT);
	
	DIO_voidSetPortValue	(KYPD_ROW_PORT, 0x0F);   //>>>>>>  must be Set Higher Nibble of The PORt
	
	DIO_voidSetPinDirection(KYPD_COL_PORT, KYPD_COL_PIN0, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KYPD_COL_PORT, KYPD_COL_PIN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KYPD_COL_PORT, KYPD_COL_PIN2, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KYPD_COL_PORT, KYPD_COL_PIN3, DIO_PIN_OUTPUT);
	
	DIO_voidSetPortValue (KYPD_COL_PORT, 0xFF);
	
}





u8 KYPD_u8GetPressedKey	(void)
{
	u8 LOC_u8ROW_Val = 0;
	u8 LOC_u8COL_Val = 0;
	
	u8 KYPD_u8ROWPINArr [KYPD_NUM_ROWS] = {KYPD_ROW_PIN0, KYPD_ROW_PIN1, KYPD_ROW_PIN2, KYPD_ROW_PIN3}; 
	u8 KYPD_u8COLPINArr [KYPD_NUM_COLS] = {KYPD_COL_PIN0, KYPD_COL_PIN1, KYPD_COL_PIN2, KYPD_COL_PIN3}; 
	
	for(LOC_u8COL_Val = 0; LOC_u8COL_Val < KYPD_NUM_COLS; LOC_u8COL_Val++)
	{
		
		DIO_voidSetPinValue		(KYPD_COL_PORT, KYPD_u8COLPINArr[LOC_u8COL_Val], DIO_PIN_LOW);
		
		for(LOC_u8ROW_Val = 0; LOC_u8ROW_Val < KYPD_NUM_ROWS; LOC_u8ROW_Val++)
		{
			u8 u8Value = KYPD_BUTTON_RELEASED; 
			DIO_u8GetPinValue(KYPD_ROW_PORT, KYPD_u8ROWPINArr[LOC_u8ROW_Val], &u8Value);
			
			if(u8Value == KYPD_BUTTON_PRESSED)
			{
				_delay_ms(30);
				if(u8Value == KYPD_BUTTON_PRESSED)
				{
					while(u8Value == KYPD_BUTTON_PRESSED)
					{
						DIO_u8GetPinValue(KYPD_ROW_PORT, KYPD_u8ROWPINArr[LOC_u8ROW_Val], &u8Value); 
					}
					
					u8 KYPD_u8Value[KYPD_NUM_ROWS][KYPD_NUM_COLS] = KYPD_VALUES;
					
					return KYPD_u8Value[LOC_u8ROW_Val][LOC_u8COL_Val];
				}
			}
			
		}
		DIO_voidSetPinValue		(KYPD_COL_PORT, KYPD_u8COLPINArr[LOC_u8COL_Val], DIO_PIN_HIGH);
	}
	return KYPD_BUTTON_RELEASED;
}