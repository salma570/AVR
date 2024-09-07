/*
 * ADC_prg.c
 *
 *  Created on: Aug 25, 2024
 *      Author: salma
 */
#include "../../STD_Types.h"
#include "../../BIT_MATH.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"
#include "ADC_int.h"

void ADC_Init(void){


	//SetRefmode

#if (Refmode ==AREF_Stop)
	CLR_BIT(ADMUX_Register,REFS1);
	CLR_BIT(ADMUX_Register,REFS0);

#elif (Refmode ==AREF_AVCC)
	CLR_BIT(ADMUX_Register,REFS1);
	SET_BIT(ADMUX_Register,REFS0);

#elif (Refmode ==AREF_Internal)
	SET_BIT(ADMUX_Register,REFS1);
	SET_BIT(ADMUX_Register,REFS0);

#endif

	//ADC_SetALDAR
#if (ALDARmode == ALL_ADCH)
	SET_BIT(ADMUX_Register,ADLAR);
#elif (ALDARmode == ALL_ADCL)
	CLR_BIT(ADMUX_Register,ADLAR);
#endif

	//ADPIS > prescaler
#if(prescaler_factor == prescaler_factor2)
	CLR_BIT(ADCSRA_Register,ADPS2);
	CLR_BIT(ADCSRA_Register,ADPS1);
	CLR_BIT(ADCSRA_Register,ADPS0);
#elif(prescaler_factor == prescaler_factor4)
	CLR_BIT(ADCSRA_Register,ADPS2);
	SET_BIT(ADCSRA_Register,ADPS1);
	CLR_BIT(ADCSRA_Register,ADPS0);
#elif(prescaler_factor == prescaler_factor8)
	CLR_BIT(ADCSRA_Register,ADPS2);
	SET_BIT(ADCSRA_Register,ADPS1);
	SET_BIT(ADCSRA_Register,ADPS0);
#elif(prescaler_factor == prescaler_factor16)
	SET_BIT(ADCSRA_Register,ADPS2);
	CLR_BIT(ADCSRA_Register,ADPS1);
	CLR_BIT(ADCSRA_Register,ADPS0);
#elif(prescaler_factor == prescaler_factor32)
	SET_BIT(ADCSRA_Register,ADPS2);
	CLR_BIT(ADCSRA_Register,ADPS1);
	SET_BIT(ADCSRA_Register,ADPS0);
#elif(prescaler_factor == prescaler_factor64)
	SET_BIT(ADCSRA_Register,ADPS2);
	SET_BIT(ADCSRA_Register,ADPS1);
	CLR_BIT(ADCSRA_Register,ADPS0);
#elif(prescaler_factor == prescaler_factor128)
	SET_BIT(ADCSRA_Register,ADPS2);
	SET_BIT(ADCSRA_Register,ADPS1);
	SET_BIT(ADCSRA_Register,ADPS0);
#endif

	//enable ADC
	SET_BIT(ADCSRA_Register,ADEN);
}
u16 ADC_Read(u8 Copy_u8Chanel){
	//Set_selectionSignal  > channels
	ADMUX_Register = ((ADMUX_Register&Bit_mask)|Copy_u8Chanel);
	//set ADsc start conversion
	SET_BIT(ADCSRA_Register,ADSC);
#if(Interrupt_mode == Interrupt_OFF)
	// wait ADIF
	while(GET_BIT(ADCSRA_Register,ADIF)==0);
	// CLR ADIF > flag
	CLR_BIT(ADCSRA_Register,ADIF);
	//return digital value
	return ADC_Data_Register;
#elif(Interrupt_mode == Interrupt_ON)






	// CLR ADIF > flag> automatically
	//return digital value
	return ADC_Data_Register;
#endif






}
u32 TO_ANALOG(u16 digital_o, u16 Multiplication_factor) {
	return ((u32)(digital_o*5*Multiplication_factor)/1024);
}

//set ADCATE autotrigger
//ADIE
