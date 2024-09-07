/*
 * SPI_prgm.c
 *
 *  Created on: Sep 3, 2024
 *      Author: salma
 */

#include "../../STD_Types.h"
#include "../../BIT_MATH.h"
#include "SPI_prv.h"
#include "SPI_int.h"

void SPI_voidMasterInit(void){
//SELECT MASTER , ENABLE SPI
	SET_BIT(SPCR_Register,MSTR);
	SET_BIT(SPCR_Register,SPE);
}
void SPI_voidSlaveInit(void){
	CLR_BIT(SPCR_Register,MSTR);
	SET_BIT(SPCR_Register,SPE);
}
u8 SPI_u8Tranceive(u8 copy_u8Data){
	SPCR_Register = copy_u8Data;
	while(GET_BIT(SPSR_Register,SPIF)==0);
	return SPDR_Register;
}
