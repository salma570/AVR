/*
 * SPI_assign.c
 *
 *  Created on: Sep 9, 2024
 *      Author: salma
 */


#include "STD_Types.h"
#include "BIT_MATH.h"
#include "./MCAL_AVR/DIO/DIO_int.h"
#include "./MCAL_AVR/SPI/SPI_int.h"
#include "./MCAL_AVR/ADC/ADC_int.h"
#include <util/delay.h>
//each main set in a diffrent project

void main(void){
	DIO_SetPinDirection(PORTB,PIN_5,Output); //MOSI
	DIO_SetPinDirection(PORTB,PIN_6,Input); //MISO
	DIO_SetPinDirection(PORTB,PIN_7,Output); //CLK
	DIO_SetPinDirection(PORTB,PIN_4,Input); //CLK
	DIO_SetPinValue(PORTB,PIN_4,HIGH);

	SPI_voidMasterInit();

	//ADC pin
	DIO_SetPinDirection(PORTA,PIN_0,Input);

	ADC_Init();
	u16 digital =0;
	u32 temp =0;


	while(1){
		digital = ADC_Read(Channel_0);
		temp = ((((u32)digital*5000)/1024)/10); //GET TEMP VALUE

		if(temp>=26){
			(void)SPI_u8Tranceive(1);
		}else{
			(void)SPI_u8Tranceive(0);
		}
		_delay_ms(10);

	}
}
