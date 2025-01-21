/*
 * EEPROM_int.h
 *
 *  Created on: Sep 5, 2024
 *      Author: salma
 */

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

#define Device_0 0 //gnd
#define Device_1 1 //vcc

void EEPROM_VoidWrite(u16 Copy_u16byteAdress, u8 Copy_u8Data, u8 Copy_u8device);
u8 EEPROM_u8Read(u16 Copy_u16byteAdress, u8 Copy_u8device);
#endif /* EEPROM_INT_H_ */
