/*
 * INTERRUPT_INT.h
 *
 *  Created on: Oct 7, 2019
 *      Author: shady
 */

#ifndef INTERRUPT_INT_H_
#define INTERRUPT_INT_H_





/*Interrupt Vectors name */
#define EXT_INT0_VEC				1
#define EXT_INT1_VEC				2
#define EXT_INT2_VEC				3
#define TIMER2_CMP_VEC				4
#define TIMER2_OVF_VEC				5
#define TIMER1_CAP_EVENT_VEC		6
#define TIMER1_CMPA_VEC				7
#define TIMER1_CMPB_VEC				8
#define TIMER1_OVF_VEC				9
#define TIMER0_CMP_VEC				10
#define TIMER0_OVF_VEC				11
#define SPI_STC_VEC					12
#define UART_RXC_VEC				13
#define UART_UDRE_VEC				14
#define UART_TXC_VEC				15
#define ADC_VEC						16
#define EE_RDY_VEC					17
/*there still 3 vectors to be added*/


/*Interrupt function prototypes*/
u8 SET_INT_VEC_TO_ISR(u8 u8_INT_VEC_NAME, void (*FUNC_PTR)(void));




/*Global Interrupt Enable*/
/*Status Register*/


#define SREG_register	(*(volatile u8*)0x5F)

/*Status register PINS*/
#define I_BIT			7
#define T_BIT			6
#define H_BIT			5
#define S_BIT			4
#define V_BIT			3
#define N_BIT			2
#define Z_BIT			1
#define C_BIT			0



#endif /* INTERRUPT_INT_H_ */
