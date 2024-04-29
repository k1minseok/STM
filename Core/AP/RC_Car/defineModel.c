/*
 * defineModel.c
 *
 *  Created on: Apr 27, 2024
 *      Author: k1min
 */

#include "defineModel.h"

/*
 * Model
 * 1. Manage all #define used in the AP
 * 2. Manage all hardware (Motor, Ultrasonic, ...)
 * 3. Store various states
 */

//extern UART_HandleTypeDef huart2;


Button_t Button_1, Button_2, Button_3;
LED_t LED_1, LED_2, LED_3;
//Ultrasonic_t LeftUltra, CenterUltra, RightUltra;

handler_t DevHandler;
com_hMotor_t com_hMotor;
com_hUltra_t com_hUltra;

uint8_t CarModeState_Mo;


void Model_hardwareinit(UART_HandleTypeDef *inHuart,
		TIM_HandleTypeDef *motor_inHtim,
		TIM_HandleTypeDef *UltraLeft_inHtim, TIM_HandleTypeDef *UltraCenter_inHtim, TIM_HandleTypeDef *UltraRight_inHtim)
{
	DevHandler.myHuart = inHuart;
	DevHandler.motor_htim = motor_inHtim;
	DevHandler.UltraLeft_htim = UltraLeft_inHtim;
	DevHandler.UltraCenter_htim = UltraCenter_inHtim;
	DevHandler.UltraRight_htim = UltraRight_inHtim;


	Motor_init(&(com_hMotor.hLeftMotor), motor_inHtim, TIM_CHANNEL_1, LEFT_DIR1_Port,
			LEFT_DIR1_Port_Pin, LEFT_DIR2_Port, LEFT_DIR2_Port_Pin);
	Motor_init(&(com_hMotor.hRightMotor), motor_inHtim, TIM_CHANNEL_2, RIGHT_DIR1_Port,
			RIGHT_DIR1_Port_Pin, RIGHT_DIR2_Port, RIGHT_DIR2_Port_Pin);
}

handler_t *Model_getHandler()
{
	return &DevHandler;
}

com_hMotor_t *Model_getHandleMotor()
{
	return &com_hMotor;
}


int _write(int file, char *ptr, int len)		// for printf() function
{
	HAL_UART_Transmit(DevHandler.myHuart, (uint8_t*) ptr, len, 1000);

	return len;
}


uint8_t Model_getCarModeState()
{
	return CarModeState_Mo;
}
void Model_setCarModeState(uint8_t data)
{
	CarModeState_Mo = data;
}
