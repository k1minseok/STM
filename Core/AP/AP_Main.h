/*
 * AP_Main.h
 *
 *  Created on: Apr 23, 2024
 *      Author: k1min
 */

#ifndef AP_AP_MAIN_H_
#define AP_AP_MAIN_H_

#include "stm32f4xx_hal.h"
#include "RC_Car/Controller.h"
#include "RC_Car/Listener.h"
#include "RC_Car/Presenter.h"
#include "RC_Car/defineModel.h"
#include "../Common/delayUS/delayUS.h"


void AP_Main_init();
void AP_Main_execute();


#endif /* AP_AP_MAIN_H_ */
