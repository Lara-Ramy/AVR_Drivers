/*
 * keypad_config.h
 *
 *  Created on: Jul 24, 2023
 *      Author: larar
 */

#ifndef HAL_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_CONFIG_H_

#define ROWS_NUM 4
#define COLUMNS_NUM 4

#define ROW1 PC5
#define ROW2 PC4
#define ROW3 PC3
#define ROW4 PC2

#define COLUMN1 PD7
#define COLUMN2 PD6
#define COLUMN3 PD5
#define COLUMN4 PD3

#define ROWS_ARR {ROW1, ROW2, ROW3, ROW4}
#define COLUMNS_ARR {COLUMN1, COLUMN2, COLUMN3, COLUMN4}
#define KEYPAD_KEYS {'7', '8', '9', '/', '4', '5', '6', '*', '1', '2', '3', '-', 'c', '0', '=', '+'}



#endif /* HAL_KEYPAD_CONFIG_H_ */
