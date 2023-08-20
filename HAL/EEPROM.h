/*
 * EEPROM.h
 *
 *  Created on: Aug 7, 2023
 *      Author: larar
 */

#ifndef HAL_EEPROM_H_
#define HAL_EEPROM_H_

#include "../UTILS/STD_TYPES.h"

#define EEPROM_ADDRESS		0b01010000

#define MAX_PAGE_WRITE		7

void EEPROM_vInit(void);

void EEPROM_vWriteByte(uint16 address, uint8 data);

uint8 EEPROM_u8ReadByte(uint16 address);

void EEPROM_vWritePage(uint16 address, uint8* data);

void EEPROM_u8SequentialRead(uint16 address, uint8* data);
#endif /* HAL_EEPROM_H_ */
