/*
 * ADC_cfg.h
 *
 *  Created on: Aug 25, 2024
 *      Author: salma
 */

#ifndef MCAL_AVR_ADC_ADC_CFG_H_
#define MCAL_AVR_ADC_ADC_CFG_H_


//initialisation

#define Refmode 				AREF_AVCC
#define ALDARmode 				ALL_ADCL
#define prescaler_factor    	prescaler_factor128

#define MUXselection_mode 		SingleEnded

#define Interrupt_mode 			Interrupt_OFF
#define AutotriggerMode 		Autotrigger_OFF
#define Autotrigger_source 		Autotrigger_none

#endif /* MCAL_AVR_ADC_ADC_CFG_H_ */
