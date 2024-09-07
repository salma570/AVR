#include "../STD_Types.h"
#include "../BIT_MATH.h"
#include ".././MCAL_AVR/DIO/DIO_int.h"
#include ".././MCAL_AVR/ADC/ADC_int.h"
#include ".././HAL/LCD/LCD_int.h"


#include "util/delay.h"

void AnalogSensors_main(){

	//LM35
	ADC_Init();
	LCD_init();

	//ADC pin
	u16 digital =0;
	u32 Analog =0;
	u32 temp =0;

	DIO_SetPinDirection(PORTA,PIN_0,Input);

	while(1){
		digital = ADC_Read(Channel_0);
		Analog = (((u32)digital*5000)/1024);
		temp = Analog/10;
		LCD_WriteCommand(lcd_Clear);
		LCD_WriteString((u8*)"temperature = ");
		LCD_WriteCommand((temp/10)+48);
		LCD_WriteCommand((temp%10)+48);
		LCD_WriteChar('C');

		_delay_ms(2000);

	}

	//LDR

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
