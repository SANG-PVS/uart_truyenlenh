#ifndef RESPOND_H
#define RESPOND_H
#include <stdarg.h>
#include <stdio.h>
#include "stm32f1xx_hal.h"
#include "string.h"
void Respond_print(const char*str,...);
void Res_init (UART_HandleTypeDef*huartx);
#endif
