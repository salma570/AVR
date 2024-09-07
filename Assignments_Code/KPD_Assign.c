#include "../STD_Types.h"
#include "../BIT_MATH.h"

#include <util/delay.h>


#include ".././MCAL_AVR/DIO/DIO_int.h"

#include ".././HAL/LCD/LCD_int.h"
#include ".././HAL/KPD/KPD_int.h"

//#define LCD_DataPort PORTD /* Select PORTA or PORTB or PORTC or PORTD */
//#define LCD_CtrlPort PORTA /* Select PORTA or PORTB or PORTC or PORTD */
//
//#define RS_Pin PIN_0 /* Select a pin from PIN_0 to PIN_7 */
//#define RW_Pin PIN_1 /* Select a pin from PIN_0 to PIN_7 */
//#define E_Pin PIN_2 /* Select a pin from PIN_0 to PIN_7 */
//
//
//
//
//
//
//#define KPD_PORT PORTB
//
//#define ROW_start PIN_0
//#define ROW_end PIN_3
//
//#define COL_start PIN_4
//#define COL_end PIN_7






#define LED_PORT PORTC
#define KPD_PORT PORTB



#define Right 1
#define Left 0


void flash500();
void shift(u8 KPD_number, u8 RightOrLeft);
void converge(u8 KPD_number);
void diverge(u8 KPD_number);
void PingPongEffect(u8 KPD_number);
void ConvergeDiverge(u8 KPD_number);
void increment(u8 KPD_number);

void main_KPDAssign(){
	DIO_SetPortDirection(LED_PORT,PortOut);
	LCD_init();
	KPD_init();

	while(1){
		switch(KPD_GetKey()){
		case 0:
			LCD_WriteString((u8*)"flash every 500 ms");
			flash500();//DIP switch > 1 on flash every 500 ms
			break;
		case 1:
			LCD_WriteString((u8*)"shifting left every 250ms");
			shift(1,Left); //DIP switch > 2 on > shifting left every 250ms
			break;
		case 2:
			LCD_WriteString((u8*)"shifting right every 250ms");
			shift(2,Right); //DIP switch > 3 on > shifting right every 250ms
			break;
		case 3:
			LCD_WriteString((u8*)"converging LED every 300ms");
			converge(3);//DIP switch > 4 on > converging LED every 300ms
			break;
		case 4:
			LCD_WriteString((u8*)"diverging LED every 300ms");
			diverge(4); //DIP switch > 5 on > diverging LED every 300ms
			break;
		case 5:
			LCD_WriteString((u8*)"PingPong Effect");
			PingPongEffect(5);//DIP switch > 6 on
			break;
		case 6:
			LCD_WriteString((u8*)"increment");
			increment(6);//DIP switch > 7 on
			break;
		case 7:
			LCD_WriteString((u8*)"Converge & Diverge");
			ConvergeDiverge(7); //DIP switch > 8 on
			break;

		}
		DIO_SetPortValue(LED_PORT,PortIn);
		LCD_WriteCommand(lcd_Clear);
	}
}

void PingPongEffect(u8 KPD_number){
	shift(KPD_number,Right);
	shift(KPD_number,Left);
}
void ConvergeDiverge(u8 KPD_number){

	converge(KPD_number);
	diverge(KPD_number);




}
void increment(u8 KPD_number){
	for(int i=0; i<8;i++){
		DIO_SetPinValue(LED_PORT,i,HIGH);
		_delay_ms(250);
	}
}

void diverge(u8 KPD_number){
	for(int i=1;i<=4;i++){
		DIO_SetPinValue(LED_PORT,i+3,HIGH);
		DIO_SetPinValue(LED_PORT,4-i,HIGH);
		_delay_ms(300);
		DIO_SetPinValue(LED_PORT,i+3,LOW);
		DIO_SetPinValue(LED_PORT,4-i,LOW);
	}
}
void converge(u8 KPD_number){
	for(int i=0; i<4;i++){
		DIO_SetPinValue(LED_PORT,i,HIGH);
		DIO_SetPinValue(LED_PORT,(7-i),HIGH);
		_delay_ms(300);
		DIO_SetPinValue(LED_PORT,i,LOW);
		DIO_SetPinValue(LED_PORT,(7-i),LOW);
	}
}
void flash500(){
	for(int i =0; i<2; i++){
		DIO_SetPortValue(LED_PORT,PortOut);
		_delay_ms(500);
		DIO_SetPortValue(LED_PORT,PortIn);
		_delay_ms(500);
	}
}
void shift(u8 KPD_number, u8 RightOrLeft){
	for(int i=0; i<8;i++){
		if(RightOrLeft == Right){
			DIO_SetPortValue(LED_PORT, (1 << i));
		}else if(RightOrLeft== Left){
			DIO_SetPortValue(LED_PORT,(128>>i));
		}
		_delay_ms(250);
	}
}
