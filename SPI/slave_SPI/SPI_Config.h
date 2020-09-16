/*
 * SPI_Config.h
 *
 *  Created on: May 14, 2019
 *      Author: Ahmed
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/* SPI_SLAVE	or 	SPI_MASTER*/
#define SPI_MODE			SPI_SLAVE

/* SPICLK_DIV_BY_4	SPICLK_DIV_BY_16	SPICLK_DIV_BY_64	SPICLK_DIV_BY_128*/
#define SPI_PRESCALER		SPICLK_DIV_BY_16

/*IDLE_HIGH		IDLE_LOW*/
#define SPI_Clock_Polarity	IDLE_LOW

/*Sample_On_Leading		Sample_On_Trailing*/
#define SPI_Clock_Phase		Sample_On_Trailing

/*LSB_FIRST		MSB_FIRST*/
#define SPI_DATA_ORDER		LSB_FIRST

/*SPI_ENABLE		SPI_DISABLE*/
#define SPI_Status			SPI_ENABLE

/*SPI_INT_ENABLE		SPI_INT_DISABLE*/
#define SPI_INT_Status		SPI_INT_DISABLE

#endif /* SPI_CONFIG_H_ */
