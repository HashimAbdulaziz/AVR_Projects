/*
 * App.h
 *
 * Created: 9/7/2023 10:08:52 PM
 *  Author: Marwan
 */ 
#include "../03_LIB/STD_TYPES.h"


#ifndef APP_H_
#define APP_H_

void Init_peripherals(void);
u8 Check_Password(void);
void System_Locked(void);
void LED_OFF_ON(void);
void Conrol_Motor(void);

#endif /* APP_H_ */