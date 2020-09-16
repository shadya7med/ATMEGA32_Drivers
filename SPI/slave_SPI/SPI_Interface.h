/*
 * SPI_Interface.h
 *
 *  Created on: May 14, 2019
 *      Author: Ahmed
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_Init (void);
void SPI_SynchTransceiver(u8 Copy_DataSent, u8 *Copy_DataReceived);


#endif /* SPI_INTERFACE_H_ */
