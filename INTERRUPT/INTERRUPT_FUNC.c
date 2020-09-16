/*
 * INTERRUPT_FUNC.c
 *
 *  Created on: Oct 7, 2019
 *      Author: shady
 *
 *
 *      Description :
 *      using Call back Functions ISR will call the function to be executed when interrupt happens
 *       from the APP layer using pointers to functions and
 *      SET_INT_VEC_TO_ISR(interrupt vector name , function name -address first statement in the function-)
 */

#include"STD_TYPES.h"

#include"INTERRUPT_PRIV.h"
#include"INTERRUPT_INT.h"




/*Pointers to Interrupt vectors functions*/
static void (* EXT_INT[3])		(void) = {NULL,NULL,NULL};
static void (* TIM2[2])			(void) = {NULL,NULL};
static void	(* TIM1[4])			(void) = {NULL,NULL,NULL,NULL};
static void (* TIM0[2])			(void) = {NULL,NULL};
static void (* UART_INT[3])		(void) = {NULL,NULL,NULL} ;
static void (* ADC_INT)			(void) = NULL;
static void (* SPI_INT)			(void) = NULL;
static void (*EE_RDY_INT)		(void ) = NULL ;

u8 SET_INT_VEC_TO_ISR(u8 u8_INT_VEC_NAME , void (*FUNC_PTR)(void))
{
	u8 ErrorState;

	if((u8_INT_VEC_NAME >= 1)&&(u8_INT_VEC_NAME <=20)&&(FUNC_PTR != NULL))
	{
		ErrorState = ErrorStateOK ;

		switch ( u8_INT_VEC_NAME)
		{
			case EXT_INT0_VEC:			EXT_INT[0] 	= FUNC_PTR;		break ;
			case EXT_INT1_VEC:			EXT_INT[1] 	= FUNC_PTR;		break ;
			case EXT_INT2_VEC:			EXT_INT[2] 	= FUNC_PTR;		break ;

			case TIMER2_CMP_VEC:		TIM2[0]	   	= FUNC_PTR;		break ;
			case TIMER2_OVF_VEC:		TIM2[1]    	= FUNC_PTR;		break ;

			case TIMER1_CAP_EVENT_VEC:	TIM1[0] 	= FUNC_PTR;		break ;
			case TIMER1_CMPA_VEC:		TIM1[1] 	= FUNC_PTR;		break ;
			case TIMER1_CMPB_VEC:		TIM1[2] 	= FUNC_PTR;		break ;
			case TIMER1_OVF_VEC:		TIM1[3] 	= FUNC_PTR;		break ;

			case TIMER0_CMP_VEC:		TIM0[0] 	= FUNC_PTR;		break ;
			case TIMER0_OVF_VEC:		TIM0[1] 	= FUNC_PTR; 	break ;

			case SPI_STC_VEC:			SPI_INT 	= FUNC_PTR;		break ;

			case UART_RXC_VEC:			UART_INT[0] = FUNC_PTR;		break ;
			case UART_UDRE_VEC:			UART_INT[1] = FUNC_PTR;		break ;
			case UART_TXC_VEC:			UART_INT[2] = FUNC_PTR;		break ;

			case ADC_VEC:				ADC_INT	    = FUNC_PTR;		break ;


			case EE_RDY_VEC:			EE_RDY_INT  = FUNC_PTR;		break ;

		}
	}
	else
	{
		ErrorState = ErrorStateNOK;
	}

	return ErrorState;
}

/*External interrupts ISR*/
ISR(EXT_INT0)			{	EXT_INT[0](); 	}
ISR(EXT_INT1)			{	EXT_INT[1](); 	}
ISR(EXT_INT2)			{	EXT_INT[2](); 	}

/*TIMER2 ISR*/
ISR(TIMER2_CMP)			{	TIM2[0]();		}
ISR(TIMER2_OVF)			{	TIM2[1]();		}

/*TIMER1 ISR*/
ISR(TIMER1_CAP_EVENT)	{	TIM1[0]();		}
ISR(TIMER1_CMPA)		{	TIM1[1]();		}
ISR(TIMER1_CMPB)		{	TIM1[2]();		}
ISR(TIMER1_OVF)			{	TIM1[3]();		}

/*TIMER0 ISR*/
ISR(TIMER0_CMP)			{	TIM0[0]();		}
ISR(TIMER0_OVF)			{	TIM0[1]();		}

/*SPI ISR*/
ISR(SPI_STC)			{	SPI_INT();		}

/*UART ISR*/
ISR(UART_RXC)			{	UART_INT[0]();	}
ISR(UART_UDRE)			{	UART_INT[1]();	}
ISR(UART_TXC)			{	UART_INT[2]();	}

/*ADC ISR*/
ISR(ADC)				{	ADC_INT();		}

/*EEPROM ISR*/
ISR(EE_RDY)				{	EE_RDY_INT();	}











