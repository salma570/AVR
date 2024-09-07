/*
 * seg7_session.c
 *
 *  Created on: Aug 28, 2024
 *      Author: salma
 */
#include "../STD_Types.h"
#include "../BIT_MATH.h"

#include <avr/io.h>
#include <util/delay.h>

//#include ".././MCAL_AVR/DIO/DIO_int.h"

#define OUTPUT_HIGH 255
#define SEGMENT_PORT PORTC
#define SEGMENT_DDR DDRC

#define SEGMENT_PORT_decimal PORTD // 0,1,2,3,4,5,6,7,8,9
#define SEGMENT_DDR_decimal DDRD // 10,20,30, etc

#define LED_PORT PORTA
#define LED_DDR DDRA

#define GREEN_PIN 2
#define YELLOW_PIN 1
#define RED_PIN 0


int ARR [10]={
		//0b(dot)gfedcba
		// wires  D0> a && com >vcc
		// anode
		0b00111111,
		0b00000110,
		0b01011011,
		0b01001111,
		0b01100110,
		0b01101101,
		0b01111101,
		0b00000111,
		0b01111111,
		0b01101111
};

void main_seg7Code(void);

void main_seg7Code(){
	//SEG7_init();
	//SEG7_DisplayNumber(2);

//	//LED A0
//	//DIO_SetPinDirection(PORTA,PIN_0,Output);
//	//DIO_SetPinValue(PORTA,PIN_0,LOW);
//	DIO_SetPortDirection(PORTA,PortOut);
//	DIO_SetPortValue(PORTA,0);
//
//	//Button B0
//	//DIO_SetPinDirection(PORTB,PIN_0,Input);
//	//Pull-Up
//	//DIO_SetPinValue(PORTB,PIN_0,HIGH);
//
//	u8 LocalVariable;
//	while(1){
//		DIO_GetPinValueByPtr(PORTB,PIN_0,&LocalVariable);
//		if(LocalVariable==0)
//		{
//			//DIO_SetPortValue(PORTA,255);
//			DIO_SetPinValue(PORTA,PIN_0,HIGH);
//		}
//		else
//		{
//			//DIO_SetPortValue(PORTA,0);
//			DIO_SetPinValue(PORTA,PIN_0,LOW);
//		}
//	}

}

void Count(u8 CountTonumber) { //Using _2segdisplays
	SEGMENT_DDR = OUTPUT_HIGH;
	SEGMENT_DDR_decimal = OUTPUT_HIGH;
	for(int i = 1; i<= CountTonumber;i++){
		u8 tens = i / 10;
		u8 ones = i % 10;
		SEGMENT_PORT = ~ARR[ones];
		SEGMENT_PORT_decimal = ~ARR[tens];
		_delay_ms(500);

	}
}
void Count_toNinex2(void) {
	DDRA = OUTPUT_HIGH;
	int i = 0, dir = 1;
	while (1) {
		PORTA = (i < 9 && dir == 1) ? (dir = 1, ~ARR[i++]) : ((i == 1) ? (dir = 1) : (dir = 0), ~ARR[i--]);
		_delay_ms(500);
	}
}
void Count_toNine(void) {
	DDRD = OUTPUT_HIGH;
	while (1) {
		for (int i = 0; i < 10; i++) {
			PORTD = ~ARR[i];
			_delay_ms(2000);
		}
	}
}
