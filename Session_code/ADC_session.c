#include "../STD_Types.h"
#include "../BIT_MATH.h"

#include ".././MCAL_AVR/DIO/DIO_int.h"
#include ".././MCAL_AVR/GIE/GIE_int.h"
#include ".././MCAL_AVR/EXTI/EXTI_int.h"
#include ".././MCAL_AVR/ADC/ADC_int.h"

#include ".././HAL/Seg7/Seg7_int.h"
#include ".././HAL/LCD/LCD_int.h"
#include ".././HAL/KPD/KPD_int.h"

#include "util/delay.h"
int main_ADC(void){
	//lab_1_ADC();
	//lab_2_ADC();



	while(1){

	}
	return 0;
}

void lab_1_ADC(){
	u16 digital=0;
	u32 Analog =0;
	//LED 1
	DIO_SetPinDirection(PORTB,PIN_0,Output);
	DIO_SetPinValue(PORTB,PIN_0,LOW);
	//LED 2
	DIO_SetPinDirection(PORTB,PIN_1,Output);
	DIO_SetPinValue(PORTB,PIN_1,LOW);
	//LED 3
	DIO_SetPinDirection(PORTB,PIN_2,Output);
	DIO_SetPinValue(PORTB,PIN_2,LOW);


	//ADC pin
	DIO_SetPinDirection(PORTA,PIN_2,Input);
	ADC_Init();
	while(1){
		digital = ADC_Read(Channel_2);
		Analog = (((u32)digital*5000)/1024);

		if(Analog<1500){
			DIO_SetPinValue(PORTB,PIN_0,HIGH);
			DIO_SetPinValue(PORTB,PIN_1,LOW);
			DIO_SetPinValue(PORTB,PIN_2,LOW);
		}else if(Analog >=1500 && Analog<3000){
			DIO_SetPinValue(PORTB,PIN_0,LOW);
			DIO_SetPinValue(PORTB,PIN_1,HIGH);
			DIO_SetPinValue(PORTB,PIN_2,LOW);
		}else{
			DIO_SetPinValue(PORTB,PIN_0,LOW);
			DIO_SetPinValue(PORTB,PIN_1,LOW);
			DIO_SetPinValue(PORTB,PIN_2,HIGH);
		}

		//_delay_ms(1000);
	}

}
void lab_2_ADC(){
	u16 digital=0;
	u32 Analog =0;

	//ADC pin
	DIO_SetPinDirection(PORTA,PIN_2,Input);
	ADC_Init();
	LCD_init();
	while(1){
		digital = ADC_Read(Channel_2);
		Analog = (((u32)digital*5000)/1024);


		LCD_WriteString((u8*)"Milli volt= ");

		LCD_WriteChar((Analog/1000)+48);
		LCD_WriteChar(((Analog%1000)/100)+48);
		LCD_WriteChar(((Analog%100)/10)+48);
		LCD_WriteChar(((Analog%10))+48);

		LCD_WriteString((u8*)" mv");
		//_delay_ms(1000);

		LCD_WriteCommand(lcd_Clear);


	}
}
