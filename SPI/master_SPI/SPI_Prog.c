/*
 * SPI_Prog.c
 *
 *  Created on: May 14, 2019
 *      Author: Ahmed
 */


#include "STD_TYPES.h"
#include "BIT_CALC.h"

#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

void SPI_Init (void)
{
	SPCR_Register = (SPI_INT_Status<<7)|(SPI_Status<<6)|(SPI_DATA_ORDER<<5)|(SPI_MODE<<4)|(SPI_Clock_Polarity<<3)|(SPI_Clock_Phase<<2)|(SPI_PRESCALER<<0);
	/* Enable SPI, Master, set clock rate fck/16 , CPHA setupthen sample */
	//SPCR_REG = (1<<6)|(1<<4)|(1<<0)|(1<<2);


#if (SPI_MODE == SPI_MASTER)
	SET_BIT(SPCR_Register,4);
#else
	CLR_BIT(SPCR_Register,4);
#endif
}

void SPI_SynchTransceiver(u8 Copy_DataSent, u8 *Copy_DataReceived)
{
	/* Start transmission */
	SPDR_Register = Copy_DataSent;
	/* Wait for transmission complete */
	while(!(SPSR_Register & (1<<7)));
	/*save Received Byte*/
	*Copy_DataReceived = SPDR_Register;
}
void SPI_SendByte(u8 Data)
{
	SPDR_Register = Data;
	while(!(GET_BIT(SPSR_Register,7) ));
}
