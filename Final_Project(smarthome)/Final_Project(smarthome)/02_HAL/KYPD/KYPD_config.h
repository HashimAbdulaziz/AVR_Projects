/* 
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   KYPD_config.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * 
 *	Author: Hashim Abdulaziz Hashim
 *	Layer : HAL
 *	SWC   : KYPD
 *
 */

#ifndef _KYPD_CONFIG_H_
#define _KYPD_CONFIG_H_


/*	KYPD dimensions */ 
#define  KYPD_NUM_COLS	4
#define	 KYPD_NUM_ROWS	4


#define KYPD_ROW_PORT			 DIO_PORTA
#define KYPD_ROW_PIN0			 DIO_PIN0
#define KYPD_ROW_PIN1			 DIO_PIN1
#define KYPD_ROW_PIN2			 DIO_PIN2
#define KYPD_ROW_PIN3			 DIO_PIN3

#define KYPD_COL_PORT			 DIO_PORTB
#define KYPD_COL_PIN0			 DIO_PIN4
#define KYPD_COL_PIN1			 DIO_PIN5
#define KYPD_COL_PIN2			 DIO_PIN6
#define KYPD_COL_PIN3			 DIO_PIN7




/*Define the keypad values*/
#define KYPD_VALUES     {{'7','8','9','/'},\
						{'4','5','6','*'},\
						{'1','2','3','-'},\
						{'c','0','=','+'}}




#endif
