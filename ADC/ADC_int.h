/*
 * ADC_int.h
 *
 *  Created on: Sep 7, 2019
 *      Author: shady
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

#define HIGH 1
#define LOW 0


#define ADCChannel0 0b11100000

/*ADMUX_REGISTER_PINS*/
#define REFS1 7
#define REFS0 6
#define ADLAR 5

/*ADCSRA*/
#define ADEN 7
#define ADSC 6
#define ADIF 4


/*ADC Functions*/
void ADC_intialize(void);
u8 ADC_GETVALUE_BLOCKING(u8 u8_ChannelNum,u8 *u8_ResultCopy);

#endif /* ADC_INT_H_ */
