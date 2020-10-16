/*
 * GSM_A6_Driver.c
 */

#include "GSM_A6_Driver.h"
#include <string.h>
#include <stdint.h>

extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef hdma_usart2_rx;

char RX_Buffer[RX_BUFFER_SIZE];

char Incomming_SMS_Phone_Num[13] = {'\0'};

char Incomming_SMS_Message[100] = {'\0'};

int GSM_Compare_GSMData_With(const char* string)
{
	char * ptr = NULL;
	ptr = strstr(RX_Buffer, string);
	if(ptr != NULL)
		return 1;
	else
		return 0;
}

void GSM_Send_AT_Command(char* AT_CMD)
{
	HAL_UART_Transmit(&huart2, (uint8_t*)AT_CMD, strlen(AT_CMD), 2000);
}

void GSM_Make_Call(char* phone_number)
{
	char AT_CMD[16] = "ATD+91";
	char CR[] = "\r";
	strcat(AT_CMD, phone_number);
	strcat(AT_CMD, CR);
	GSM_Send_AT_Command(AT_CMD);
}

void GSM_Receive_Call(void)
{
	GSM_Send_AT_Command("ATA\r");
	HAL_Delay(100);
}

void GSM_HangUp_Call(void)
{
	HAL_Delay(500);
	GSM_Send_AT_Command("ATH\r");
	HAL_Delay(500);

}

void GSM_Send_SMS(char* Message, char* phone_number)
{
	char SMS_AT_CMD1[] = "AT+CMGF=1\r";
	char SMS_AT_CMD2[21] = "AT+CMGS=+91";
	char CR[] = "\r";
	uint8_t MSG_END[] = {26};

	GSM_Send_AT_Command(SMS_AT_CMD1);
		//HAL_UART_Transmit(&myUARThandle,(uint8_t *)SMS_AT_CMD1, strlen(SMS_AT_CMD1),2000);
		HAL_Delay(750);
		GSM_Send_AT_Command(SMS_AT_CMD2);
		//HAL_UART_Transmit(&myUARThandle,(uint8_t *)SMS_AT_CMD2, strlen(SMS_AT_CMD2),2000);
		HAL_Delay(750);

		GSM_Send_AT_Command(Message);
		//HAL_UART_Transmit(&myUARThandle,(uint8_t *)Message, strlen(Message),2000);
		HAL_Delay(500);

		GSM_Send_AT_Command((char *)MSG_END);
		//HAL_UART_Transmit(&myUARThandle,(uint8_t *)MSG_END, sizeof(MSG_END),2000);
}

void GSM_Receive_SMS(void)
{
	char temp_buffer[RX_BUFFER_SIZE];
	int i = 0,j = 0,k = 0,l = 0,m = 0;

	while(i <= 127)
	{
		temp_buffer[i] = RX_Buffer[i];
		i++;
	}
	char phone_pattern[2] = {'"','+'};

	char* ptr = strstr(temp_buffer, phone_pattern);

	for(j=0; j<13; j++)
	{
		Incomming_SMS_Phone_Num[j] = ptr[1+j];
	}

	char sms_pattern[2] = {'6', '"'};

	ptr = strstr(temp_buffer, sms_pattern);

	for(k=0;k<4;k++)
	{
		ptr++;
		if(ptr == &temp_buffer[127])
		{
			if(k==3)
			{
				Incomming_SMS_Message[l] = *(ptr+m);
				l++;
			}

			ptr = &temp_buffer[0];
		}
	}
	while(*(ptr+m) !='\r')
	{
		if(ptr+m == &temp_buffer[127])
		{
			Incomming_SMS_Message[l] = *(ptr+m);
			ptr = &temp_buffer[0];
			m = 0;
		}
		else
		{
			Incomming_SMS_Message[l] = *(ptr+m);
			l++;
			m++;
		}
	}
}

void GSM_Init(void)
{
	HAL_UART_Receive_DMA(&huart2, (uint8_t *)RX_Buffer, RX_BUFFER_SIZE);

	HAL_Delay(20000);

	GSM_Send_AT_Command("AT\r");
	HAL_Delay(500);

	GSM_Send_AT_Command("AT+CMGF=1\r");
	HAL_Delay(500);

	GSM_Send_AT_Command("AT+CNMI=1,2,0,0,0\r");
	HAL_Delay(1000);

	GSM_CLEAR_RX_buffer();
}

void GSM_Clear_RX_buffer(void)
{
	int i;
	for(i=0; i<RX_BUFFER_SIZE;i++)
		RX_Buffer[i]='\r';
}

