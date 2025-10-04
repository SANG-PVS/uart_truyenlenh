#ifndef NHAP_NHAY_H
#define NHAP_NHAY_H
#include "string.h"
#include "stdlib.h"
#include "stm32f1xx_hal.h"
#include "response.h"
typedef struct
{
	GPIO_TypeDef  *GPIOx;
} gpio_led ;
void nhap_nhay(char**argv,uint8_t argv_num,gpio_led*led);
void nhay_led_init (gpio_led*led,GPIO_TypeDef * gpiox);
#endif