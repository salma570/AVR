/*
 * Tmr_prv.h
 *
 *  Created on: Aug 28, 2024
 *      Author: salma
 */

#ifndef MCAL_AVR_TIMERS_TMR_PRV_H_
#define MCAL_AVR_TIMERS_TMR_PRV_H_


//registers
#define TCCR0_Register *((volatile u8 *)(0x53))
#define TCNT0_Register *((volatile u8 *)(0x52))
#define OCR0_Register *((volatile u8 *)(0x5C))
#define TIMSK_Register *((volatile u8 *)(0x59))
#define TIFR_Register *((volatile u8 *)(0x58))


#define FOC0	7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02 2
#define CS01 1
#define CS00 0

#define OCIE0 1
#define TOIE0 0

#define OCF0 1
#define TOV0 0


#define TCCR1A_Register *((volatile u8 *)(0x4F))

#define TCCR1B_Register *((volatile u8 *)(0x4E))

#define TCNT1HL_Register *((volatile u16 *)(0x4C))

#define OCR1AHL_Register *((volatile u16 *)(0x4A))
#define OCR1BHL_Register *((volatile u16 *)(0x48))

#define ICR1HL_Register *((volatile u16 *)(0x46))

#define COM1A1 7
#define COM1A0 6

#define COM1B1 5
#define COM1B0 4
#define FOC1A 3
#define FOC1B 2

#define WGM11 1
#define WGM10 0

#define ICNC1 7
#define ICES1 6

#define WGM13 4
#define WGM12 3

#define CS12 2
#define CS11 1
#define CS10 0


#define TICIE1 5
#define OCIE1A 4
#define OCIE1B 3
#define TOIE1 2

#define ICF1 5
#define OCF1A 4
#define OCF1B 3
#define TOV1 2

#endif /* MCAL_AVR_TIMERS_TMR_PRV_H_ */
