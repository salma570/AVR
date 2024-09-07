/*
 * main.c
 *
 *  Created on: Aug 12, 2024
 *      Author: salma
 */
#include "../STD_Types.h"
#include "../BIT_MATH.h"
#include <util/delay.h>
#include ".././MCAL_AVR/DIO/DIO_int.h"


void main_transistor(void){
	//	DC
	//	while(1){
	//		DIO_SetPinDirection(PORTA,PIN0,Output);
	//		DIO_SetPinValue(PORTA,PIN0,HIGH);
	//		_delay_ms(1000);
	//		DIO_SetPinValue(PORTA,PIN0,LOW);
	//		_delay_ms(1000);
	//	}

	//	buzzer
	//	while(1){
	//		DIO_SetPinDirection(PORTA,PIN0,Output);
	//		DIO_SetPinValue(PORTA,PIN0,HIGH);
	//		DIO_SetPinDirection(PORTB,PIN0,Input);
	//		DIO_SetPinValue(PORTB,PIN0,HIGH);
	//	}


//	4 transis > H-Bridge
//	DIO_SetPinDirection(PORTB,PIN0,Output);
//	DIO_SetPinDirection(PORTA,PIN0,Output);
//
//	while(1){
//
//		DIO_SetPinValue(PORTA,PIN0,HIGH);
//		DIO_SetPinValue(PORTB,PIN0,LOW);
//		_delay_ms(200);
//		DIO_SetPinValue(PORTA,PIN0,LOW);
//		DIO_SetPinValue(PORTB,PIN0,HIGH);
//		_delay_ms(2000);
//	}


	//DIO_SetPinDirection(PORTD,PIN_7,Output);
	//	DIO_SetPinDirection(PORTD,PIN_6,Output);
	//	while(1){
	//
	//		DIO_SetPinValue(PORTD,PIN_6,LOW);
	//		DIO_SetPinValue(PORTD,PIN_7,HIGH);
	//		_delay_ms(1000);
	//		DIO_SetPinValue(PORTD,PIN_6,HIGH);
	//		DIO_SetPinValue(PORTD,PIN_7,LOW);
	//		_delay_ms(1000);
	//	}

	//stepper motor
	//	DIO_SetPortDirection(PORTA, PortOut);
	//	for(int i=0; i<512;i++){
	//		DIO_SetPinValue(PORTA,PIN_0,HIGH);
	//		DIO_SetPinValue(PORTA,PIN_1,LOW);
	//		DIO_SetPinValue(PORTA,PIN_2,LOW);
	//		DIO_SetPinValue(PORTA,PIN_3,LOW);
	//
	//		_delay_ms(10);
	//		DIO_SetPinValue(PORTA,PIN_0,LOW);
	//		DIO_SetPinValue(PORTA,PIN_1,HIGH);
	//		DIO_SetPinValue(PORTA,PIN_2,LOW);
	//		DIO_SetPinValue(PORTA,PIN_3,LOW);
	//		_delay_ms(10);
	//		DIO_SetPinValue(PORTA,PIN_0,LOW);
	//		DIO_SetPinValue(PORTA,PIN_1,LOW);
	//		DIO_SetPinValue(PORTA,PIN_2,HIGH);
	//		DIO_SetPinValue(PORTA,PIN_3,LOW);
	//		_delay_ms(10);
	//		DIO_SetPinValue(PORTA,PIN_0,LOW);
	//		DIO_SetPinValue(PORTA,PIN_1,LOW);
	//		DIO_SetPinValue(PORTA,PIN_2,LOW);
	//		DIO_SetPinValue(PORTA,PIN_3,HIGH);
	//		_delay_ms(10);
	//	}


	while(1){

	}

}

