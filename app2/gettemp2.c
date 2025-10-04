#include "gettemp2.h"
void gettemp(char**argv,uint8_t argv_num)
{
	if(argv_num>=2)
	{
		response_print("du %d doi so roi cot oi",argv_num);
	}
	else
	{
		response_print("chua du doi so ni oi ");
	}
}
