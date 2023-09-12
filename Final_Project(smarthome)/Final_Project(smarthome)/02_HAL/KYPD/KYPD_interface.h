/* 
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   KYPD_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * 
 *	Author: Hashim Abdulaziz Hashim
 *	Layer : HAL
 *	SWC   : KYPD
 *
 */

#ifndef _KYPD_INTERFACE_H_
#define _KYPD_INTERFACE_H_

#define KYPD_BUTTON_PRESSED			DIO_PIN_LOW
#define KYPD_BUTTON_RELEASED		DIO_PIN_HIGH



void KYPD_voidInt			(void);
u8 KYPD_u8GetPressedKey	(void);





#endif
