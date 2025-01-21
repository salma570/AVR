/*
 * EEPROM_prm.c
 *
 *  Created on: Sep 5, 2024
 *      Author: salma
 */
#include "../../STD_Types.h"
#include "../../BIT_MATH.h"
#include "../I2C/TWI_Interface.h"
#include "EEPROM_int.h"
#include <util/delay.h>

void EEPROM_VoidWrite(u16 Copy_u16byteAdress, u8 Copy_u8Data, u8 Copy_u8device){
	u8 slaveAdress = 0;
	slaveAdress = 0b1010000|(Copy_u8device<<2)|(u8)(Copy_u16byteAdress>>8);

	//start
	TWI_voidStartCondition();
	TWI_voidSendSlaveAddressWithWrite(slaveAdress);
	TWI_voidSendData((u8)Copy_u16byteAdress);
	TWI_voidSendData(Copy_u8Data);
	TWI_voidStopCondition();
	_delay_ms(10);

}
u8 EEPROM_u8Read(u16 Copy_u16byteAdress, u8 Copy_u8device){
	u8 data =0;
	u8 slaveAdress = 0;
	slaveAdress = 0b1010000|(Copy_u8device<<2)|(u8)(Copy_u16byteAdress>>8);

	//start
	TWI_voidStartCondition();
	TWI_voidSendSlaveAddressWithWrite(slaveAdress);
	TWI_voidSendData((u8)Copy_u16byteAdress);
	//repeated start
	TWI_voidStartCondition();
	TWI_voidSendSLaveAddressWithRead(slaveAdress);
	data = TWI_u8RecieveData();
	TWI_voidStopCondition();
	return data;
}

