/*
 * TMR1_session.c
 *
 *  Created on: Sep 3, 2024
 *      Author: salma
 */


#include "../STD_Types.h"
#include "../BIT_MATH.h"

#include ".././MCAL_AVR/DIO/DIO_int.h"
#include ".././MCAL_AVR/GIE/GIE_int.h"
#include ".././MCAL_AVR/EXTI/EXTI_int.h"
#include ".././MCAL_AVR/Timers/Tmr_int.h"

void function_tmr(void);
int TMR1_main(void){ //ctc mode
	TIM0_voidinit();

	//LED > OC0
	DIO_SetPinDirection(PORTB,PIN_3,Output);

	TIM0_voidCTCIntEnable();
	TIM0_voidCTCSetRegValue(200);
	TIM0_voidCTCCallBack(function_tmr);

	GIE_Enable();




	while(1){

	}

	return 0;
}
//cfg>> normal_WGM

void OVF_example(){
	/*
	 *  1 sec > toggle led
	 *  tick time > 8 prescaler system frequency = 8 MHz
	 *  tick time 1 micro sec
	 *  overflow time = 256 microsec
	 *  ovf count = 1 (tick time) /(256 *10^-6) = 3906.25 > check counter when it hits 3907
	 *  preload = (1-0.25)*256 = 192
	 *
	 *
	 */
	TIM0_voidinit();

	//LED
	DIO_SetPinDirection(PORTA,PIN_0,Output);
	DIO_SetPinValue(PORTA,PIN_0,LOW);

	TIM0_voidOVFSetRegValue(200);
	while(1){

	}

}
void function_tmr(void){
	static u32 counter =0;
	counter++;

	if(counter==3907){
		static u8 i=0;
		if(i==0){
			i =1;
			DIO_SetPinValue(PORTA,PIN_0,LOW);

		}else{
			i =0;
			DIO_SetPinValue(PORTA,PIN_0,HIGH);
		}
		counter = 0;
		TIM0_voidOVFSetRegValue(192);

	}
}
