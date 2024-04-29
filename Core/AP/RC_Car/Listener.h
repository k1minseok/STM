/*
 * Listener.h
 *
 *  Created on: Apr 26, 2024
 *      Author: k1min
 */

#ifndef AP_RC_CAR_LISTENER_H_
#define AP_RC_CAR_LISTENER_H_

#include "defineModel.h"
#include "stm32f4xx_hal.h"
#include "Queue_Car.h"
#include <string.h>


void Listener_ISR_Process(uint8_t rcvData);
void Listener_init();
void Listener_CarMode_EventCheck();
void Listener_clearModeBuf();

#endif /* AP_RC_CAR_LISTENER_H_ */
