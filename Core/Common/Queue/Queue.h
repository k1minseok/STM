/*
 * Queue.h
 *
 *  Created on: Apr 26, 2024
 *      Author: k1min
 */

#ifndef COMMON_QUEUE_QUEUE_H_
#define COMMON_QUEUE_QUEUE_H_

#include "stm32f4xx_hal.h"
#include "stdint.h"


#define BUF_SIZE			100

typedef struct{
	uint8_t QueBuff[BUF_SIZE];
	int tail;
	int head;
	int QueCounter;
}Que_t;


void Que_init(Que_t *Que);

uint8_t QueFull(Que_t *Que);
uint8_t QueEmpty(Que_t *Que);

void enQue(Que_t *Que, uint8_t data);
uint8_t deQue(Que_t *Que);


#endif /* COMMON_QUEUE_QUEUE_H_ */
