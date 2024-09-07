/*
 * main.c
 *
 *  Created on: Aug 12, 2024
 *      Author: salma
 */
#include "../STD_Types.h"
#include "../BIT_MATH.h"
#include <avr/io.h>
#include <util/delay.h>

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

void Count_assign(u8 CountTonumber);
void seg7_main(void);
static int ARR [10]={
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

void seg7_main(void){
	LED_DDR= 255;//output
	while(1){
		SET_BIT(LED_PORT,GREEN_PIN);
		Count_assign(10);
		CLR_BIT(LED_PORT,GREEN_PIN);
		SET_BIT(LED_PORT,YELLOW_PIN);
		Count_assign(3);
		CLR_BIT(LED_PORT,YELLOW_PIN);
		SET_BIT(LED_PORT,RED_PIN);
		Count_assign(10);
		CLR_BIT(LED_PORT,RED_PIN);
	}
}

void Count_assign(u8 CountTonumber) { //Using _2segdisplays
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
