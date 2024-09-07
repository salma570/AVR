/*
 * Tmr_int.h
 *
 *  Created on: Aug 28, 2024
 *      Author: salma
 */

#ifndef MCAL_AVR_TIMERS_TMR_INT_H_
#define MCAL_AVR_TIMERS_TMR_INT_H_


#define  normal_WGM 0
#define  PMW 1
#define CTC 2
#define FAST_PMW 3

#define normal_COM 0
#define toggle 1
#define clear 2
#define set  3


#define noSource 0
#define noprescaling 1
#define clk_8 2
#define clk_64 3
#define clk_256 4
#define clk_1024 5
#define clk_EXT_fallingEdge 6
#define clk_EXT_RisingEdge 7


//********** TIMER 0
void TIM0_voidinit(void);

void TIM0_voidOVFIntEnable(void);
void TIM0_voidOVFCallBack(void(*ptr)(void));
void TIM0_voidOVFSetRegValue(u8 Copu_u8PreLoadValue);


void TIM0_voidCTCSetRegValue(u8 Copu_u8CompareValue);
void TIM0_voidCTCIntEnable(void);
void TIM0_voidCTCCallBack(void(*ptr)(void));

//********** TIMER 1
void TIM1_voidinit(void);
void TIM1_voidISRSetRegValue(u16 copy_u16TopVAlue);
void TIM1_void_CTC_SetRegValue(u16 copy_u16CompareVal);




#endif /* MCAL_AVR_TIMERS_TMR_INT_H_ */
