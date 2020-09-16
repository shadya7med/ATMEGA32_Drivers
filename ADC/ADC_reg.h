/*
 * ADC_reg.h
 *
 *  Created on: Sep 7, 2019
 *      Author: shady
 */

#ifndef ADC_REG_H_
#define ADC_REG_H_

/*ADC Registers*/
#define ADMUX_register *((volatile u8*)0x27)
#define ADCSRA_register *((volatile u8*)0x26)
#define ADCH_register *((volatile u8*)0x25)
#define ADCL_register *((volatile u8*)0x24)



#endif /* ADC_REG_H_ */
