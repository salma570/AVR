/*
 * UART_prv.h
 *
 *  Created on: Sep 2, 2024
 *      Author: salma
 */

#ifndef MCAL_AVR_UART_UART_PRV_H_
#define MCAL_AVR_UART_UART_PRV_H_


#define UDR_Register     *((volatile u8 *)(0x2C))
#define UCSRA_Register   *((volatile u8 *)(0x2B))
#define UCSRB_Register   *((volatile u8 *)(0x2A))
#define UCSRC_Register   *((volatile u8 *)(0x40))
#define UBRRL_Register   *((volatile u8 *)(0x29))


#define RXEN 4
#define TXEN 3

#define UDRE 5

#define URSCL 7

#define UCSZ0 1
#define UCSZ1 2
#define UCSZ2 2

#endif /* MCAL_AVR_UART_UART_PRV_H_ */
