#include "Respond.h"
static UART_HandleTypeDef*huart_res;
 void Respond_print(const char*str,...)
 {
	  char buffer[100];//khai bao bo dem de luu
	  va_list args;// khai bao bien kieu va_list ten la args
	  va_start(args,str);// dat con tro sau fomat str de bat dau 
	  vsprintf(buffer,str,args);// quet fomat , den kieu du lieu nao se goi va_args de lay chuoi 
	  va_end(args);// ket thuc 
	  HAL_UART_Transmit(huart_res,(uint8_t*)buffer,strlen(buffer),100);
 }
 void Res_init (UART_HandleTypeDef*huartx)
{
	huart_res=huartx;
}