/*
 * defineModel.h
 *
 *  Created on: Apr 27, 2024
 *      Author: k1min
 */

#ifndef AP_RC_CAR_DEFINEMODEL_H_
#define AP_RC_CAR_DEFINEMODEL_H_


#include "../Driver/Motor/Motor.h"
#include "../Driver/Button/Button.h"
#include "../Driver/LED/LED.h"
#include "../Driver/CLCD/CLCD.h"
#include "../Driver/Ultrasonic/Ultrasonic.h"
#include "../Driver/Motor/Motor.h"
#include <stdio.h>


#define Ultrasonic1_Trig_Port			GPIOC
#define Ultrasonic1_Trig_Pin			GPIO_PIN_0
#define Ultrasonic1_Echo_Port			GPIOC
#define Ultrasonic1_Echo_Pin			GPIO_PIN_1

#define Ultrasonic2_Trig_Port			GPIOB
#define Ultrasonic2_Trig_Pin			GPIO_PIN_0
#define Ultrasonic2_Echo_Port			GPIOA
#define Ultrasonic2_Echo_Pin			GPIO_PIN_4

#define Ultrasonic3_Trig_Port			GPIOC
#define Ultrasonic3_Trig_Pin			GPIO_PIN_3
#define Ultrasonic3_Echo_Port			GPIOC
#define Ultrasonic3_Echo_Pin			GPIO_PIN_2

// Motor define
#define LEFT_DIR1_Port						GPIOC
#define LEFT_DIR1_Port_Pin				GPIO_PIN_7
#define LEFT_DIR2_Port						GPIOB
#define LEFT_DIR2_Port_Pin				GPIO_PIN_4

#define RIGHT_DIR1_Port						GPIOA
#define RIGHT_DIR1_Port_Pin				GPIO_PIN_8
#define RIGHT_DIR2_Port						GPIOB
#define RIGHT_DIR2_Port_Pin				GPIO_PIN_10

//#define turnDifferSpeed						400
//#define MotorSpeed								1000


typedef enum{
	OFF,
	FORWARD,
	BACKWARD,
	RIGHT_FORWARD,
	LEFT_FORWARD
}CarModeState_t;

typedef struct{
	UART_HandleTypeDef *myHuart;
	TIM_HandleTypeDef *motor_htim;
	TIM_HandleTypeDef *UltraRight_htim;
	TIM_HandleTypeDef *UltraCenter_htim;
	TIM_HandleTypeDef *UltraLeft_htim;
}handler_t;

typedef struct{
	Motor_t hLeftMotor;
	Motor_t hRightMotor;
}com_hMotor_t;

typedef struct{
	Ultrasonic_t LeftUltra;
	Ultrasonic_t CenterUltra;
	Ultrasonic_t RightUltra;
}com_hUltra_t;


void Model_hardwareinit(UART_HandleTypeDef *inHuart,
		TIM_HandleTypeDef *motor_inHtim,
		TIM_HandleTypeDef *UltraLeft_inHtim, TIM_HandleTypeDef *UltraCenter_inHtim, TIM_HandleTypeDef *UltraRight_inHtim);

handler_t *Model_getHandler();
com_hMotor_t *Model_getHandleMotor();

uint8_t Model_getCarModeState();
void Model_setCarModeState(uint8_t data);


#endif /* AP_RC_CAR_DEFINEMODEL_H_ */
