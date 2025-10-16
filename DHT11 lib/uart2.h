#ifndef UART_H
#define UART_H
#include "stm32f1xx_hal.h"
#include "stdio.h"
#include "string.h"
#include "gettemp2.h"
void uart_receive(uint8_t data_rx);
void uart_handle (DHT11*ht);
#endif
