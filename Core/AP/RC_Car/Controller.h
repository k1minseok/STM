/*
 * Controller.h
 *
 *  Created on: Apr 26, 2024
 *      Author: k1min
 */

#ifndef AP_RC_CAR_CONTROLLER_H_
#define AP_RC_CAR_CONTROLLER_H_

#include "stm32f4xx_hal.h"
#include "defineModel.h"
#include "Presenter.h"


void Controller_Car_init();
void Controller_Car_execute();

void Controller_CarOFF_Run();
void Controller_CarForward_Run(int speedVal);
void Controller_CarBackward_Run(int speedVal);
void Controller_CarRightForward_Run(int speedVal, int speedDif);
void Controller_CarLeftForward_Run(int speedVal, int speedDif);


#endif /* AP_RC_CAR_CONTROLLER_H_ */
