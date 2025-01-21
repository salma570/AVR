/*
 * UART_asssign.c
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
#include "util/delay.h"



void main(){
	UART_voidInit();
	TIM1_voidinit();

	//OC0 pmw signal

	DIO_SetPinDirection(PORTD,PIN_5,Output);
	TIM1_voidISRSetRegValue(20000);

	while(1){
		//set compare match value >  UART_voidTransmit(value)
		// in mc 2:UART_voidReceive() & TIM1_void_CTC_SetRegValue() & TIM1_voidISRSetRegValue

		switch(UART_voidReceive()){
		case 0: TIM1_void_CTC_SetRegValue(10); 	 break;
		case 1: TIM1_void_CTC_SetRegValue(4000);  break;
		case 2: TIM1_void_CTC_SetRegValue(6000);  break;
		case 3: TIM1_void_CTC_SetRegValue(8000);  break;
		default:TIM1_void_CTC_SetRegValue(0);
		}
		TIM1_voidISRSetRegValue(20000);
		_delay_ms(1000);

	}

}
