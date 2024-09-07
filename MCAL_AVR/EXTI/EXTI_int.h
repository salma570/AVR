/*
 * EXTI_int.h
 *
 *  Created on: Aug 25, 2024
 *      Author: salma
 */

#ifndef MCAL_AVR_EXTI_EXTI_INT_H_
#define MCAL_AVR_EXTI_EXTI_INT_H_


#define EXTI0 0
#define EXTI1 1
#define EXTI2 2

#define FallingEdge 0
#define RisingEdge 1
#define onchange 2
#define LowLevel 3


void EXTI_SetTriggerMode();
void EXTI_Enable(u8 Copy_u8IntNumber);
void EXTI_Disable(u8 Copy_u8IntNumber);
void EXTI0_CallBackFunction(void(*ptr)(void));
void EXTI1_CallBackFunction(void(*ptr)(void));
void EXTI2_CallBackFunction(void(*ptr)(void));

#endif /* MCAL_AVR_EXTI_EXTI_INT_H_ */
