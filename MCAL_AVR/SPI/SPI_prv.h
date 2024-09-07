/*
 * SPI_prv.h
 *
 *  Created on: Sep 3, 2024
 *      Author: salma
 */

#ifndef MCAL_AVR_SPI_SPI_PRV_H_
#define MCAL_AVR_SPI_SPI_PRV_H_

#define SPCR_Register   *((volatile u8 *)(0x2D))
#define SPSR_Register   *((volatile u8 *)(0x2E))
#define SPDR_Register   *((volatile u8 *)(0x2F))

#define MSTR 4
#define SPE 6
#define SPIF 7

#endif /* MCAL_AVR_SPI_SPI_PRV_H_ */
