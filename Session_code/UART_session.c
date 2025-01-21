#include "../STD_Types.h"
#include "../BIT_MATH.h"

#include ".././MCAL_AVR/DIO/DIO_int.h"
#include ".././MCAL_AVR/Timers/Tmr_int.h"
#include ".././MCAL_AVR/UART/UART_int.h"
#include ".././MCAL_AVR/SPI/SPI_int.h"

#include "util/delay.h"


void UART_session(){
		UART_voidInit();
		DIO_SetPinDirection(PORTD,PIN_1,Output);

		UART_voidTransmit('S');
		while(1){

		}
}
