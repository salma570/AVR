#include "../STD_Types.h"
#include "../BIT_MATH.h"
#include <util/delay.h>

#include ".././MCAL_AVR/DIO/DIO_int.h"


void Timers1_Assign(void){
	//	4 transis > H-Bridge
	DIO_SetPinDirection(PORTB,PIN_0,Output);
	DIO_SetPinDirection(PORTA,PIN_0,Output);

	DIO_SetPinDirection(PORTD,PIN_0,Output);
	DIO_SetPinDirection(PORTD,PIN_1,Output);
	DIO_SetPinDirection(PORTD,PIN_2,Output);

	while(1){

		DIO_SetPinValue(PORTD,PIN_0,HIGH);

		DIO_SetPinValue(PORTA,PIN_0,HIGH);
		DIO_SetPinValue(PORTB,PIN_0,LOW);



		_delay_ms(5000);

		DIO_SetPinValue(PORTD,PIN_0,LOW);
		DIO_SetPinValue(PORTD,PIN_1,HIGH);

		DIO_SetPinValue(PORTA,PIN_0,LOW);
		DIO_SetPinValue(PORTB,PIN_0,HIGH);


		_delay_ms(3000);

		DIO_SetPinValue(PORTA,PIN_0,LOW);
		DIO_SetPinValue(PORTB,PIN_0,LOW);

		DIO_SetPinValue(PORTD,PIN_1,LOW);
		DIO_SetPinValue(PORTD,PIN_2,HIGH);
		_delay_ms(5000);


		DIO_SetPinValue(PORTD,PIN_2,LOW);
	}


}

