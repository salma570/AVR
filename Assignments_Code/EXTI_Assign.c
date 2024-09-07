#include "../STD_Types.h"
#include "../BIT_MATH.h"

#include ".././MCAL_AVR/DIO/DIO_int.h"
#include ".././MCAL_AVR/GIE/GIE_int.h"
#include ".././MCAL_AVR/EXTI/EXTI_int.h"

#include "util/delay.h"

void DC_onoff(void);

void EXTI_main(void){

	//DC motor
	DIO_SetPinDirection(PORTA,PIN_0,Output);
	DIO_SetPinValue(PORTA,PIN_0,LOW);

	//button > D2,D1 OR B2 >> P.2
	DIO_SetPinDirection(PORTD,PIN_3,Input);
	DIO_SetPinValue(PORTD,PIN_3,HIGH);


	EXTI_SetTriggerMode();
	EXTI1_CallBackFunction(DC_onoff);

	EXTI_Enable(EXTI1);
	GIE_Enable();

	while(1){

	}

}

void DC_onoff(void){ // toggle
	static u8 i=0;
	if(i==0){
		DIO_SetPinValue(PORTA,PIN_0,HIGH);
		i=1;
	}else{
		DIO_SetPinValue(PORTA,PIN_0,LOW);
		i=0;
	}
}
