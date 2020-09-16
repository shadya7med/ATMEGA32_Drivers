/*
 * TIMER_REG.h
 *
 *  Created on: Oct 7, 2019
 *      Author: shady
 */

#ifndef TIMER_REG_H_
#define TIMER_REG_H_


/*TIMER0 registers*/
#define TCNT0_register 	(*(volatile u8*)0x52)
#define TCCR0_register 	(*(volatile u8*)0x53)
#define OCR0_register 	(*(volatile u8*)0x5C)

/*TIMER2 registers*/
#define TCNT2_register 	(*(volatile u8*)0x44)
#define TCCR2_register 	(*(volatile u8*)0x45)
#define OCR2_register	(*(volatile u8*)0x43)

/*TIMER1 registers*/
#define TCCR1A_register	(*(volatile u8*)0x4F)
#define TCCR1B_register	(*(volatile u8*)0x4E)
#define TCNT1_register	(*(volatile u16*)0x4C)
#define TCNT1L_register	(*(volatile u8*)0x4C)
#define TCNT1H_register	(*(volatile u8*)0x4D)
#define OCR1A_register	(*(volatile u16*)0x4A)
#define OCR1AL_register	(*(volatile u8*)0x4A)
#define OCR1AH_register	(*(volatile u8*)0x4B)
#define OCR1B_register	(*(volatile u16*)0x48)
#define OCR1BL_register	(*(volatile u8*)0x48)
#define OCR1BH_register	(*(volatile u8*)0x49)
#define ICR1_register	(*(volatile u16*)0x46)
#define ICR1L_register	(*(volatile u8*)0x46)
#define ICR1H_register	(*(volatile u8*)0x47)

/*All Timer Registers*/

/*TISMK --> PIE*/
#define TIMSK_register 	(*(volatile u8*)0x59)

/*TIFR --> PIF*/
#define TIFR_register 	(*(volatile u8*)0x58)



#endif /* TIMER_REG_H_ */
