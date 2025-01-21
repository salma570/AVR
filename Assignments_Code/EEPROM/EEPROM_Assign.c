#include "STD_Types.h"
#include "BIT_MATH.h"

#include "./MCAL_AVR/DIO/DIO_int.h"
#include "./MCAL_AVR/I2C/TWI_Interface.h"
#include "./MCAL_AVR/EEPROM/EEPROM_int.h"

#include <util/delay.h>


void main(){
	u8 value =0;


	//store value in EEPROM
	TWI_voidMasterInit(1);
	EEPROM_VoidWrite(5,7,Device_0);

	//Retrieve value in EEPROM
	value = EEPROM_u8Read(5,Device_0);

	//display retrieved value as binary on LED's
	DIO_SetPortDirection(PORTA,PortOut);
	DIO_SetPortValue(PORTA,value);



	while(1){

	}

}
