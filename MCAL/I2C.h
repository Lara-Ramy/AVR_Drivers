/*
 * I2C.h
 *
 *  Created on: Aug 7, 2023
 *      Author: larar
 */

#ifndef MCAL_I2C_H_
#define MCAL_I2C_H_
#include "../UTILS/STD_TYPES.h"
#include <string.h>

void I2C_vInitMaster					(uint8 address);

void I2C_vSendStartCondition			(void);

void I2C_vSendRepeatedStartCondition	(void);

void I2C_vSendStopCondition				(void);

void I2C_vSendSlaveAddresswithWrite		(uint8 address);

void I2C_vSendSlaveAddresswithRead		(uint8 address);

void I2C_vSendDataMaster				(uint8 data);

void I2C_vReadDataMaster				(uint8* data);

#endif /* MCAL_I2C_H_ */
