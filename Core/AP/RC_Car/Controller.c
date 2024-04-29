/*
 * Controller.c
 *
 *  Created on: Apr 26, 2024
 *      Author: k1min
 */


#include "Controller.h"

//Motor_t litener_hLeftMotor, litener_hRightMotor;
//uint8_t curCarModeState;

uint8_t prevCarModeState;
uint16_t MotorSpeed, turnDiffSpeed;

/*
 * Controller
 * : Define actions for each mode by referencing the model's modeState
 * 1. Motor : speed & action(forward, back, ...)
 * 2. UART : output data
 */

void Controller_Car_init()
{
	prevCarModeState = OFF;

	MotorSpeed = 1000;
	turnDiffSpeed = 1000;
}

void Controller_Car_execute()
{
	uint8_t curCarModeState = Model_getCarModeState();
	//uint8_t curCarModeState = LEFT_FORWARD;
	//curCarModeState = RIGHT_FORWARD;
	if(prevCarModeState == curCarModeState) return;

	switch (curCarModeState)
	{
		case OFF:
			//stopMode();
			Controller_CarOFF_Run();
			break;

		case FORWARD:
			Controller_CarForward_Run(MotorSpeed);
			break;

		case BACKWARD:
			Controller_CarBackward_Run(MotorSpeed);
			break;

		case RIGHT_FORWARD:
			Controller_CarRightForward_Run(MotorSpeed, turnDiffSpeed);
			break;

		case LEFT_FORWARD:
			Controller_CarLeftForward_Run(MotorSpeed, turnDiffSpeed);
			break;
	}
	prevCarModeState = curCarModeState;
}

void Controller_CarOFF_Run()
{
	Motor_SetSpeed(&(Model_getHandleMotor()->hLeftMotor), 0);
	Motor_SetSpeed(&(Model_getHandleMotor()->hRightMotor), 0);
	Presenter_Motor_Run(OFF);
	Presenter_UART_Run(OFF);
}
void Controller_CarForward_Run(int speedVal)
{
	if(speedVal > 1000) speedVal = 1000;
	Motor_SetSpeed(&(Model_getHandleMotor()->hLeftMotor), speedVal);
	Motor_SetSpeed(&(Model_getHandleMotor()->hRightMotor), speedVal);
	Presenter_Motor_Run(FORWARD);
	Presenter_UART_Run(FORWARD);
}
void Controller_CarBackward_Run(int speedVal)
{
	if(speedVal > 1000) speedVal = 1000;
	Motor_SetSpeed(&(Model_getHandleMotor()->hLeftMotor), speedVal);
	Motor_SetSpeed(&(Model_getHandleMotor()->hRightMotor), speedVal);
	Presenter_Motor_Run(BACKWARD);
	Presenter_UART_Run(BACKWARD);
}
void Controller_CarRightForward_Run(int speedVal, int speedDif)
{
	if(speedVal > 1000) speedVal = 1000;
	//if((speedVal+speedDif) > 1000) speedVal = 1000-speedDif;
	Motor_SetSpeed(&(Model_getHandleMotor()->hLeftMotor), speedVal);
	Motor_SetSpeed(&(Model_getHandleMotor()->hRightMotor), speedVal-speedDif);
	Presenter_Motor_Run(RIGHT_FORWARD);
	Presenter_UART_Run(RIGHT_FORWARD);
}
void Controller_CarLeftForward_Run(int speedVal, int speedDif)
{
	if(speedVal > 1000) speedVal = 1000;
	//if(speedVal<speedDif) speedVal = 1000-speedDif;
	Motor_SetSpeed(&(Model_getHandleMotor()->hLeftMotor), speedVal-speedDif);
	Motor_SetSpeed(&(Model_getHandleMotor()->hRightMotor), speedVal);
	Presenter_Motor_Run(LEFT_FORWARD);
	Presenter_UART_Run(LEFT_FORWARD);
}


//void sleepMode()
//{
//	HAL_SuspendTick();
//	__HAL_RCC_PWR_CLK_ENABLE();
//	HAL_PWR_EnterSLEEPMode(0, PWR_SLEEPENTRY_WFI);
//	HAL_ResumeTick();
//}
//void stopMode()
//{
//	HAL_SuspendTick();
//	__HAL_RCC_PWR_CLK_ENABLE();
//	HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_SLEEPENTRY_WFI);
//	HAL_ResumeTick();
//	SystemClock_Config();
//}
//void softReset()
//{
//	NVIC_SystemReset();
//}

