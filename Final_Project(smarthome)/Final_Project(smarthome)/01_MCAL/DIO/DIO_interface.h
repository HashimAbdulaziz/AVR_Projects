/* 
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   DIO_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * 
 *	Author: Hashim Abdulaziz Hashim
 *	Layer : MCALL
 *	SWC   : DIO/GPIO
 *
 */

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_



#define DIO_PIN_INPUT	0
#define DIO_PIN_OUTPUT	0xFF

#define  DIO_PORT_INPUT	 0
#define  DIO_PORT_OUTPUT 0xFF

#define  DIO_PIN_HIGH	1
#define  DIO_PIN_LOW	0


#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7


void DIO_voidSetPinDirection	(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Direction );
void DIO_voidSetPinValue		(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value		);
void DIO_u8GetPinValue			(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 *Copy_PtrData	);
void DIO_voidTogglePinValue		(u8 Copy_u8PORT, u8 Copy_u8PIN						);

void DIO_voidSetPortDirection	(u8 Copy_u8PORT, u8 Copy_u8Direction);
void DIO_voidSetPortValue		(u8 Copy_u8PORT, u8 Copy_u8Value	);
void DIO_u8GetPortValue			(u8 Copy_u8PORT, u8 *Copy_PtrData	);
void DIO_voidTogglePortValue	(u8 Copy_u8PORT						);











#endif
