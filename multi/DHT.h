/***
 *** Filename    : DHT.h
 *** Description : C libDHT multiple sensor library
 ***               Made to substitute for the C++ DHT code in the Freenove tutorial
 *** Author      : Matthew Haas
 *** modification: 2025/10/02
 *** Reference   : https://www.uugear.com/
 ***                   portfolio/dht11-humidity-temperature-sensor-module/
 ***               https://github.com/
 ***                   Qengineering/DHT22-Raspberry-Pi
 ***                   Freenove/Freenove_Ultimate_Starter_Kit_for_Raspberry_Pi/
 ***                       tree/master/Code/C_Code/21.1.1_DHT11
 ***                   RobTillaart/Arduino/tree/master/libraries/DHTlib
 ***
 **************************************************************************************/

#ifndef _DHT_H_
#define _DHT_H_

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define  TIMING                   0
#define  STATE                    1

#define  MAX_TIMINGS             85
#define  SENSOR_TYPE_DHT11        0
#define  SENSOR_TYPE_DHT22        1

#define  DHTLIB_OK                0
#define  DHTLIB_ERROR_CHECKSUM   -1
#define  DHTLIB_ERROR_TIMEOUT    -2
#define  DHTLIB_ERROR_ALLOC      -3
#define  DHTLIB_INVALID_VALUE  -999

#define  DHTLIB_DHT11_WAKEUP     20
#define  DHTLIB_DHT_WAKEUP        1

#define  DHTLIB_TIMEOUT         100

typedef struct dht      DHT;
typedef struct pulse    Pulse;
typedef struct timespec TIMESPEC;

struct pulse
{
    int       timing;
    int       state;
};

struct dht
{
    float     celcius;
    float     fahrenheit;
    float     humidity;
    uint16_t  byte[5];
    uint16_t *checksum;
    uint8_t   cached;
    uint8_t   gpio_pin;
    uint8_t   type;
    uint8_t   pulses;
    Pulse    *signal;
    int      (*read) (DHT **);
};

int  DHT_init (DHT **, uint8_t, uint8_t);
int  DHT_read (DHT **);

#endif
