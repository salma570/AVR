/*
 * UART_prgm.c
 *
 *  Created on: Sep 2, 2024
 *      Author: salma
 */


#include "../../STD_Types.h"
#include "../../BIT_MATH.h"

#include "UART_int.h"
#include "UART_prv.h"

void UART_voidInit(void){
	u8 Local_variable =0;
	SET_BIT(Local_variable,URSCL);

	SET_BIT(Local_variable,UCSZ1);
	SET_BIT(Local_variable,UCSZ0);
	CLR_BIT(UCSRB_Register,UCSZ2);

	UCSRC_Register = Local_variable;

	//9600 baude rate
	UBRRL_Register = 51;

	//enable receive and transmit
	SET_BIT(UCSRB_Register,RXEN);
	SET_BIT(UCSRB_Register,TXEN);

}

void UART_voidTransmit(u8 Copy_u8Data){
	while((GET_BIT(UCSRA_Register, UDRE))==0);
	UDR_Register = Copy_u8Data;
}

u8 UART_voidReceive(void){
	while((GET_BIT(UCSRA_Register, 7))==0);
	return UDR_Register;
}
