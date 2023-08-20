/*
 * lcd.c
 *
 *  Created on: Jul 23, 2023
 *      Author: larar
 */


#include "lcd.h"
#include "lcd_config.h"


void LCD_vInit(void){
//#if     LCD_MODE == 4
	_delay_ms(45);
	DIO_WriteChannel(RS, LOW);
	vPriEnable();
	vPriWriteHalfPort(0b0010);
	vPriEnable();

	LCD_vSendCmnd(0b00101000);
	_delay_us(45);
	//set display on/off control
	LCD_vSendCmnd(0b00001111);
	_delay_us(45);
	//set display clear
	LCD_vSendCmnd(0b00000001);
	_delay_ms(2);
	//set entry mode
	LCD_vSendCmnd(0b00000110);

//#endif
}

void LCD_vSendCmnd(uint8 cmnd){
	DIO_WriteChannel(RS, LOW);
//#if     LCD_MODE == 4
	vPriWriteHalfPort(cmnd >> 4);
	vPriEnable();
	vPriWriteHalfPort(cmnd);
	vPriEnable();
//#endif

}

void LCD_vSendData(uint8 data){
	DIO_WriteChannel(RS, HIGH);
//#if     LCD_MODE == 4
	vPriWriteHalfPort(data >> 4);
	vPriEnable();
	vPriWriteHalfPort(data);
	vPriEnable();
//#endif
}

void LCD_vSendString(uint8* str){
	uint8 i = 0;
	while (str[i] != '\0'){
		LCD_vSendData(str[i]);
		i++;
	}
}

void LCD_vSendInt(sint32 num){
	sint32 out = 1;
	if(num < 0){
		LCD_vSendData('-');
		num *= -1;
	}

	while (num > 0){
		out = ((out*10) + (num%10));
		num /= 10;
	}

	while (out > 1){
		LCD_vSendData(((out%10)+48));
		out /= 10;
	}
}

void LCD_vGoTo(uint8 row , uint8 col)
{
	uint8 pos[2] = {0x80 , 0xc0};

	LCD_vSendCmnd(pos[row]+col);
}


static void vPriWriteHalfPort(uint8 value){
	if(GET_BIT(value, 0) == 1){
		DIO_WriteChannel(D4, HIGH);
	}
	else{
		DIO_WriteChannel(D4, LOW);
	}
	if(GET_BIT(value, 1) == 1){
		DIO_WriteChannel(D5, HIGH);
	}
	else{
		DIO_WriteChannel(D5, LOW);
	}
	if(GET_BIT(value, 2) == 1){
		DIO_WriteChannel(D6, HIGH);
	}
	else{
		DIO_WriteChannel(D6, LOW);
		}
	if(GET_BIT(value, 3) == 1){
		DIO_WriteChannel(D7, HIGH);
	}
	else{
		DIO_WriteChannel(D7, LOW);
	}
}

static void vPriEnable(void){
	DIO_WriteChannel(EN, HIGH);
	_delay_ms(1);
	DIO_WriteChannel(EN, LOW);
}
