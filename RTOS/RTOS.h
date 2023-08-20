/*
 * RTOS.h
 *
 *  Created on: Aug 18, 2023
 *      Author: larar
 */

#ifndef RTOS_RTOS_H_
#define RTOS_RTOS_H_

typedef struct{
	uint16 periodicity;
	void (*ptf)(void);
}task;

void start_OS();
void create_task(uint8 periodicity, uint8 priority, void (*ptr)(void));
void schedular(void);
void Increment_tickTime(void);

#endif /* RTOS_RTOS_H_ */
