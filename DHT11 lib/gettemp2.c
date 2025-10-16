#include "gettemp2.h"
void get(char**argv,uint8_t argv_num,DHT11*ht)
{
	if(argv_num>=1)
		{
	   if(strcmp(argv[1],"Hum")==0)
	     {
		    response_print("do am hien tai la %d%%",get_Hum(ht));
				response_print("\n");
				response_print("temp");
	     }
	   else if (strcmp(argv[1],"Temp")==0)
	     {
		    response_print("nhiet do hien tai la %d do",get_Tem(ht));
				response_print("\n");
				 response_print("temp");
	     }
		  else if (strcmp(argv[1],"Temp&Hum")==0)
	     {
		    response_print("nhiet do va do am hien tai la %d do va %d%%",get_Tem(ht),get_Hum(ht));
				response_print("\n");
				 response_print("hum");
	     }
    }
}
