/*
 * ADC_int.h
 *
 *  Created on: Aug 25, 2024
 *      Author: salma
 */

#ifndef MCAL_AVR_ADC_ADC_INT_H_
#define MCAL_AVR_ADC_ADC_INT_H_

 #define Channel_0 0
 #define Channel_1 1
 #define Channel_2 2
 #define Channel_3 3
 #define Channel_4 4
 #define Channel_5 5
 #define Channel_6 6
 #define Channel_7 7

#define Bit_mask 0b11100000

#define Interrupt_ON 1
#define Interrupt_OFF 0

#define AREF_Stop 0
#define AREF_AVCC 1
#define AREF_Internal 3

#define ALL_ADCH 1
#define ALL_ADCL 0

#define SingleEnded 0
#define PosDiffrential 1
#define NegDiffrential 2


#define prescaler_factor2 	0
#define prescaler_factor4	1
#define prescaler_factor8	2
#define prescaler_factor16	3
#define prescaler_factor32	4
#define prescaler_factor64	5
#define prescaler_factor128	6


#define Autotrigger_OFF 0
#define Autotrigger_enable 1

#define trigger_freeRunning 		0
#define trigger_AnalogComparator 	1
#define trigger_EXTI0				2
#define trigger_CompareMatch		3
#define trigger_Overflow0			4
#define trigger_CompareMatchB		5
#define trigger_Overflow1			6
#define trigger_Capture Event		7
#define Autotrigger_none 			8


void ADC_Init(void);
u16 ADC_Read(u8 Copy_u8Chanel);
u32 TO_ANALOG(u16 digital_o, u16 Multiplication_factor);


#endif /* MCAL_AVR_ADC_ADC_INT_H_ */
