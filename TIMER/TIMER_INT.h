/*
 * TIMER_INT.h
 *
 *  Created on: Oct 7, 2019
 *      Author: shady
 */

#ifndef TIMER_INT_H_
#define TIMER_INT_H_

/*TIMER0 registers PINS*/
/*TCCR0*/
#define FOC0 	7
#define WGM00	6
#define COM01	5
#define COM00	4
#define WGM01	3
#define CS02	2
#define CS01	1
#define CS00	0

/*TIMER0 Force Output Compare --> BIT 7*/
#define TIM0_FOC0_OFF			0
#define TIM0_FOC0_ON			1

/*TIMER0 Wave Generation MODES-->BITs 6,3*/
#define TIM0_NORMAL		0b00000000
#define TIM0_PWM_PC		0b01000000
#define TIM0_CTC		0b00001000
#define TIM0_PWM_FAST	0b01001000

/*TIMER0 OC0 MODES-->non-PWM -->BITs5,4*/
#define TIM0_NORMAL_PORT	0b00
#define TIM0_TOG_OC0		0b01
#define TIM0_CLR_OC0		0b10
#define TIM0_SET_OC0		0b11

/*TIMER0 OC0 MODES-->fast/PC-PWM -->BITs5,4*/
//#define TIM0_NORMAL_PORT		0b00 //already defined
#define TIM0_RESERVED			0b01
#define TIM0_CLR_SET_OC0		0b10
#define TIM0_SET_CLR_OC0		0b11



/*TIMER0 CLK Select --> BITs2,1,0*/
#define TIM0_NO_CLK_TIM0_STOP	0b000
#define TIM0_CLK_1				0b001
#define TIM0_CLK_8				0b010
#define TIM0_CLK_64				0b011
#define TIM0_CLK_256			0b100
#define TIM0_CLK_1024			0b101
#define TIM0_EXT_CLK_FE			0b110
#define TIM0_EXT_CLK_RE			0b111

/*TIMER0 Interrupt State*/
#define TIM0_OVF_INT_EN			1
#define TIM0_OVF_INT_DIS		0

#define TIM0_CMP_INT_EN			1
#define TIM0_CMP_INT_DIS		0
/*****************************************************************/
/*TIMER0 registers PINS*/
/*TCRR1A*/
#define COM1A1		7
#define COM1A0		6
#define COM1B1		5
#define COM1B0		4
#define FOC1A		3
#define FOC1B		2
#define WGM11		1
#define WGM10		0

/*TCCR1B*/
#define ICNC1		7
#define ICES1		6
#define WGM13		4
#define WGM12		3
#define CS12		2
#define CS11		1
#define CS10		0

/*TCCR1A states*/
/*TIMER1 Compare Output Mode for Ch.A-->BITS 7,6
 * 						-->Non-PWM*/
#define TIM1_NORMAL_PORT		0b00
#define TIM1_TOG_OC1A			0b01
#define TIM1_CLR_OC1A			0b10
#define TIM1_SET_OC1A			0b11

/*				-->fast/PC-PWM -->	*/
//#define TIM1_NORMAL_PORT		0b00 //already defined
#define TIM1_TOG_OC1A_OFF_OC1B	0b01//if WG mode was mode 15,otherwise both OC1A & OC1B will be OFF
#define TIM1_CLR_SET_OC1A		0b10
#define TIM1_SET_CLR_OC1A		0b11

/*TIMER1 Compare Output Mode for Ch.B-->BITS 5,4*/
/* 						-->Non-PWM*/
//#define TIM1_NORMAL_PORT		0b00 //already defined
#define TIM1_TOG_OC1B			0b01
#define TIM1_CLR_OC1B			0b10
#define TIM1_SET_OC1B			0b11

/*				-->fast/PC-PWM -->	*/
//#define TIM1_NORMAL_PORT		0b00 //already defined
#define TIM1_TOG_OC1A_OFF_OC1B	0b01//if WG mode was mode 15,otherwise both OC1A & OC1B will be OFF
#define TIM1_CLR_SET_OC1B		0b10
#define TIM1_SET_CLR_OC1B		0b11

/*Force Output Compare for Channel A --> bit 3*/
#define TIM1_FOC1A_ON				1
#define TIM1_FOC1A_OFF				0

/*Force Output Compare for Channel B --> bit 2*/
#define TIM1_FOC1B_ON				1
#define TIM1_FOC1B_OFF				0

/*TIMER1 WG Modes*/
#define	TIM1_NORMAL					0
#define TIM1_PWM_PC_8				1
#define TIM1_PWM_PC_9				2
#define TIM1_PWM_PC_10				3
#define TIM1_CTC_TOP_OCR			4
#define TIM1_PWM_FAST_8				5
#define	TIM1_PWM_FAST_9				6
#define TIM1_PWM_FAST_10			7
#define TIM1_PWM_PC_TOP_ICR			10
#define	TIM1_PWM_PC_TOP_OCR 		11
#define TIM1_CTC_TOP_ICR			12
#define	TIM1_PWM_FAST_TOP_ICR		14
#define	TIM1_PWM_FAST_TOP_OCR		15

#define WGM_11_10_0					0b00
#define WGM_11_10_1					0b01
#define WGM_11_10_2					0b10
#define WGM_11_10_3					0b11
#define WGM_11_10_4					0b00
#define WGM_11_10_5					0b01
#define WGM_11_10_6					0b10
#define WGM_11_10_7					0b11
#define WGM_11_10_8					0b00
#define WGM_11_10_9					0b01
#define WGM_11_10_10				0b10
#define WGM_11_10_11				0b11
#define WGM_11_10_12				0b00
#define WGM_11_10_13				0b01
#define WGM_11_10_14				0b10
#define WGM_11_10_15				0b11

#define WGM_13_12_0					0b00
#define WGM_13_12_1					0b00
#define WGM_13_12_2					0b00
#define WGM_13_12_3					0b00
#define WGM_13_12_4					0b01
#define WGM_13_12_5					0b01
#define WGM_13_12_6					0b01
#define WGM_13_12_7					0b01
#define WGM_13_12_8					0b10
#define WGM_13_12_9					0b10
#define WGM_13_12_10				0b10
#define WGM_13_12_11				0b10
#define WGM_13_12_12				0b11
#define WGM_13_12_13				0b11
#define WGM_13_12_14				0b11
#define WGM_13_12_15				0b11





/*TCCR1B states */
/*TIMER1 Input Capture Noise Canceler -->bit 7*/
#define TIM1_IN_CAP_NOISE_CAN_ON	1
#define TIM1_IN_CAP_NOISE_CAN_OFF	0

/*TIMER1 INPUT Capture Edge Select-->bit 6*/
#define TIM1_IN_CAP_Edge_FALL		0
#define TIM1_IN_CAP_Edge_RISE		1

/*bit 5 is reserved will always be written zero */

/*TIMER1 Clock pre-scalar -->bit 2,1,0*/
#define TIM1_NO_CLK_TIM1_STOP		0b000
#define TIM1_CLK_1					0b001
#define TIM1_CLK_8					0b010
#define TIM1_CLK_64					0b011
#define TIM1_CLK_256				0b100
#define TIM1_CLK_1024				0b101
#define TIM1_EXT_CLK_FE				0b110
#define TIM1_EXT_CLK_RE				0b111

/*TIMER1 Interrupt States*/
#define TIM1_OVF_INT_DIS			0
#define TIM1_OVF_INT_EN				1

#define TIM1_CMPA_INT_DIS			0
#define TIM1_CMPA_INT_EN			1

#define TIM1_CMPB_INT_DIS			0
#define TIM1_CMPB_INT_EN			1

#define TIM1_ICU_INT_DIS			0
#define TIM1_ICU_INT_EN				1

/************************************************************************/
/*All Timers flags and Interrupt enables PINS*/
/*TIMSK*/
#define OCIE2	7
#define TOIE2	6
#define TICIE1	5
#define OCIE1A	4
#define OCIE1B	3
#define TOIE1	2
#define OCIE0	1
#define TOIE0	0

/*TIFR*/
#define OCF2	7
#define TOV2	6
#define ICF1	5
#define OCF1A	4
#define OCF1B	3
#define TOV1	2
#define OCF0	1
#define TOV0	0

/*TIMERs Functions*/
/*TIMER0*/
void TIMER0_INIT(u8 u8_TIM0_REGValue,u8 u8_COM_MAT_REGValue);

void TIM0_Set_TIMER_REG_Value(u8 u8_RegValue);

void TIM0_Set_CMP_REG_Value(u8 u8_RegValue);

/*TIMER1*/
void TIMER1_INIT(u16 u16_TIM1_REGValue,u16 u16_COMA_MAT_REGValue, u16 u16_COMB_MAT_REGValue,u16 u16_IC_REGValue);

void TIM1_Set_TIMER_REG_Value(u16 u16_RegValue);

void TIM1_Set_CMPA_REG_Value(u16 u16_RegValue);
void TIM1_Set_CMPB_REG_Value(u16 u16_RegValue);

void TIM1_Set_IC_REG_Value(u16 u16_RegValue);


/*TIMER2*/

#endif /* TIMER_INT_H_ */
