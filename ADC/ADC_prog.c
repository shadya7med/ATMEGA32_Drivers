/*
 * ADC_prog.c
 *
 *  Created on: Sep 7, 2019
 *      Author: shady
 */
#include"STD_TYPES.h"
#include"BIT_CALC.h"
//#include "DIO_reg.h"
#include "ADC_reg.h"
#include "ADC_int.h"

void ADC_intialize(void)
{

	/*ADC Enable*/
	SET_BIT(ADCSRA_register,ADEN);
	/*REF Selection */
	SET_BIT(ADMUX_register,REFS0);
	CLR_BIT(ADMUX_register,REFS1);

	/*ADC Left Adjusted*/
	SET_BIT(ADMUX_register,ADLAR);



	/*Prescalar Factor --> 128 */
	ADCSRA_register &= 0b11111000 ;




}
u8 ADC_GETVALUE_BLOCKING(u8 u8_ChannelNum,u8 *u8_ResultCopy)
{
		u8 u8_ChannelErrorState;

	if ((u8_ChannelNum >=0) || (u8_ChannelNum <=7))
	{
		/*Channel Num Check*/
		u8_ChannelErrorState = ErrorStateOK ;
		/*Analog Channel Selection*/
		ADMUX_register = (((ADMUX_register) & (ADCChannel0)) | (u8_ChannelNum));
		/*Start Conversion*/
		SET_BIT(ADCSRA_register,ADSC);
		/*read blocking*/
		while (GET_BIT(ADCSRA_register,ADIF)== 0 );

		/*Clear ADC Read flag*/
		SET_BIT(ADCSRA_register,ADIF);
		/*read*/
		(*u8_ResultCopy) = ADCH_register;
	}
	else {
		u8_ChannelErrorState = ErrorStateNOK ;



	}

return u8_ChannelErrorState ;
}
