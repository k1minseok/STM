/*
 * Car_Queue.h
 *
 *  Created on: Apr 26, 2024
 *      Author: k1min
 */

#ifndef AP_RC_CAR_QUEUE_CAR_H_
#define AP_RC_CAR_QUEUE_CAR_H_

#include <stdint.h>
#include "../Common/Queue/Queue.h"

void Que_Car_init();
void enQue_CarModeState(uint8_t data);
uint8_t deQue_CarModeState();
int Que_Car_isEmpty();


#endif /* AP_RC_CAR_QUEUE_CAR_H_ */
