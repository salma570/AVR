#include "../STD_Types.h"
#include "../BIT_MATH.h"
#include <util/delay.h>

#include ".././MCAL_AVR/DIO/DIO_int.h"

#include ".././HAL/LCD/LCD_int.h"


//#define LCD_DataPort PORTC /* Select PORTA or PORTB or PORTC or PORTD */
//#define LCD_CtrlPort PORTD /* Select PORTA or PORTB or PORTC or PORTD */
//
//#define RS_Pin PIN_0 /* Select a pin from PIN_0 to PIN_7 */
//#define RW_Pin PIN_1 /* Select a pin from PIN_0 to PIN_7 */
//#define E_Pin PIN_2 /* Select a pin from PIN_0 to PIN_7 */

void loop(void);

#define LED_PORT_DIOassign PORTA
#define LED_PIN_DIOassign  PIN_0

#define Button_port_DIOassign PORTB
#define Button_pin_DIOassign  PIN_0

void main_DIO_ASSIGN(){
	LCD_init();
	DIO_SetPinDirection(LED_PORT_DIOassign,LED_PIN_DIOassign,Output);

	DIO_SetPinDirection(Button_port_DIOassign,Button_pin_DIOassign,Input);
	DIO_SetPinValue(Button_port_DIOassign,Button_pin_DIOassign,HIGH);

	for(int i =0; i<10;i++){
		LCD_WriteChar(i+48);
		DIO_SetPinValue(LED_PORT_DIOassign,LED_PIN_DIOassign,HIGH);
		_delay_ms(1000);
		DIO_SetPinValue(LED_PORT_DIOassign,LED_PIN_DIOassign,HIGH);
		LCD_WriteCommand(lcd_Clear);
	}
	LCD_WriteCommand(lcd_Clear);
	LCD_WriteString((u8*)"LED ON");
	DIO_SetPinValue(LED_PORT_DIOassign,LED_PIN_DIOassign,HIGH);
	while(1)
	{

	}
}


//	LCD_WriteChar('1');
//	loop();
//	LCD_WriteChar('2');
//	loop();
//	LCD_WriteChar('3');
//	loop();
//	LCD_WriteChar('4');
//	loop();
//	LCD_WriteChar('5');
//	loop();
//	LCD_WriteChar('6');
//	loop();
//	LCD_WriteChar('7');
//	loop();
//	LCD_WriteChar('8');
//	loop();
//	LCD_WriteChar('9');
//	loop();


void loop(void){
	DIO_SetPinValue(LED_PORT_DIOassign,LED_PIN_DIOassign,HIGH);
	_delay_ms(1000);
	DIO_SetPinValue(LED_PORT_DIOassign,LED_PIN_DIOassign,LOW);
	LCD_WriteCommand(lcd_Clear);
}
