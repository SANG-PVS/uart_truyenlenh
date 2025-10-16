#ifndef DHT11_H
#define DHT11_H
#include "stm32f1xx_hal.h"
typedef struct 
{
uint8_t int_Tem;
uint8_t int_Hum;
uint8_t float_Tem;
uint8_t float_Hum;
uint8_t Checksum;
} valuedht11 ;
typedef struct 
{
	GPIO_TypeDef  *GPIOx;
	uint16_t GPIO_Pin ;
	valuedht11 value_dht;
} DHT11 ;
uint8_t get_Hum (DHT11*ht);
uint8_t get_Tem (DHT11*ht);
void DHT11_init (DHT11*ht,GPIO_TypeDef  *GPIO1,uint16_t GPIO_Pin1);
#endif 
