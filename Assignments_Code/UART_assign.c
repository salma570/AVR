

//these 2 functions should be in the main file in separate projects 
//in the vid I sent from the mc to itself instead 





#include "STD_Types.h"
#include "BIT_MATH.h"
#include "./MCAL_AVR/DIO/DIO_int.h"
#include "./HAL/KPD/KPD_int.h"
#include "./MCAL_AVR/UART/UART_int.h"
#include "./MCAL_AVR/ADC/ADC_int.h"
#include "./MCAL_AVR/Timers/TMR_int.h"
#include "util/delay.h"


void UART_mc1(){

	KPD_init();
	TIM1_voidinit();

	DIO_SetPortDirection(PORTA,PortOut);


	switch(KPD_GetKey()){
			case 0: UART_voidTransmit(1); 	 break;
			case 1: UART_voidTransmit(2);  break;
			case 2: UART_voidTransmit(3);  break;
			case 3: UART_voidTransmit(4);  break;
			default:UART_voidTransmit(0);
			}

	while(1){

	}

}

void UART_mc2(){
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
