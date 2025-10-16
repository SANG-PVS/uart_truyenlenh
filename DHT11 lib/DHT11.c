#include "DHT11.h"
#include "Us.h"
void setOutput(DHT11*ht)
{
	GPIO_InitTypeDef setinit = {0};
	setinit.Pin = ht->GPIO_Pin;
	setinit.Mode= GPIO_MODE_OUTPUT_PP;
	setinit.Pull = GPIO_PULLUP;
	setinit.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ht->GPIOx,&setinit);	
}
void setInput(DHT11*ht)
{
	GPIO_InitTypeDef setinit = {0};
	setinit.Pin = ht->GPIO_Pin;
	setinit.Mode= GPIO_MODE_INPUT;
	setinit.Pull = GPIO_NOPULL;
  setinit.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ht->GPIOx,&setinit);	
}
void DHT11_start (DHT11*ht)
{
	setOutput(ht);
	HAL_GPIO_WritePin(ht->GPIOx,ht->GPIO_Pin,0);
	HAL_Delay(20);
	HAL_GPIO_WritePin(ht->GPIOx,ht->GPIO_Pin,1);
	delay_us(30);
	setInput(ht);
	while(HAL_GPIO_ReadPin(ht->GPIOx,ht->GPIO_Pin)==1);//cho keo xuong muc 0 
	while(HAL_GPIO_ReadPin(ht->GPIOx,ht->GPIO_Pin)==0);// sau do lai keo len de san sang truyen
	while(HAL_GPIO_ReadPin(ht->GPIOx,ht->GPIO_Pin)==1);// keo xuong muc low ( pha 1 ) 
}
uint8_t DHT11_read_byte (DHT11*ht)
{
	uint8_t data = 0 , i =0;
	for(i=0;i<8;i++)
	{
		while (HAL_GPIO_ReadPin(ht->GPIOx,ht->GPIO_Pin)==0);// keo len pha 2 
		delay_us(50);
		if ( HAL_GPIO_ReadPin(ht->GPIOx,ht->GPIO_Pin)==1)
		{
			data = (data<<1)|(1<<0);
		}
		else 
		{
			data=(data<<1)&~(1<<0);
		}
		while(HAL_GPIO_ReadPin(ht->GPIOx,ht->GPIO_Pin)==1);// cho keo xuong muc thap de truyen bit moi 
	}
	return data ;
}
void DHT11_Handle(DHT11*ht){
	DHT11_start(ht);
	ht->value_dht.int_Hum=DHT11_read_byte(ht);
	ht->value_dht.float_Hum=DHT11_read_byte(ht);
	ht->value_dht.int_Tem=DHT11_read_byte(ht);
	ht->value_dht.float_Tem=DHT11_read_byte(ht);
	ht->value_dht.Checksum =DHT11_read_byte(ht);
	HAL_Delay (1000);
	//get_Hum (ht->value_dht.int_Hum);
}
uint8_t get_Hum (DHT11*ht)
{
	DHT11_Handle(ht);
	HAL_Delay (1000);
	return ht->value_dht.int_Hum ;
}
uint8_t get_Tem (DHT11*ht)
{ 
	DHT11_Handle(ht);
	return ht->value_dht.int_Tem ;
}
void DHT11_init (DHT11*ht,GPIO_TypeDef  *GPIO1,uint16_t GPIO_Pin1)
{
	ht->GPIOx = GPIO1;
	ht->GPIO_Pin=GPIO_Pin1;
}