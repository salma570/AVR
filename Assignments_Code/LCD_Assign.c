

#include "../STD_Types.h"
#include "../BIT_MATH.h"

#include <util/delay.h>

#include ".././MCAL_AVR/DIO/DIO_int.h"
#include ".././HAL/LCD/LCD_int.h"

void main_LCDAssign(){
	LCD_init();
	while(1){
		for(int i = 0; i<=11;i++){//colomns
			if(i%2 ==0 ){
				LCD_GoTo(Line_1,i);
			}else{
				LCD_GoTo(Line_2,i);
			}
			LCD_WriteString((u8*)"SALMA");

			_delay_ms(500);
			LCD_WriteCommand(lcd_Clear);
		}
	}
}
