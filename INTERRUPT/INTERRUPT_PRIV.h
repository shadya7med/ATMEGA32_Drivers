/*
 * INTERRUPT_PRIV.h
 *
 *  Created on: Oct 7, 2019
 *      Author: shady
 */

#ifndef INTERRUPT_PRIV_H_
#define INTERRUPT_PRIV_H_


#define ISR(vector) 	void vector (void ) __attribute__((signal));\
						void vector (void )

/*AVR ATMEGA32 interrupt vector*/
/* EXT--> External
 * CMP--> compare
 * OVF-->Overflow
 * CAP-->capture event
 * STC-->Serial transfer complete
 * RXC-->receiving complete
 * TXC-->transmitting complete
 * UDRE-->UART data register is empty
 * */
#define EXT_INT0				__vector_1
#define EXT_INT1				__vector_2
#define EXT_INT2				__vector_3
#define TIMER2_CMP				__vector_4
#define TIMER2_OVF				__vector_5
#define TIMER1_CAP_EVENT		__vector_6
#define TIMER1_CMPA				__vector_7
#define TIMER1_CMPB				__vector_8
#define TIMER1_OVF				__vector_9
#define TIMER0_CMP				__vector_10
#define TIMER0_OVF 				__vector_11
#define SPI_STC					__vector_12
#define UART_RXC				__vector_13
#define UART_UDRE				__vector_14
#define UART_TXC				__vector_15
#define ADC						__vector_16
#define EE_RDY					__vector_17
/*there still 3 vectors to be added*/


#endif /* INTERRUPT_PRIV_H_ */

