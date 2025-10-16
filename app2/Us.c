#include "Us.h"
extern TIM_HandleTypeDef htim1;
void delay_us(uint16_t time_us)
{
	HAL_TIM_Base_Start(&htim1);
	__HAL_TIM_SET_COUNTER(&htim1,0);
	while(__HAL_TIM_GET_COUNTER(&htim1)< time_us);
	HAL_TIM_Base_Stop(&htim1);
}