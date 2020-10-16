/*
 * 1602_LCD_APIs.h
 */

#ifndef	_1602_LCD_APIS_H
#define _1602_LCD_APIS_H

#include "main.h"
#include "stm32f4xx.h"
#include <stdint.h>

//LCD control pins
#define PIN_RS						(1 << 0)
#define PIN_EN						(1 << 2)
#define BACKLIGHT					(1 << 3)

//I2C Module Address
#define I2C_SLAVE_ADDRESS			0x4E

//LCD Commands
#define LCD_FUNCTION_SET1			0x33
#define LCD_FUNCTION_SET2			0x32
#define LCD_4BIT_2LINE_MODE			0x28
#define LCD_DISP_CURS_ON			0x0E
#define LCD_DISP_ON_CURS_OFF		0x0C
#define LCD_DISPLAY_OFF				0x08
#define LCD_DISPLAY_ON				0x04
#define LCD_CLEAR_DISPLAY			0x01
#define LCD_ENTRY_MODE_SET			0x04
#define LCD_INCREMENT_CURSER		0x06
#define LCD_SET_ROW1_COL1			0x80
#define LCD_SET_ROW2_COL1			0xC0
#define LCD_MOVE_DISPLAY_LEFT		0x18
#define LCD_MOVE_DISPLAY_RIGHT		0x1C


void LCD_Init(void);
void LCD_Send_Cmd(uint8_t cmd);
void LCD_Send_Data(uint8_t data);
void LCD_Send_String(char *str);
void LCD_Clear_Then_Display(char *str);
void LCD_Send_String_On_Line1(char *str);
void LCD_Send_String_On_Line2(char *str);
void LCD_Display_Long_Message(char *str);










#endif //_1602_LCD_APIS_H
