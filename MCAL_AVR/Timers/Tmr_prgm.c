/*
 * tmr_prgm.c
 *
 *  Created on: Aug 28, 2024
 *      Author: salma
 */

#include "../../STD_Types.h"
#include "../../BIT_MATH.h"
#include "Tmr_prv.h"
#include "Tmr_cfg.h"
#include "Tmr_int.h"

void(*OVF0_Globalptr)(void)=0;
void(*CTC0_Globalptr)(void)=0;

void TIM0_voidinit(void){
	// mode (normal, ctc or pmw)
# if(TM0_Waveform_Generation_Mode == normal_WGM)
	CLR_BIT(TCCR0_Register,WGM01);
	CLR_BIT(TCCR0_Register,WGM00);
# elif(TM0_Waveform_Generation_Mode == PMW)
	CLR_BIT(TCCR0_Register,WGM01);
	SET_BIT(TCCR0_Register,WGM00);
# elif(TM0_Waveform_Generation_Mode == CTC)
	SET_BIT(TCCR0_Register,WGM01);
	CLR_BIT(TCCR0_Register,WGM00);
# elif(TM0_Waveform_Generation_Mode == FAST_PMW)
	SET_BIT(TCCR0_Register,WGM01);
	SET_BIT(TCCR0_Register,WGM00);
#endif



# if(TM0_Compare_Match_Output_Mode == normal_COM)
	CLR_BIT(TCCR0_Register,COM01);
	CLR_BIT(TCCR0_Register,COM00);
# elif(TM0_Compare_Match_Output_Mode == toggle)
	CLR_BIT(TCCR0_Register,COM01);
	SET_BIT(TCCR0_Register,COM00);
# elif(TM0_Compare_Match_Output_Mode == clear)
	SET_BIT(TCCR0_Register,COM01);
	CLR_BIT(TCCR0_Register,COM00);
# elif(TM0_Compare_Match_Output_Mode == set)
	SET_BIT(TCCR0_Register,COM01);
	SET_BIT(TCCR0_Register,COM00);
#endif


# if(TM0_Clock_Select == noSource)
	CLR_BIT(TCCR0_Register,CS02);
	CLR_BIT(TCCR0_Register,CS01);
	CLR_BIT(TCCR0_Register,CS00);
# elif(TM0_Clock_Select == noprescaling)
	CLR_BIT(TCCR0_Register,CS02);
	CLR_BIT(TCCR0_Register,CS01);
	SET_BIT(TCCR0_Register,CS00);
# elif(TM0_Clock_Select == clk_8)
	CLR_BIT(TCCR0_Register,CS02);
	SET_BIT(TCCR0_Register,CS01);
	CLR_BIT(TCCR0_Register,CS00);
# elif(TM0_Clock_Select == clk_64)
	CLR_BIT(TCCR0_Register,CS02);
	SET_BIT(TCCR0_Register,CS01);
	SET_BIT(TCCR0_Register,CS00);
# elif(TM0_Clock_Select ==clk_256 )
	SET_BIT(TCCR0_Register,CS02);
	CLR_BIT(TCCR0_Register,CS01);
	CLR_BIT(TCCR0_Register,CS00);
# elif(TM0_Clock_Select == clk_1024)
	SET_BIT(TCCR0_Register,CS02);
	CLR_BIT(TCCR0_Register,CS01);
	SET_BIT(TCCR0_Register,CS00);
# elif(TM0_Clock_Select == clk_EXT_fallingEdge)
	SET_BIT(TCCR0_Register,CS02);
	SET_BIT(TCCR0_Register,CS01);
	CLR_BIT(TCCR0_Register,CS00);
# elif(TM0_Clock_Select == clk_EXT_RisingEdge)
	SET_BIT(TCCR0_Register,CS02);
	SET_BIT(TCCR0_Register,CS01);
	SET_BIT(TCCR0_Register,CS00);
#endif
}
//******** OVERFLOW MODE
void TIM0_voidOVFSetRegValue(u8 Copu_u8PreLoadValue){
	TCNT0_Register = Copu_u8PreLoadValue;
}
void TIM0_voidOVFIntEnable(void){
	SET_BIT(TIMSK_Register,TOIE0);
}
void TIM0_voidOVFCallBack(void(*ptr)(void)){
	OVF0_Globalptr = ptr;
}
void __vector_11 (void) __attribute__ ((signal,used,externally_visible)) ; \
void __vector_11(void){
	OVF0_Globalptr();
}

//************ CTC MODE
void TIM0_voidCTCSetRegValue(u8 Copu_u8CompareValue){
	TCNT0_Register = Copu_u8CompareValue;
}
void TIM0_voidCTCIntEnable(void){
	SET_BIT(TIMSK_Register,OCIE0);
}
void TIM0_voidCTCCallBack(void(*ptr)(void)){
	CTC0_Globalptr = ptr;
}
void __vector_10 (void) __attribute__ ((signal,used,externally_visible)) ; \
void __vector_10(void){
	CTC0_Globalptr();
}
//************ pmw MODE

//***************************************************************




void TIM1_voidinit(void){
	SET_BIT(TCCR1A_Register,COM1A1);
	CLR_BIT(TCCR1A_Register,COM1A0);


	CLR_BIT(TCCR1A_Register,WGM00);
	SET_BIT(TCCR1A_Register,WGM11);
	SET_BIT(TCCR1A_Register,WGM12);
	SET_BIT(TCCR1A_Register,WGM13);

	CLR_BIT(TCCR1B_Register,CS10);
	SET_BIT(TCCR1B_Register,CS11);
	CLR_BIT(TCCR1B_Register,CS12);

}
void TIM1_voidISRSetRegValue(u16 copy_u16TopVAlue){
	ICR1HL_Register = copy_u16TopVAlue;
}
void TIM1_void_CTC_SetRegValue(u16 copy_u16CompareVal){
	OCR1AHL_Register = copy_u16CompareVal;
}




















//***********************  TIMER 1


//***********************	OVF
//void(*OVF1_Globalptr)(void)=0;
//
//void TIM1_voidOVFIntEnable(void){
//	SET_BIT(TIMSK_Register,TOIE0);
//}
//void TIM1_voidOVFSetRegValue(u8 Copu_u8PreLoadValue){
//	TCNT0_Register = Copu_u8PreLoadValue;
//}
//void TIM1_voidOVFCallBack(void(*ptr)(void)){
//	OVF1_Globalptr = ptr;
//}
//void __vector_9 (void) __attribute__ ((signal,used,externally_visible)) ; \
//void __vector_9(void){
//	OVF1_Globalptr();
//}

//***********************	CTC 1A
//
//void(*CTC1A_Globalptr)(void)=0;
//
//void TIM1_voidOVFIntEnable(void){
//	SET_BIT(TIMSK_Register,TOIE0);
//}
//
//void TIM1A_voidCTCSetRegValue(u8 Copu_u8CompareValue){
//	TCNT0_Register = Copu_u8CompareValue;
//}
//
//void TIM1_CTC1A_voidCallBack(void(*ptr)(void)){
//	CTC1A_Globalptr = ptr;
//}
//void __vector_7 (void) __attribute__ ((signal,used,externally_visible)) ; \
//void __vector_7(void){
//	CTC1A_Globalptr();
//}

//***********************	CTC 1B

//void(*CTC1B_Globalptr)(void)=0;
//
//void TIM1_voidOVFIntEnable(void){
//	SET_BIT(TIMSK_Register,TOIE0);
//}
//void TIM1A_voidCTCSetRegValue(u8 Copu_u8CompareValue){
//	TCNT0_Register = Copu_u8CompareValue;
//}
//void TIM1_CTC1B_voidCallBack(void(*ptr)(void)){
//	CTC1B_Globalptr = ptr;
//}
//void __vector_8 (void) __attribute__ ((signal,used,externally_visible)) ; \
//void __vector_8(void){
//	CTC1B_Globalptr();
//}
//

