/*
 * TIMER_CONFG.h
 *
 *
 *  Created on: Oct 9, 2019
 *      Author: shady
 */
#include"TIMER_INT.h"

#ifndef TIMER_CONFG_H_
#define TIMER_CONFG_H_
/*TIMER0 Initialization state*/

/*Force Output Compare --> TIM0_FOC0_OFF			TIM0_FOC0_ON		*/
#define TIM0_FOC0_STATE			TIM0_FOC0_OFF

/*TIMER0 Wave Generation MODE-->TIM0_NORMAL	TIM0_PWM_PC		TIM0_CTC	TIM0_PWM_FAST*/
#define TIM0_WG_MODE			TIM0_PWM_FAST

/*TIMER0 OC0 MODES-->non-PWM -->
 * 		TIM0_NORMAL_PORT	TIM0_TOG_OC0	TIM0_CLR_OC0	TIM0_SET_OC0
 * 				  -->Fast /PC PWM -->
 *		TIM0_NORMAL_PORT	TIM0_RESERVED	TIM0_CLR_SET_OC0	TIM0_SET_CLR_OC0
 * 		OUTPUT won't appear unless OC0 is made an output using DDRx register	  */
#define TIM0_OC0_STATE			TIM0_CLR_SET_OC0

/*TIMER0 CLK Select -->	TIM0_NO_CLK_TIM0_STOP 	TIM0_CLK_1			TIM0_CLK_8
 * 						TIM0_CLK_64				TIM0_CLK_256		TIM0_CLK_1024
 * 						TIM0_EXT_CLK_FE			TIM0_EXT_CLK_RE*/

#define TIM0_CLK_PRESCALAR		TIM0_CLK_8

/*TIMER0 Interrupt -->TIM0_CMP_INT_EN	TIM0_CMP_INT_DIS
 * 					TIM0_OVF_INT_DIS	TIM0_OVF_INT_DIS
 * 				-->	Enable Global Interrupt from INTERRUPT.h*/
#define TIM0_OVF_INT_STATE		TIM0_OVF_INT_DIS
#define TIM0_CMP_INT_STATE		TIM0_CMP_INT_DIS

/****************************************************************************/
/****************************************************************************/
/******************************** TIMER1 ********************************/
/****************************************************************************/
/****************************************************************************/

/*TIMER1 Initializing State*/

/*Force Output Compare --> TIM1_FOC1A_OFF			TIM1_FOC1A_ON
 *					   --> TIM1_FOC1B_OFF			TIM1_FOC1B_ON	 */
#define TIM1_FOC1A_STATE			TIM1_FOC1A_OFF
#define TIM1_FOC1B_STATE			TIM1_FOC1B_OFF


/*TIMER1 Wave Generation MODE-->
 * TIM1_NORMAL
 * TIM1_PWM_PC_8	 TIM1_PWM_PC_9  	TIM1_PWM_PC_10 		TIM1_PWM_PC_TOP_ICR	 	TIM1_PWM_PC_TOP_OCR
 * TIM1_CTC_TOP_OCR				TIM1_CTC_TOP_ICR
 * TIM1_PWM_FAST_8	 TIM1_PWM_FAST_9	TIM1_PWM_FAST_10	TIM1_PWM_FAST_TOP_ICR	TIM1_PWM_FAST_TOP_OCR*/
#define TIM1_WG_MODE			TIM1_PWM_FAST_TOP_ICR


/*TIMER1 OC1A MODES-->non-PWM -->
 * 		TIM1_NORMAL_PORT	TIM1_TOG_OC1A	TIM1_CLR_OC1A	TIM1_SET_OC1A
 * 				  -->Fast /PC PWM -->
 *		TIM1_NORMAL_PORT	TIM1_TOG_OC1A_OFF_OC1B	TIM1_CLR_SET_OC1A	TIM1_SET_CLR_OC1A
 * 		OUTPUT won't appear unless OC0 is made an output using DDRx register	  */
#define TIM1_OC1A_STATE			TIM1_CLR_SET_OC1A



/*TIMER1 OC1B MODES-->non-PWM -->
 * 		TIM1_NORMAL_PORT	TIM1_TOG_OC1B	TIM1_CLR_OC1B	TIM1_SET_OC1B
 * 				  -->Fast /PC PWM -->
 *		TIM1_NORMAL_PORT	TIM1_TOG_OC1A_OFF_OC1B	TIM1_CLR_SET_OC1B	TIM1_SET_CLR_OC1B
 * 		OUTPUT won't appear unless OC0 is made an output using DDRx register	  */
#define TIM1_OC1B_STATE			TIM1_NORMAL_PORT



/*TIMER1 ICU Noise Canceler -->TIM1_IN_CAP_NOISE_CAN_OFF		TIM1_IN_CAP_NOISE_CAN_ON*/
#define TIM1_IN_CAP_NOISE_CAN_STATE			TIM1_IN_CAP_NOISE_CAN_OFF



/*TIMER1 ICU Edge SEL --> TIM1_IN_CAP_Edge_FALL				TIM1_IN_CAP_Edge_RISE*/
#define TIM1_IN_CAP_Edge_STATE		TIM1_IN_CAP_Edge_FALL



/*TIMER1 CLK Select -->	TIM1_NO_CLK_TIM1_STOP 	TIM1_CLK_1			TIM1_CLK_8
 * 						TIM1_CLK_64				TIM1_CLK_256		TIM1_CLK_1024
 * 						TIM1_EXT_CLK_FE			TIM1_EXT_CLK_RE*/
#define TIM1_CLK_PRESCALAR		TIM1_CLK_8



/*TIMER1 Interrupt -->TIM1_CMPA_INT_EN		TIM1_CMPA_INT_DIS
 * 					  TIM1_CMPB_INT_EN		TIM1_CMPB_INT_DIS
 * 					  TIM1_OVF_INT_EN		TIM1_OVF_INT_DIS
 * 					  TIM1_ICU_INT_EN		TIM1_ICU_INT_DIS
 * 				-->	Enable Global Interrupt from INTERRUPT.h*/
#define TIM1_OVF_INT_STATE		TIM1_OVF_INT_DIS
#define	TIM1_CMPA_INT_STATE		TIM1_CMPA_INT_DIS
#define TIM1_CMPB_INT_STATE		TIM1_CMPB_INT_DIS
#define TIM1_ICU_INT_STATE		TIM1_ICU_INT_DIS



#endif /* TIMER_CONFG_H_ */
