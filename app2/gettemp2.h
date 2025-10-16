#ifndef GETTEMP_H
#define GETTEMP_H
#include "response.h"
#include "DHT11.h"
void get(char**argv,uint8_t argv_num,DHT11*dt);
#endif