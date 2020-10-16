/*
 * GSM_A6_Driver.h
 */

#ifndef _GSM_A6_DRIVER_H
#define _GSM_A6_DRIVER_H


#include "main.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"

#define RX_BUFFER_SIZE			128

int GSM_Compare_GSMData_With(const char* string);

void GSM_Send_AT_Command(char* AT_CMD);

void GSM_Make_Call(char* phone_number);

void GSM_Receive_Call(void);

void GSM_HangUp_Call(void);

void GSM_Send_SMS(char* Message, char* phone_number);

void GSM_Receive_SMS(void);

void GSM_Init(void);

void GSM_Clear_RX_buffer(void);







#endif //GSM_A6_Driver.h
