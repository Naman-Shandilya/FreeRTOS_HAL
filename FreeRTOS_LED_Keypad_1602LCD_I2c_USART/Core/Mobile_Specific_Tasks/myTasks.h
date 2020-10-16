/*
 * myTasks.h
 */
#ifndef _MYTASKS_H
#define _MYTASKS_H

#include "main.h"

//#include "1602_LCD_APIs.h"
//#include "4x4_Keypad_APIs.h"
//#include "GSM_A6_Driver.h"

extern char phone_num[10];

void Phone_Home_Display(void);
void Phone_Make_Call(void);
void Phone_Send_SMS(void);
void Phone_Receive_Call(void);
void Phone_Receive_SMS(void);
void Store_Phone_Number(char First_KeyPress_Val);



#endif
