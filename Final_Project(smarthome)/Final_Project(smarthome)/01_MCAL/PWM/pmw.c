/*********************************************************************************************************************************
/******************************************************    Author : Marwan    **********************************************
/******************************************************    Layer  : MCAL            **********************************************
/******************************************************    SWC    : TIMERS          **********************************************
/******************************************************    Version: 1.0             **********************************************/
#include "../../03_LIB/STD_TYPES.h"
#include "../../03_LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "pmw.h"


void PMW_voidInit()
{
	SET_BIT(SREG , SREG_I);
	TCNT0 = TIMERS_U8_PRELOAD_INITIAL_VALUE;
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);

/*Choose PWM Mode*/
 SET_BIT(TCCR0, TCCR0_WGM00);
 SET_BIT(TCCR0, TCCR0_WGM01);

/*Set OC0 on top Clear OC0 on Compare => Non Inverting*/
CLR_BIT(TCCR0, TCCR0_COM00);
SET_BIT(TCCR0, TCCR0_COM01);

OCR0=OCR0_valu_PWM;
#if   TIMER0_PRESCALER   ==  freq_8
CLR_BIT(TCCR0, TCCR0_CS00);
SET_BIT(TCCR0, TCCR0_CS01);
CLR_BIT(TCCR0, TCCR0_CS02);
#elif  TIMER0_PRESCALER   ==  freq_64
SET_BIT(TCCR0, TCCR0_CS00);
SET_BIT(TCCR0, TCCR0_CS01);
CLR_BIT(TCCR0, TCCR0_CS02);
#elif  TIMER0_PRESCALER   ==  freq_256
CLR_BIT(TCCR0, TCCR0_CS00);
CLR_BIT(TCCR0, TCCR0_CS01);
SET_BIT(TCCR0, TCCR0_CS02);
#elif  TIMER0_PRESCALER   ==  freq_1024
SET_BIT(TCCR0, TCCR0_CS00);
CLR_BIT(TCCR0, TCCR0_CS01);
SET_BIT(TCCR0, TCCR0_CS02);
#else
#error "wrong Prescaler config"
#endif

}


void PMW_voidSetDuty(u8 Copy_u8DutyCycle )
{

/*Check for mode in PWM*/
OCR0 = Copy_u8DutyCycle;  /*Sets OCR0 value*/
}