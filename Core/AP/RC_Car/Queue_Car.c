/*
 * Car_Queue.c
 *
 *  Created on: Apr 26, 2024
 *      Author: k1min
 */

#include "Queue_Car.h"

/*
 * Queue
 * 1. Read/Write in form of Ring Buffer
 */

Que_t carmodeQue;

void Que_Car_init()
{
	Que_init(&carmodeQue);
}

void enQue_CarModeState(uint8_t data)
{
	enQue(&carmodeQue, data);
}

uint8_t deQue_CarModeState()
{
	uint8_t temp = deQue(&carmodeQue);

	return temp;
}

int Que_Car_isEmpty()
{
	return QueEmpty(&carmodeQue);
}
