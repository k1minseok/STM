/*
 * Presenter.h
 *
 *  Created on: Apr 26, 2024
 *      Author: k1min
 */

#ifndef AP_RC_CAR_PRESENTER_H_
#define AP_RC_CAR_PRESENTER_H_

#include "defineModel.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>


void Presenter_Motor_Run(uint8_t state);
void Presenter_UART_Run(uint8_t state);


#endif /* AP_RC_CAR_PRESENTER_H_ */
