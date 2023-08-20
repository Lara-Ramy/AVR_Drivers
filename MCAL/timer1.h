/*
 * timer1.h
 *
 *  Created on: Jul 31, 2023
 *      Author: larar
 */

#ifndef MCAL_TIMER1_H_
#define MCAL_TIMER1_H_

void Timer1_vInit(void);

void Timer1_vStart(uint16 start_time);

void Timer1_vStop(void);

void Timer1_SetPWMFast(uint8 duty, uint8 frequency);

void Timer1_vSetCompA(uint16 comp_time);

void Timer1_vSetCompB(uint16 comp_time);

#endif /* MCAL_TIMER1_H_ */
