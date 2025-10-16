#ifndef RESPONSE_H
#define RESPONSE_H
#include "stm32f1xx_hal.h"
#include "stdio.h"
#include "stdarg.h"
#include "string.h"
void res_init (UART_HandleTypeDef *huartx);
void response_print (const char* str,...);
#endif