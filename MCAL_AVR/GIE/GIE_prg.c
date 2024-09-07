/*
 * GIE_prg.c
 *
 *  Created on: Aug 25, 2024
 *      Author: salma
 */

#include "../../STD_Types.h"
#include "../../BIT_MATH.h"
#include "GIE_prv.h"
#include "GIE_int.h"

void GIE_Enable(void){
	SET_BIT(SREG_Register,I_BIT);
}
void GIE_Disable(void){
	CLR_BIT(SREG_Register,I_BIT);
}


