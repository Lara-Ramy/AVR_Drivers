/*
 * keypad.c
 *
 *  Created on: Jul 23, 2023
 *      Author: larar
 */
#include "keypad.h"
#include "../MCAL/dio.h"
#include "keypad_config.h"


uint8 characters[ROWS_NUM][COLUMNS_NUM] = {};


void Keypad_vInit(void){
	DIO_SetInternalPullup(COLUMN1, HIGH);
	DIO_SetInternalPullup(COLUMN2, HIGH);
	DIO_SetInternalPullup(COLUMN3, HIGH);
	DIO_SetInternalPullup(COLUMN4, HIGH);
}

uint8 Keypad_u8GetPressed(void){
	uint8 rows[ROWS_NUM] = ROWS_ARR;
	uint8 columns[COLUMNS_NUM] = COLUMNS_ARR;
	uint8 characters[ROWS_NUM][COLUMNS_NUM] = KEYPAD_KEYS;


	for (uint8 i = 0; i < ROWS_NUM; i++){
		DIO_WriteChannel(rows[i], LOW);
		for (uint8 j = 0; j < COLUMNS_NUM; j++){
			if (DIO_ReadChannel(columns[j]) == 0){
				while(0 == DIO_ReadChannel(columns[j]));
				DIO_WriteChannel(rows[i], HIGH);
				return characters[i][j];
			}
		}
		DIO_WriteChannel(rows[i], HIGH);
	}
	return KEY_NOT_PRESSED;
}
