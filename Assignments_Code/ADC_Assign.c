#include "../STD_Types.h"
#include "../BIT_MATH.h"

#include ".././MCAL_AVR/DIO/DIO_int.h"
#include ".././MCAL_AVR/ADC/ADC_int.h"

#include "util/delay.h"


void ADCAssign_main(void){
	u16 digital =0;
	u32 Analog =0;

	ADC_Init();
	DIO_SetPortDirection(PORTA,PortIn);

	DIO_SetPinDirection(PORTC,PIN_3,Output);
	DIO_SetPinValue(PORTC,PIN_3,LOW);


	while(1){
		digital = ADC_Read(Channel_0);
		Analog = (((u32)digital*5000)/1024);
		if(Analog<1500){
			DIO_SetPinValue(PORTC,PIN_3,LOW);
		}else{
			DIO_SetPinValue(PORTC,PIN_3,HIGH);
		}
		_delay_ms(1000);

	}

}

