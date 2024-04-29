/*
 * AP_Main.c
 *
 *  Created on: Apr 23, 2024
 *      Author: k1min
 */

#include "AP_Main.h"
#include "stdio.h"

//extern TIM_HandleTypeDef htim1, htim2, htim3;
//extern UART_HandleTypeDef huart2;

//uint8_t rcvData;
//
//
//
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//	if (huart->Instance == USART2)
//	{
//		Listener_ISR_Process(rcvData);
//		HAL_UART_Transmit(Model_getHandler()->myHuart, &rcvData, 1, 100);
//		HAL_UART_Receive_IT(Model_getHandler()->myHuart, &rcvData, 1);
//		//HAL_UART_Transmit(&huart2, &rcvData, 1, 100);
//	}
//}


void AP_Main_init(UART_HandleTypeDef *inHuart,
		TIM_HandleTypeDef *motor_inHtim,
		TIM_HandleTypeDef *UltraLeft_inHtim, TIM_HandleTypeDef *UltraCenter_inHtim, TIM_HandleTypeDef *UltraRight_inHtim)
{
	DelayInit();
	Que_Car_init();
	Listener_init();
	Model_hardwareinit(inHuart, motor_inHtim, UltraLeft_inHtim, UltraCenter_inHtim, UltraRight_inHtim);
	Controller_Car_init();
//
//	HAL_UART_Receive_IT(inHuart, &rcvData, 1);
}
void AP_Main_execute()
{
	Listener_CarMode_EventCheck();
	Controller_Car_execute();
}


//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//	Ultrasonic_ISR_Process(&Ultrasonic_1, GPIO_Pin);
//	Ultrasonic_ISR_Process(&Ultrasonic_2, GPIO_Pin);
//	Ultrasonic_ISR_Process(&Ultrasonic_3, GPIO_Pin);
//}


//void sys_init()
//{
//	button_init(&Button_1, GPIOC, GPIO_PIN_10);
//	button_init(&Button_2, GPIOC, GPIO_PIN_11);
//	button_init(&Button_3, GPIOC, GPIO_PIN_12);
//
//	LED_init(&LED_1, GPIOC, GPIO_PIN_8);
//	LED_init(&LED_2, GPIOC, GPIO_PIN_6);
//	LED_init(&LED_3, GPIOC, GPIO_PIN_5);
//
//	Ultraosnic_init(&Ultrasonic_1, &htim1, Ultrasonic1_Trig_Port, Ultrasonic1_Trig_Pin,
//			Ultrasonic1_Echo_Port, Ultrasonic1_Echo_Pin);
//	Ultraosnic_init(&Ultrasonic_2, &htim2, Ultrasonic2_Trig_Port, Ultrasonic2_Trig_Pin,
//			Ultrasonic2_Echo_Port, Ultrasonic2_Echo_Pin);
//	Ultraosnic_init(&Ultrasonic_3, &htim3, Ultrasonic3_Trig_Port, Ultrasonic3_Trig_Pin,
//			Ultrasonic3_Echo_Port, Ultrasonic3_Echo_Pin);
//
//	LCD_init();
//	DelayInit();
//}

//int APMain()
//{
//	sys_init();
//	Listener_init(&huart2);
//
//	while (1)
//	{
//		Listener_CarMode_EventCheck();
//
//	}
//
//	return 0;
//}
