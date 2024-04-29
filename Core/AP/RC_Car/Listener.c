/*
 * Listener.c
 *
 *  Created on: Apr 26, 2024
 *      Author: k1min
 */


#include "Listener.h"

//UART_HandleTypeDef *myHuart;
//extern uint8_t rcvData;
//Que_t uart2RxQue;

uint8_t CarModeBuf[20];
uint8_t index_carmodebuf;
uint8_t CarModeState_Li;
uint8_t rxFlag;

/*
 * Listener
 * 1. Receive a string via UART to decide modeState & save in Model
 *
 */

void Listener_ISR_Process(uint8_t rcvData)
{
	if(rcvData == '\n')			// Check the last char in a string
	{
		rxFlag = 1;
		printf("rxFlag : %d  rxCmplt\n", rxFlag);		// for debugㅡㅡㅡㅡㅡㅡㅡㅡ
		return;								// for not save '\n'
	}
	enQue_CarModeState(rcvData);
}

void Listener_init()
{
	CarModeState_Li = OFF;
	Listener_clearModeBuf();
}

void Listener_CarMode_EventCheck()
{
	if(!rxFlag) return;			// Execute only one time when received on UART

  uint8_t ch = deQue_CarModeState();
	if(ch)
	{
		static int iii = 0;								// for debugㅡㅡㅡㅡㅡㅡㅡㅡ
		printf("%d   %c\n", iii++, ch);		// for debugㅡㅡㅡㅡㅡㅡㅡㅡ
		CarModeBuf[index_carmodebuf++] = ch;
	}

	if (strcmp(CarModeBuf, "OFF") == 0)
	{
		CarModeState_Li = OFF;
		Model_setCarModeState(CarModeState_Li);
		printf("Buffer : %s  compareSuc\n", CarModeBuf);		// for debugㅡㅡㅡㅡㅡㅡㅡ
	}
	else if (strcmp(CarModeBuf, "FORW") == 0)
	{
		CarModeState_Li = FORWARD;
		Model_setCarModeState(CarModeState_Li);
		printf("Buffer : %s  compareSuc\n", CarModeBuf);		// for debugㅡㅡㅡㅡㅡㅡㅡ
	}
	else if (strcmp(CarModeBuf, "BACK") == 0)
	{
		CarModeState_Li = BACKWARD;
		Model_setCarModeState(CarModeState_Li);
		printf("Buffer : %s  compareSuc\n", CarModeBuf);		// for debugㅡㅡㅡㅡㅡㅡㅡ
	}
	else if (strcmp(CarModeBuf, "RIGHT") == 0)
	{
		CarModeState_Li = RIGHT_FORWARD;
		Model_setCarModeState(CarModeState_Li);
	}
	else if (strcmp(CarModeBuf, "LEFT") == 0)
	{
		CarModeState_Li = LEFT_FORWARD;
		Model_setCarModeState(CarModeState_Li);
	}

	if(Que_Car_isEmpty())
	{
		printf("Buffer : %s  queEmpty\n", CarModeBuf);		// for debugㅡㅡㅡㅡㅡㅡㅡ
		rxFlag = 0;
		Listener_clearModeBuf();
	}
}

void Listener_clearModeBuf()
{
	memset(CarModeBuf, '\0', 20);
	index_carmodebuf = 0;
	printf("ClearBuffer\n");		// for debug---------------
	printf("--------------------------\n");
}
