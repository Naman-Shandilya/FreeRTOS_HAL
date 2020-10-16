/*
 * 4x4_Keypad_APIs.c
 */

#include "4x4_Keypad_APIs.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"

#define SET_ROW1_HIGH			HAL_GPIO_WritePin(KEYPAD_ROW_1_PIN_GPIO_Port, KEYPAD_ROW_1_PIN_Pin, GPIO_PIN_SET)
#define SET_ROW2_HIGH			HAL_GPIO_WritePin(KEYPAD_ROW_2_PIN_GPIO_Port, KEYPAD_ROW_2_PIN_Pin, GPIO_PIN_SET)
#define SET_ROW3_HIGH			HAL_GPIO_WritePin(KEYPAD_ROW_3_PIN_GPIO_Port, KEYPAD_ROW_3_PIN_Pin, GPIO_PIN_SET)
#define SET_ROW4_HIGH			HAL_GPIO_WritePin(KEYPAD_ROW_4_PIN_GPIO_Port, KEYPAD_ROW_4_PIN_Pin, GPIO_PIN_SET)
#define SET_ROW1_LOW			HAL_GPIO_WritePin(KEYPAD_ROW_1_PIN_GPIO_Port, KEYPAD_ROW_1_PIN_Pin, GPIO_PIN_RESET)
#define SET_ROW2_LOW			HAL_GPIO_WritePin(KEYPAD_ROW_2_PIN_GPIO_Port, KEYPAD_ROW_2_PIN_Pin, GPIO_PIN_RESET)
#define SET_ROW3_LOW			HAL_GPIO_WritePin(KEYPAD_ROW_3_PIN_GPIO_Port, KEYPAD_ROW_3_PIN_Pin, GPIO_PIN_RESET)
#define SET_ROW4_LOW			HAL_GPIO_WritePin(KEYPAD_ROW_4_PIN_GPIO_Port, KEYPAD_ROW_4_PIN_Pin, GPIO_PIN_RESET)

#define READ_COLUMN_1			HAL_GPIO_Read_Pin(KEYPAD_COLUMN_1_PIN_GPIO_Port, KEYPAD_COLUMN_1_PIN_Pin)
#define READ_COLUMN_2			HAL_GPIO_Read_Pin(KEYPAD_COLUMN_2_PIN_GPIO_Port, KEYPAD_COLUMN_2_PIN_Pin)
#define READ_COLUMN_3			HAL_GPIO_Read_Pin(KEYPAD_COLUMN_3_PIN_GPIO_Port, KEYPAD_COLUMN_3_PIN_Pin)
#define READ_COLUMN_4			HAL_GPIO_Read_Pin(KEYPAD_COLUMN_4_PIN_GPIO_Port, KEYPAD_COLUMN_4_PIN_Pin)


const char Keypad_Button_Values[4][4] = { {'1', '2', '3', 'A'},
										  {'4', '5', '6', 'B'},
										  {'7', '8', '9', 'C'},
										  {'*', '0', '#', 'D'},
										};

static void Set_Keypad_Row(uint8_t Row)
{
	SET_ROW1_HIGH;
	SET_ROW2_HIGH;
	SET_ROW3_HIGH;
	SET_ROW4_HIGH;

	if(Row == 1)
	{
		SET_ROW1_LOW;
	}

	if(Row == 2)
	{
		SET_ROW2_LOW;
	}
	if(Row == 3)
	{
		SET_ROW3_LOW;
	}
	if(Row == 4)
	{
		SET_ROW4_LOW;
	}
}

static char Check_Keypad_Column(uint8_t Row)
{
	if(!READ_COLUMN_1)
	{
		while(!READ_COLUMN_1);
		return Keypad_Button_Values[Row-1][0];
	}

	if(!READ_COLUMN_2)
	{
		while(!READ_COLUMN_2);
		return Keypad_Button_Values[Row-1][1];
	}

	if(!READ_COLUMN_3)
		{
			while(!READ_COLUMN_3);
			return Keypad_Button_Values[Row-1][2];
		}

	if(!READ_COLUMN_4)
		{
			while(!READ_COLUMN_4);
			return Keypad_Button_Values[Row-1][3];
		}

	return KEYPAD_NOT_PRESSED;
}

void KEYPAD_Init(void)
{
	SET_ROW1_LOW;
	SET_ROW2_LOW;
	SET_ROW3_LOW;
	SET_ROW4_LOW;
}


char KEYPAD_Read(void)
{
	char check;
	Set_Keypad_Row(1);
	check = Check_Keypad_Column(1);
	if(check)
		return check;

	Set_Keypad_Row(2);
	check = Check_Keypad_Column(2);
	if(check)
		return check;

	Set_Keypad_Row(3);
	check = Check_Keypad_Column(3);
	if(check)
		return check;

	Set_Keypad_Row(4);
	check = Check_Keypad_Column(4);
	if(check)
		return check;

	return KEYPAD_NOT_PRESSED;
}
