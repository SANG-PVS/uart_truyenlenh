#include "response.h"
static UART_HandleTypeDef *huart_res;
void response_print (const char* str,...)
{
	char buffer[100];//khai bao bo dem de luu 
	va_list args ;//khai bao kieu du lieu va_list args
	va_start(args,str);// dat con tro sau fomat str de lay chuoi
	vsprintf(buffer,str,args);//quet fomat den kieu du lieu nao se lay du lieu kieu do 
	va_end(args);
	HAL_UART_Transmit(huart_res,(uint8_t*)buffer,strlen(buffer),100);//gui nguoc lai phan hoi 
}
void res_init (UART_HandleTypeDef *huartx)
{
	huart_res=huartx;
}