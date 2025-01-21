/*
 * SPI_assign.c
 *
 *  Created on: Sep 9, 2024
 *      Author: salma
 */


#include "STD_Types.h"
#include "BIT_MATH.h"
#include "./MCAL_AVR/DIO/DIO_int.h"
#include "./MCAL_AVR/UART/UART_int.h"
#include "./MCAL_AVR/SPI/SPI_int.h"
#include "./MCAL_AVR/ADC/ADC_int.h"
#include <util/delay.h>
//each main set in a diffrent project



void SPI_main(){
	u8 x = 0;
	DIO_SetPinDirection(PORTD,PIN_0,Input);
	DIO_SetPortDirection(PORTA, PortOut);
//	UART_voidInit();
	SPI_voidSlaveInit();


	//dc moto pin
	DIO_SetPinDirection(PORTD,PIN_0,Output);
	DIO_SetPinValue(PORTD,PIN_0,LOW);
	while(1){
		x = SPI_u8Tranceive(0);
		if(x==0){
			DIO_SetPinValue(PORTD,PIN_0,LOW);
		}else{
			DIO_SetPinValue(PORTD,PIN_0,HIGH);
		}
		_delay_ms(10);
	}


}
