#include "nhap_nhay2.h"
static void setOutput(char**argv,gpio_led*led, uint8_t i)
{
	GPIO_InitTypeDef setinit = {0};
	setinit.Pin = GPIO_PIN_0<<atoi(argv[i]) ;
	setinit.Mode= GPIO_MODE_OUTPUT_PP;
	setinit.Pull = GPIO_NOPULL;
  setinit.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(led->GPIOx,&setinit);	
}
void nhap_nhay(char**argv,uint8_t argv_num,gpio_led*led)
{ 
	if(strcmp(argv[1],"on")==0)
	{
		 for( uint8_t i=2 ;i<argv_num;i++)
		 {
			 setOutput(argv,led,i);
			 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0<<atoi(argv[i]),1);
			 response_print(" da bat led so %d",atoi(argv[i]));
			 response_print ("\n");
		 }
	}
	else if(strcmp(argv[1],"off")==0)
	{
		 for( uint8_t i=2 ;i<argv_num;i++)
		 {
			  setOutput(argv,led,i);
	      HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0<<atoi(argv[i]),0);
			  response_print( " da tat led so %d ",atoi(argv[i]));
			  response_print ("\n");
		 }
		}
}
void nhay_led_init (gpio_led*led,GPIO_TypeDef * gpiox)
{
	led->GPIOx = gpiox;
}