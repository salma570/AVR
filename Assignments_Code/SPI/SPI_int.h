/*
 * SPI_prv.h
 *
 *  Created on: Sep 3, 2024
 *      Author: salma
 */

#ifndef MCAL_AVR_SPI_SPI_PRV_H_
#define MCAL_AVR_SPI_SPI_PRV_H_

void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);
u8 SPI_u8Tranceive(u8 copy_u8Data);


#endif /* MCAL_AVR_SPI_SPI_PRV_H_ */
