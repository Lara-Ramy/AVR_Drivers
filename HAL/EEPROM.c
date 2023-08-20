/*
 * EEPROM.c
 *
 *  Created on: Aug 7, 2023
 *      Author: larar
 */

#include "EEPROM.h"
#include "../MCAL/I2C.h"
#include "../UTILS/STD_TYPES.h"
#include <util/delay.h>

void EEPROM_vInit(void){
	I2C_vInitMaster(0x01);
}

void EEPROM_vWriteByte(uint16 address, uint8 data){
	I2C_vSendStartCondition();
	I2C_vSendSlaveAddresswithWrite(EEPROM_ADDRESS | (address>>8));
	I2C_vSendDataMaster((uint8)address);
	I2C_vSendDataMaster(data);
	I2C_vSendStopCondition();

	_delay_ms(5);
}

uint8 EEPROM_u8ReadByte(uint16 address){
	uint8 data;
	I2C_vSendStartCondition();
	I2C_vSendSlaveAddresswithWrite(EEPROM_ADDRESS | (address>>8));
	I2C_vSendDataMaster((uint8)address);

	I2C_vSendRepeatedStartCondition();
	I2C_vSendSlaveAddresswithRead(EEPROM_ADDRESS | (address>>8));
	I2C_vReadDataMaster(&data);

	I2C_vSendStopCondition();
	_delay_ms(5);
	return data;
}

void EEPROM_vWritePage(uint16 address, uint8* data){
	I2C_vSendStartCondition();
	I2C_vSendSlaveAddresswithWrite(EEPROM_ADDRESS | (address>>8));
	I2C_vSendDataMaster((uint8)address);
	uint8 i = 0;
	while(data[i] != '\0' && i < MAX_PAGE_WRITE - 1){
		I2C_vSendDataMaster(data[i]);
		i++;
	}
	I2C_vSendDataMaster(data[i]);
	I2C_vSendStopCondition();
}

void EEPROM_u8SequentialRead(uint16 address, uint8* data){

	I2C_vSendStartCondition();
	I2C_vSendSlaveAddresswithWrite(EEPROM_ADDRESS | (address>>8));
	I2C_vSendDataMaster((uint8)address);

	I2C_vSendRepeatedStartCondition();
	I2C_vSendSlaveAddresswithRead(EEPROM_ADDRESS | (address>>8));
	uint8 i = 0;
	while(data[i] != '\0' && i < MAX_PAGE_WRITE - 1){
		I2C_vReadDataMaster(data + i);
		i++;
	}
	I2C_vReadDataMaster(data + i);

	I2C_vSendStopCondition();
	_delay_ms(5);

}

