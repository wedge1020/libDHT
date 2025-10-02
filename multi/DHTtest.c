/*
 *  dht.c:
 *    read temperature and humidity from DHT11 or DHT22 sensor
 */
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <DHT.h>

int main (void)
{
    DHT *DHT11                     = NULL;

    DHT_init (&DHT11, 12, SENSOR_TYPE_DHT11);

    fprintf (stdout, "Raspberry Pi DHT11/DHT22 temperature/humidity sensor test\n");

    if (wiringPiSetup ()          == -1)
    {
        fprintf (stderr, "[ERROR] Could not initialize wiringPi\n");
        exit (1);
    }

    while (1)
    {
        read_DHT_data (&DHT11);

        if (DHT11 -> cached       == TRUE)
        {
            fprintf (stdout, "[cached] ");
        }

        fprintf (stdout, "Humidity = %.1f %% ",    DHT11 -> humidity);
        fprintf (stdout, "Temperature = %.1f *C ", DHT11 -> celcius);
        fprintf (stdout, "(%.1f *F)\n",            DHT11 -> fahrenheit);

        delay (2000); /* wait 2 seconds before next read */
    }
    return (0);
}
