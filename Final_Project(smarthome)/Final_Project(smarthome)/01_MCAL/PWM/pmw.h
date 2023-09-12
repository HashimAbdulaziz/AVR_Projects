/**************************************************************************************************************************
/******************************************************    Author : Marwan    **********************************************
/******************************************************    Layer  : MCAL     **********************************************
/******************************************************    SWC    : TIMERS   **********************************************
/******************************************************    Version: 1.0      **********************************************/
#include "../../03_LIB/STD_TYPES.h"

#ifndef PMW_H
#define PMW_H

#define SREG  *((volatile u8*)0x5F) //status register----------------global interupt enable
#define SREG_I    7



#define TCCR0          *((volatile u8*)0x53)  /**/
#define TCCR0_WGM00          6                /**/
#define TCCR0_WGM01          3                /**/
#define TCCR0_CS02           2                /**/
#define TCCR0_CS01           1                /**/
#define TCCR0_CS00           0                /**/
#define TCCR0_COM00          4                /**/
#define TCCR0_COM01          5                /**/

#define OCR0           *((volatile u8*)0x5C)   /**/

#define TIMSK          *((volatile u8*)0x59)   /**/
#define TIMSK_OCIE          1                  /**/
#define TIMSK_TOIE          0                  /**/

#define  TCNT0           *((volatile u8*)0x52) /**/


#define  OCR0_valu_PWM   0
#define TIMERS_U8_NORMAL_NO_OF_OVF					114
#define TIMERS_U8_PRELOAD_INITIAL_VALUE				0




/**/
//#define  TIMER0_SET_CTC_INITIAL_VALUE


/**/
#define TIMER0_PRESCALER   freq_8
#define	freq_256			256
#define freq_64             64
#define freq_1024           1024
#define freq_8              8




void PMW_voidInit();

void PMW_voidSetDuty(u8 Copy_u8DutyCycle);

#endif