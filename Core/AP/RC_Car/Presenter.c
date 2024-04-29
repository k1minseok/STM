/*
 * Presenter.c
 *
 *  Created on: Apr 26, 2024
 *      Author: k1min
 */

#include "Presenter.h"

//extern Motor_t hLeftMotor, hRightMotor;

/*
 * Presenter
 * : Execute output hardware actions for each mode
 * 1. UART : printf output
 * 2. Motor : Forward, Back, ...
 *
 */

void Presenter_Motor_Run(uint8_t state)
{
	switch (state)
	{
		case OFF:
			Motor_Stop(&(Model_getHandleMotor()->hLeftMotor));
			Motor_Stop(&(Model_getHandleMotor()->hRightMotor));
			break;

		case FORWARD:
			Motor_Forward(&(Model_getHandleMotor()->hLeftMotor));
			Motor_Forward(&(Model_getHandleMotor()->hRightMotor));
			break;

		case BACKWARD:
			Motor_Backward(&(Model_getHandleMotor()->hLeftMotor));
			Motor_Backward(&(Model_getHandleMotor()->hRightMotor));
			break;

		case RIGHT_FORWARD:
			Motor_Forward(&(Model_getHandleMotor()->hLeftMotor));
			Motor_Forward(&(Model_getHandleMotor()->hRightMotor));
			break;

		case LEFT_FORWARD:
			Motor_Forward(&(Model_getHandleMotor()->hLeftMotor));
			Motor_Forward(&(Model_getHandleMotor()->hRightMotor));
			break;
	}
}

void Presenter_UART_Run(uint8_t state)
{
	switch (state)
	{
		case OFF:
			printf("Mode : OFF\n");
			printf("--------------------------\n");
			break;

		case FORWARD:
			printf("Mode : Forward\n");
			printf("--------------------------\n");
			break;

		case BACKWARD:
			printf("Mode : Backward\n");
			printf("--------------------------\n");
			break;

		case RIGHT_FORWARD:
			printf("Mode : RightForward\n");
			printf("--------------------------\n");
			break;

		case LEFT_FORWARD:
			printf("Mode : LeftForward\n");
			printf("--------------------------\n");
			break;
	}
}
