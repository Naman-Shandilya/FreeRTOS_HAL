/*
 * 4x4_Keypad_APIs.h
 */

#ifndef _4X4_KEYPAD_APIS_H

#define _4X4_KEYAPD_APIS_H

#include "main.h"
#include <stdint.h>

#define NULL_CHARACTER				'\0'
#define KEYPAD_NOT_PRESSED			NULL_CHARACTER

void KEYPAD_Init(void);

char KEYPAD_Read(void);








#endif //_4X4_KEYPAD_APIS_H
