#include "uart2.h"
#define max_uart_buff 50 
uint8_t buff[max_uart_buff];
uint8_t uart_len =0 ;
uint8_t uart_flag = 0;
void uart_receive(uint8_t data_rx)
{
 if(data_rx=='\n')
 {
	 uart_flag = 1 ;
	 buff[uart_len++]='\0';
 }
 else 
 {
	 buff[uart_len++]=data_rx;
 }
}
void uart_handle (DHT11*ht)
{ 
	if(uart_flag==1)
	{
	 char * argv[20];
	 uint8_t argv_num =0 ;
	 char*token=strtok((char*)buff," ");
	 while(token!=NULL)
	 {
		 argv[argv_num++]=token;
		 token=strtok(NULL," ");
	 }
	 if(strcmp(argv[0],"get")==0)
	 {
		 get(argv,argv_num,ht);
	 }
	 uart_len =0 ;
   uart_flag = 0;	
	}
}