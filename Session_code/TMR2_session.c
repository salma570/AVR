/*
 * TMR1_session.c
 *
 *  Created on: Sep 3, 2024
 *      Author: salma
 */


#include "../STD_Types.h"
#include "../BIT_MATH.h"

#include ".././MCAL_AVR/DIO/DIO_int.h"
#include ".././MCAL_AVR/Timers/Tmr_int.h"
#include ".././MCAL_AVR/ADC/ADC_int.h"



void mappingpot_toServoMotor(){
	u16 digital = 0;
	u32 Value =0;


	//changing using pot &
	ADC_Init();
	TIM1_voidinit();

	//ADC Pin
	DIO_SetPinDirection(PORTA,PIN_0,Input);

	//oc1A> pwm signal
	DIO_SetPinDirection(PORTD,PIN_5,Output);

	while(1){
		digital = ADC_Read(Channel_0);
		//mapping
		Value = Mapping(1023,0,2500,500,digital);
		TIM1_void_CTC_SetRegValue(Value);

		//top value reg
		TIM1_voidISRSetRegValue(20000);
	}

}
void LED_onOFF(){
	//fast pmw MODE TIMR0
	u16 digital = 0;
	u32 Value =0;


	//changing using pot &
	ADC_Init();
	TIM0_voidinit();

	//ADC Pin
	DIO_SetPinDirection(PORTA,PIN_0,Input);

	//oco> pwm signal
	DIO_SetPinDirection(PORTB,PIN_3,Output);

	while(1){
		digital = ADC_Read(Channel_0);
		//mapping
		Value = Mapping(1023,0,255,0,digital);
		TIM0_voidCTCSetRegValue(Value);
	}
}
void changepot_buzzerSound(){

	//CTC MODE TIMR0
	u16 digital = 0;
	u32 Value =0;

	//changing using pot &
	ADC_Init();
	TIM0_voidinit();

	//ADC Pin
	DIO_SetPinDirection(PORTA,PIN_0,Input);

	//oco> toggle
	DIO_SetPinDirection(PORTB,PIN_3,Output);

	while(1){
		digital = ADC_Read(Channel_0);
		//mapping
		Value = mapping(1023,0,255,0,digital);
		TIM0_voidCTCSetRegValue(Value);
	}

}
