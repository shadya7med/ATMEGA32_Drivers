/*
 * TIMER_FUNC.c
 *
 *  Created on: Oct 13, 2019
 *      Author: shady
 */
#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"TIMER_REG.h"
#include"TIMER_INT.h"
#include"TIMER_CONFG.h"



/*Writing Zero to Timer counter Register , compare match register or IC register means leave it  at default*/
void TIMER0_INIT(u8 u8_TIM0_REGValue,u8 u8_COM_MAT_REGValue)
{

	/*TIMER0 Initialize*/
	/*INIT parameters are set on TIMER CONFG file */
	TCCR0_register = TIM0_FOC0_STATE << 7|TIM0_WG_MODE |TIM0_OC0_STATE << 4 | TIM0_CLK_PRESCALAR;

	/*SET Timer REG with a Value Bigger than or Equal Zero to increment on it*/
	if (((TIM0_WG_MODE == TIM0_NORMAL) || (TIM0_WG_MODE == TIM0_CTC)) && (u8_TIM0_REGValue != 0))
	{
		TCNT0_register = u8_TIM0_REGValue;
	}

	/*Load Compare Match Register if WG mode is not NORMAL MODE */
	if ((TIM0_WG_MODE != TIM0_NORMAL) && (u8_COM_MAT_REGValue))
	{
		OCR0_register = u8_COM_MAT_REGValue;
	}

	/*control OVf interrupt*/
	switch(TIM0_OVF_INT_STATE)
	{
		case TIM0_OVF_INT_EN  : SET_BIT(TIMSK_register,TOIE0);		break;
		case TIM0_OVF_INT_DIS :	CLR_BIT(TIMSK_register,TOIE0);		break;

	}

	/*control CMP interrupt*/
	switch(TIM0_CMP_INT_STATE)
	{

		case TIM0_CMP_INT_EN  :	SET_BIT(TIMSK_register,OCIE0);		break;
		case TIM0_CMP_INT_DIS :	CLR_BIT(TIMSK_register,OCIE0);		break;
	}
	/*Enable Global Interrupt from INTERRUPT.h*/
}



void TIM0_Set_TIMER_REG_Value(u8 u8_RegValue)
{
	TCNT0_register = u8_RegValue;
}


void TIM0_Set_CMP_REG_Value(u8 u8_RegValue)
{
	OCR0_register = u8_RegValue;
}

/*****************************************************************************************************/
/*****************************************************************************************************/
    /***************************************TIMER1***********************************************/
/*****************************************************************************************************/
/*****************************************************************************************************/


void TIMER1_INIT(u16 u16_TIM1_REGValue,u16 u16_COMA_MAT_REGValue,u16 u16_COMB_MAT_REGValue,u16 u16_IC_REGValue)
{

	u8 u8_WGM_11_10_Value,u8_WGM_13_12_Value;
	/*TIMER1 Initialize*/
	/*INIT parameters are set on TIMER CONFG file */

	/*Wave Generation mode select*/
	switch(TIM1_WG_MODE)
	{
		case TIM1_NORMAL		: u8_WGM_13_12_Value = WGM_13_12_0 ; u8_WGM_11_10_Value	= WGM_11_10_0 ;		break;

		case TIM1_PWM_PC_8 		: u8_WGM_13_12_Value = WGM_13_12_1 ; u8_WGM_11_10_Value= WGM_11_10_1 	;				break;
		case TIM1_PWM_PC_9		: u8_WGM_13_12_Value = WGM_13_12_2 ; u8_WGM_11_10_Value= WGM_11_10_2 	;				break;
		case TIM1_PWM_PC_10 	: u8_WGM_13_12_Value = WGM_13_12_3 ; u8_WGM_11_10_Value= WGM_11_10_3 	;				break;

		case TIM1_CTC_TOP_OCR 	: u8_WGM_13_12_Value = WGM_13_12_4 ; u8_WGM_11_10_Value= WGM_11_10_4 	;				break;

		case TIM1_PWM_FAST_8    : u8_WGM_13_12_Value = WGM_13_12_5 ; u8_WGM_11_10_Value= WGM_11_10_5 	;				break;
		case TIM1_PWM_FAST_9    : u8_WGM_13_12_Value = WGM_13_12_6 ; u8_WGM_11_10_Value= WGM_11_10_6 	;				break;
		case TIM1_PWM_FAST_10   : u8_WGM_13_12_Value = WGM_13_12_7 ; u8_WGM_11_10_Value= WGM_11_10_7 	;				break;

		case TIM1_PWM_PC_TOP_ICR: u8_WGM_13_12_Value = WGM_13_12_10 ; u8_WGM_11_10_Value= WGM_11_10_10 	;				break;
		case TIM1_PWM_PC_TOP_OCR: u8_WGM_13_12_Value = WGM_13_12_11 ; u8_WGM_11_10_Value= WGM_11_10_11 	;				break;

		case TIM1_CTC_TOP_ICR 	: u8_WGM_13_12_Value = WGM_13_12_12 ; u8_WGM_11_10_Value= WGM_11_10_12 	;				break;

		case TIM1_PWM_FAST_TOP_ICR:u8_WGM_13_12_Value= WGM_13_12_14 ; u8_WGM_11_10_Value= WGM_11_10_14 	;				break;
		case TIM1_PWM_FAST_TOP_OCR:u8_WGM_13_12_Value= WGM_13_12_15 ; u8_WGM_11_10_Value= WGM_11_10_15 	;				break;


	}

	/*setting TIMER1 Control registers*/
	TCCR1A_register = TIM1_OC1A_STATE << 6 |TIM1_OC1B_STATE << 4|TIM1_FOC1A_STATE <<3 |TIM1_FOC1B_STATE << 2 |u8_WGM_11_10_Value;
	TCCR1B_register = TIM1_IN_CAP_NOISE_CAN_STATE << 7 |TIM1_IN_CAP_Edge_STATE << 6 | 0 << 5 | u8_WGM_13_12_Value << 3 |TIM1_CLK_PRESCALAR;

	/*SET Timer REG with a Value Bigger than  Zero to increment on it*/
	if (((TIM1_WG_MODE == TIM1_NORMAL) || (TIM1_WG_MODE == TIM1_CTC_TOP_OCR)|| (TIM1_WG_MODE == TIM1_CTC_TOP_ICR)) && (u16_TIM1_REGValue != 0))
	{
		TCNT1_register = u16_TIM1_REGValue;
	}

	/*Load Compare Match Register if WG mode is not NORMAL MODE */
	if (TIM1_WG_MODE != TIM1_NORMAL)
	{
		if (u16_COMA_MAT_REGValue != 0){OCR1A_register = u16_COMA_MAT_REGValue ;}
		if (u16_COMB_MAT_REGValue != 0){OCR1B_register = u16_COMB_MAT_REGValue ;}
	}

	/*Load Input Capture Register it ICR was top value*/
	if (((TIM1_WG_MODE == TIM1_PWM_PC_TOP_ICR)||(TIM1_WG_MODE == TIM1_PWM_FAST_TOP_ICR)||(TIM1_WG_MODE == TIM1_CTC_TOP_ICR))&& (u16_IC_REGValue != 0))
	{
		ICR1_register = u16_IC_REGValue;
	}

	/*control OVf interrupt*/
	switch(TIM1_OVF_INT_STATE)
	{
		case TIM1_OVF_INT_EN  : SET_BIT(TIMSK_register,TOIE1);		break;
		case TIM1_OVF_INT_DIS :	CLR_BIT(TIMSK_register,TOIE1);		break;

	}

	/*control CMP interrupt*/
	switch(TIM1_CMPA_INT_STATE)
	{

		case TIM1_CMPA_INT_EN  :	SET_BIT(TIMSK_register,OCIE1A);		break;
		case TIM1_CMPB_INT_DIS :	CLR_BIT(TIMSK_register,OCIE1A);		break;
	}
	switch(TIM1_CMPB_INT_STATE)
		{

			case TIM1_CMPB_INT_EN  :	SET_BIT(TIMSK_register,OCIE1B);		break;
			case TIM1_CMPB_INT_DIS :	CLR_BIT(TIMSK_register,OCIE1B);		break;
		}
	/*Control IC interrupt*/
	switch(TIM1_ICU_INT_STATE)
		{

			case TIM1_ICU_INT_EN  :	SET_BIT(TIMSK_register,TICIE1);		break;
			case TIM1_ICU_INT_DIS :	CLR_BIT(TIMSK_register,TICIE1);		break;
		}
	/*Enable Global Interrupt from INTERRUPT.h*/
}





void TIM1_Set_CMPA_REG_Value(u16 u16_RegValue)
{

	OCR1A_register = u16_RegValue;

}


void TIM1_Set_CMPB_REG_Value(u16 u16_RegValue)
{
	OCR1B_register = u16_RegValue;

}


void TIM1_Set_TIMER_REG_Value(u16 u16_RegValue)
{
	TCNT1_register = u16_RegValue;

}


void TIM1_Set_IC_REG_Value(u16 u16_RegValue)
{
	ICR1_register = u16_RegValue;


}
