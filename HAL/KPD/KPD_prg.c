/*
 * KPD_prg.c
 *
 *  Created on: Aug 15, 2024
 *      Author: salma
 */

#include "../../STD_Types.h"
#include "../../BIT_MATH.h"
#include "../../MCAL_AVR/DIO/DIO_int.h"
#include "KPD_int.h"
#include "KPD_cfg.h"
#include "util/delay.h"

static u8 array[4][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
};

void KPD_init(void){
	//pins input pull-up rows
	for(int i=ROW_start; i<=ROW_end;i++){
		DIO_SetPinDirection(KPD_PORT,i,Input);
		DIO_SetPinValue(KPD_PORT,i,HIGH);
	}
	// pins output high
	for(int i=COL_start; i<=COL_end;i++){
		DIO_SetPinDirection(KPD_PORT,i,Output);
		DIO_SetPinValue(KPD_PORT,i,HIGH);
	}
}
u8 KPD_GetKey(void){
	for(int i =COL_start,c=0; i<=COL_end ;i++,c++){
		DIO_SetPinValue(KPD_PORT,(i),LOW);
		_delay_ms(20);

		for(int j =ROW_start; j<ROW_end;j++){
			if(DIO_GetPinValue(KPD_PORT,j)==0){
				return (c+j*3);
			}
		}
		DIO_SetPinValue(KPD_PORT,(i),HIGH);
	}
	return 16;
}
//u8 KPD_GetKey2(void){
//	for(int i = COL_start,c=0; i<=COL_end ;i++,c++){
//		DIO_SetPinValue(KPD_PORT,(i),LOW);
//		_delay_ms(20);
//		for(int j =ROW_start; j<ROW_end;j++){
//			if(DIO_GetPinValue(KPD_PORT,(j))==0){
//				return array[j][i];
//			}
//		}
//		DIO_SetPinValue(KPD_PORT,(i),HIGH);
//	}
//	return 16;
//}
