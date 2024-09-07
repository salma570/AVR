/*
 * main.c
 *
 *  Created on: Aug 9, 2024
 *      Author: hp
 */
#include "../STD_Types.h"
#include "../BIT_MATH.h"

#include ".././MCAL_AVR/DIO/DIO_int.h"
#include ".././MCAL_AVR/GIE/GIE_int.h"
#include ".././MCAL_AVR/EXTI/EXTI_int.h"

#include ".././HAL/Seg7/Seg7_int.h"
#include ".././HAL/LCD/LCD_int.h"
#include ".././HAL/KPD/KPD_int.h"

#include "util/delay.h"

void func(void);
void EXTIsession_main(void)
{

	//LED
	DIO_SetPinDirection(PORTA,PIN_0,Output);
	DIO_SetPinValue(PORTA,PIN_0,LOW);

	//button > D2,D1 OR B2 >> P.2
	DIO_SetPinDirection(PORTD,PIN_2,Input);
	DIO_SetPinValue(PORTD,PIN_2,HIGH);


	EXTI_SetTriggerMode();
	EXTI0_CallBackFunction(func);

	EXTI_Enable(EXTI0);
	GIE_Enable();


	//button > D2,D1 OR B2 >> P.2
	DIO_SetPinDirection(PORTD,PIN_3,Input);
	DIO_SetPinValue(PORTD,PIN_3,HIGH);


	EXTI_SetTriggerMode();
	EXTI1_CallBackFunction(func);

	EXTI_Enable(EXTI1);
	GIE_Enable();


	//button > D2,D1 OR B2 >> P.2
	DIO_SetPinDirection(PORTB,PIN_2,Input);
	DIO_SetPinValue(PORTB,PIN_2,HIGH);


	EXTI_SetTriggerMode();
	EXTI2_CallBackFunction(func);

	EXTI_Enable(EXTI2);
	GIE_Enable();

	while(1){

	}

}
void func(void){ // toggleLED
	static u8 i=0;
	if(i==0){
		DIO_SetPinValue(PORTA,PIN_0,HIGH);
		i=1;
	}else{
		DIO_SetPinValue(PORTA,PIN_0,LOW);
		i=0;
	}

}
