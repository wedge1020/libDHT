/***
 *** Filename    : DHT.hpp
 *** Description : DHT Temperature & Humidity Sensor library for Raspberry.
 ***               Used for Raspberry Pi.
 ***               Program transplantation by Freenove.
 *** Author      : freenove
 *** modification: 2020/10/16
 *** Reference   : https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib
 ***
 **************************************************************************************/

#ifndef _DHT_H_
#define _DHT_H_

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

////read return flag of sensor
#define DHTLIB_OK               0
#define DHTLIB_ERROR_CHECKSUM   -1
#define DHTLIB_ERROR_TIMEOUT    -2
#define DHTLIB_INVALID_VALUE    -999

#define DHTLIB_DHT11_WAKEUP     20
#define DHTLIB_DHT_WAKEUP       1

#define DHTLIB_TIMEOUT          100

typedef struct dht DHT;
struct dht
{
	double   humidity;
	double   temperature;
	uint8_t  bits[5];
	DHT *   (*init_DHT)      (DHT *);
	int     (*readDHT)       (DHT *, int);
	int     (*readDHTOnce)   (DHT *, int);
	int     (*readSensor)    (DHT *, int, int);
};

DHT *init_DHT11    (DHT *);
int  readDHT11Once (DHT *, int);
int  readDHT11     (DHT *, int);

DHT *init_DHT22    (DHT *);
int  readDHT22Once (DHT *, int);
int  readDHT22     (DHT *, int);

/*
class DHT{      
    public:
        DHT();
        double humidity,temperature;    //use to store temperature and humidity data read
        int readDHT11Once(int pin);     //read DHT11
        int readDHT11(int pin);     //read DHT11
    private:
        uint8_t bits[5];    //Buffer to receiver data
        int readSensor(int pin,int wakeupDelay);    //
        
};

*/


#endif
