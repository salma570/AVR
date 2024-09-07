/*
 * LCD_prg.c
 *
 *  Created on: Aug 13, 2024
 *      Author: hp
 */
#include "../../STD_Types.h"
#include "../../BIT_MATH.h"
#include "../../MCAL_AVR/DIO/DIO_int.h"
#include "LCD_int.h"
#include "LCD_cfg.h"
#include "util/delay.h"

static u8 specialPattern[64]={
		//pattern 1
		0b00000000,
		0b00000000,
		0b00000000,
		0b00010101,
		0b00011111,
		0b00000000,
		0b00000000,
		0b00000000,

		//pattern 2
		0b00000000,
		0b00001000,
		0b00001000,
		0b00001000,
		0b00011111,
		0b00000000,
		0b00000000,
		0b00000000,

		//pattern 3
		0b00000000,
		0b00000000,
		0b00001111,
		0b00001001,
		0b00011111,
		0b00000000,
		0b00000000,
		0b00000000,

		//pattern 4
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000110,
		0b00010101,
		0b00010100,
		0b00001000,
		0b00000000,
};

void LCD_init(void)
{
	//Port -> Out, Data, Command
	DIO_SetPortDirection(LCD_DataPort,PortOut);
	//3 Pins -> out
	DIO_SetPinDirection(LCD_CtrlPort,RS_Pin,Output);
	DIO_SetPinDirection(LCD_CtrlPort,RW_Pin,Output);
	DIO_SetPinDirection(LCD_CtrlPort,E_Pin,Output);
	//ensure E is low
	DIO_SetPinValue(LCD_CtrlPort,E_Pin,LOW);
	//init -> datasheet
	_delay_ms(30);
	LCD_WriteCommand(lcd_FunctionSet8bit);
	_delay_ms(5);
	LCD_WriteCommand(lcd_DisplayOn);
	_delay_ms(5);
	LCD_WriteCommand(lcd_Clear);
	_delay_ms(5);
	LCD_WriteCommand(lcd_EntryMode);
}
void LCD_WriteCommand(u8 Copy_u8Command)
{
	//RS -> 0 COMMAND
	DIO_SetPinValue(LCD_CtrlPort,RS_Pin,LOW);
	//RW -> 0 WRITE
	DIO_SetPinValue(LCD_CtrlPort,RW_Pin,LOW);
	//E -> 0 ENSURE
	DIO_SetPinValue(LCD_CtrlPort,E_Pin,LOW);
	//Write Command
	DIO_SetPortValue(LCD_DataPort,Copy_u8Command);
	//GIVE PULSE
	//E -> 1
	DIO_SetPinValue(LCD_CtrlPort,E_Pin,HIGH);
	//Delay
	_delay_ms(5);
	//E -> 0
	DIO_SetPinValue(LCD_CtrlPort,E_Pin,LOW);
}
void LCD_WriteChar(u8 Copy_u8Char)
{
	//RS -> 1 DATA
	DIO_SetPinValue(LCD_CtrlPort,RS_Pin,HIGH);
	//RW -> 0 WRITE
	DIO_SetPinValue(LCD_CtrlPort,RW_Pin,LOW);
	//E -> 0 ENSURE
	DIO_SetPinValue(LCD_CtrlPort,E_Pin,LOW);
	//Write Command
	DIO_SetPortValue(LCD_DataPort,Copy_u8Char);
	//GIVE PULSE
	//E -> 1
	DIO_SetPinValue(LCD_CtrlPort,E_Pin,HIGH);
	//Delay
	_delay_ms(5);
	//E -> 0
	DIO_SetPinValue(LCD_CtrlPort,E_Pin,LOW);
}
void LCD_WriteString(const u8 * Copy_u8Ptr)
{
	u8 i = 0;
	while(Copy_u8Ptr[i]!='\0')
	{
		LCD_WriteChar(Copy_u8Ptr[i]);
		i++;
	}
}
void LCD_GoTo(u8 Copy_u8Line, u8 Copy_u8Colomn){
	u8  Copy_u8LocalVariable;
	if(Copy_u8Colomn>=0 && Copy_u8Colomn<=15){
		switch(Copy_u8Line){
		case Line_1:
			Copy_u8LocalVariable = 128+Copy_u8Colomn;
			break;
		case Line_2:
			Copy_u8LocalVariable = 192+Copy_u8Colomn;
			break;
		default:
			break;
		}
		LCD_WriteCommand(Copy_u8LocalVariable);
	}
}
void LCD_specialPattern(){

	for(int i =0 ; i<8;i++){


	}

}
void LCD_specialPattern_prot(){
	for(int j=0; j<5;j++){// pattern #
		LCD_WriteCommand(64+(j*8)); //1st line in pattern
		for(int i = 0;i<8;i++){ // 8 lines of the pattern
			//LCD_WriteChar(specialPattern[i+(j*8)]);// only save in Memory
			LCD_GoTo(Line_1,j);
		}
	}
}

void LCD_vidWriteExtraChar (u8 Y,u8 X) //Y = Row position , X = Column position
{
	u8 iteration1,iteration2;

	/*DDRAM-->CGRAM*/
	LCD_WriteCommand(64);
	for(iteration1=0 ; iteration1<64 ; iteration1++)
	{
		LCD_WriteChar(specialPattern[iteration1]);
	}
	/*CGRAM-->DDRAM*/
	LCD_WriteCommand(128);
	LCD_GoTo(Y,X);
	/*First eight character which saved at CGRAM*/
	for (iteration2=0; iteration2<=7 ; iteration2++)
	{
		/* Write bytes of DDRAM */
		LCD_WriteChar(iteration2);

		_delay_ms(5);
	}
}

