/*
 * ADC_prv.h
 *
 *  Created on: Aug 25, 2024
 *      Author: salma
 */

#ifndef MCAL_AVR_ADC_ADC_PRV_H_
#define MCAL_AVR_ADC_ADC_PRV_H_

#define SFIOR_Register  	 *((volatile u8 *)(0x50))

#define ADMUX_Register  	 *((volatile u8 *)(0x27))
#define ADCSRA_Register   	 *((volatile u8 *)(0x26))
#define ADC_Data_Register    *((volatile u16 *)(0x24))

#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define MUX4 4
#define MUX3 3
#define MUX2 2
#define MUX1 1
#define MUX0 0

#define ADEN 7
#define ADSC 6
#define ADCATE 5
#define ADIF 4
#define ADIE 3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

#define ADTS2 7
#define ADTS1 6
#define ADTS0 5

#endif /* MCAL_AVR_ADC_ADC_PRV_H_ */
