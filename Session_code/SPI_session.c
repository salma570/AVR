/*
 * SPI_session.c
 *
 *  Created on: Sep 9, 2024
 *      Author: salma
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "./MCAL_AVR/DIO/DIO_int.h"
#include "./HAL/KPD/KPD_int.h"
#include "./MCAL_AVR/UART/UART_int.h"
#include "./MCAL_AVR/ADC/ADC_int.h"
#include "./MCAL_AVR/Timers/TMR_int.h"
#include <util/delay.h>

void SPI_sessionCode(){
	//master
	u8 x =0;
		DIO_SetPinDirection(PORTB,PIN_5,Output); //MOSI

		DIO_SetPinDirection(PORTB,PIN_6,Input); //MISO

		DIO_SetPinDirection(PORTB,PIN_7,Output); //CLK

		DIO_SetPinDirection(PORTB,PIN_4,Input); //CLK
		DIO_SetPinValue(PORTB,PIN_4,HIGH);

		DIO_SetPinDirection(PORTA,PIN_0,Output); //CLK
		SPI_voidMasterInit();
		while(1){
			x = SPI_u8Tranceive(10);
			if(x ==70){
				DIO_SetPinValue(PORTA,PIN_0,HIGH);
			}

		}



}
//slave code

//	u8 x = 0;
//	DIO_SetPinDirection(PORTD,PIN_0,Input);
//	DIO_SetPortDirection(PORTA, PortOut);
//	UART_voidInit();
//
//	while(1){
//		x = UART_voidReceive();
//		switch(x){
//		case '1':
//			DIO_SetPinValue(PORTA,PIN_0,HIGH);
//			break;
//		case '2':
//			DIO_SetPinValue(PORTA,PIN_1,HIGH);
//			break;
//		case '3':
//			DIO_SetPinValue(PORTA,PIN_2,HIGH);
//			break;
//		}
//	}
//}



