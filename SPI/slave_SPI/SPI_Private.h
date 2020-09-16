/*
 * SPI_Private.h
 *
 *  Created on: May 14, 2019
 *      Author: Ahmed
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPCR	((volatile Register *)(0x2D))
#define SPSR	((volatile Register *)(0x2E))
#define SPDR 	((volatile Register *)(0x2F))


#define SPCR_REG	(SPCR->ByteAccess)
#define SPSR_REG	(SPSR->ByteAccess)
#define SPDR_REG	(SPDR->ByteAccess)


/**************************************************/
#define SPI_SLAVE			0
#define SPI_MASTER			1

#define SPICLK_DIV_BY_4		0b00
#define SPICLK_DIV_BY_16    0b01
#define SPICLK_DIV_BY_64    0b10
#define SPICLK_DIV_BY_128   0b11
//#define SPICLK_DIV_BY_2     0b100
//#define SPICLK_DIV_BY_8     0b101
//#define SPICLK_DIV_BY_32    0b110

#define IDLE_HIGH			1
#define IDLE_LOW			0

#define Sample_On_Leading	0
#define Sample_On_Trailing	1

#define LSB_FIRST			1
#define MSB_FIRST			0

#define SPI_ENABLE			1
#define SPI_DISABLE			0

#define SPI_INT_ENABLE		1
#define SPI_INT_DISABLE		0

#endif /* SPI_PRIVATE_H_ */
