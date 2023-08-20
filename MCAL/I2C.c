/*
 * I2C.c
 *
 *  Created on: Aug 7, 2023
 *      Author: larar
 */

#include "REGISTERS.h"
#include "I2C.h"
#include "I2C_priv.h"
#include "I2C_config.h"
#include "../UTILS/STD_TYPES.h"
#include "../UTILS/MACROS.h"
#include <string.h>

void I2C_vInitMaster(uint8 address){
	if(address < 128){
		TWAR = address << 1;
	}
	TWBR = 12;
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);

	SET_BIT(TWCR,6);

	SET_BIT(TWCR,2);
}



void I2C_vSendStartCondition(void){
	SET_BIT(TWCR, 5);

	SET_BIT(TWCR, 7);

	while(GET_BIT(TWCR,7) == 0);

	while((TWSR & 0xF8) != I2C_START_COND_ACK);
}

void I2C_vSendRepeatedStartCondition(void){
	SET_BIT(TWCR, 5);

	SET_BIT(TWCR, 7);

	while(GET_BIT(TWCR,7) == 0);

	while((TWSR & 0xF8) != I2C_REP_START_COND_ACK);
}

void I2C_vSendStopCondition(void){

	SET_BIT(TWCR, 4);

	SET_BIT(TWCR, 7);
}

void I2C_vSendSlaveAddresswithWrite(uint8 address){
	if(address < 128){

		TWDR = address << 1;
		CLR_BIT(TWDR, 0);

		CLR_BIT(TWCR, 5);

		SET_BIT(TWCR, 7);

		while(GET_BIT(TWCR,7) == 0);

		while((TWSR & 0xF8) != I2C_SLAVE_ADD_W);
	}
}
void I2C_vSendSlaveAddresswithRead(uint8 address){
	if(address < 128){

		TWDR = address << 1;
		SET_BIT(TWDR, 0);

		CLR_BIT(TWCR, 5);

		SET_BIT(TWCR, 7);

		while(GET_BIT(TWCR,7) == 0);

		while((TWSR & 0xF8) != I2C_SLAVE_ADD_R);
		}
}

void I2C_vSendDataMaster(uint8 data){
	TWDR = data;

	SET_BIT(TWCR, 7);

	while(GET_BIT(TWCR,7) == 0);

	while((TWSR & 0xF8) != I2C_MASTER_DARA_SEND_ACK);
}

void I2C_vReadDataMaster(uint8* data){
	if (data != NULL) {
		SET_BIT(TWCR, 7);

		while(GET_BIT(TWCR,7) == 0);

		while((TWSR & 0xF8) != I2C_MASTER_DARA_READ_ACK);

		*data = TWDR;
	}
}

