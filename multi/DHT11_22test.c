///
/// DHTtest.c: test program that uses libDHT to read from two temperature sensors
///
////////////////////////////////////////////////////////////////////////////////////////

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <DHT.h>

int main (void)
{
    DHT *DHT11_1                   = NULL;
    DHT *DHT11_2                   = NULL;
    DHT *DHT22                     = NULL;

    fprintf (stdout, "wiringPi / libDHT DHT11/DHT22 temperature/humidity sensor test\n");

    if (wiringPiSetup ()          == -1)
    {
        fprintf (stderr, "[ERROR] Could not initialize wiringPi\n");
        exit (1);
    }

    DHT_init (&DHT11_1, 4, SENSOR_TYPE_DHT11);
    DHT_init (&DHT11_2, 5, SENSOR_TYPE_DHT11);
    DHT_init (&DHT22, 6, SENSOR_TYPE_DHT22);

    while (1)
    {
        DHT11_1 -> read (&DHT11_1);

        if (DHT11_1 -> cached       == TRUE)
        {
            fprintf (stdout, "[cached] ");
        }
        else
        {
            fprintf (stdout, "         ");
        }

        fprintf (stdout, "DHT11_1: Humidity = %.1f %% ",  DHT11_1 -> humidity);
        fprintf (stdout, "Temperature = %.1f *C ",        DHT11_1 -> celcius);
        fprintf (stdout, "(%.1f *F)\n",                   DHT11_1 -> fahrenheit);

        DHT11_2 -> read (&DHT11_2);

        if (DHT11_2 -> cached       == TRUE)
        {
            fprintf (stdout, "[cached] ");
        }
        else
        {
            fprintf (stdout, "         ");
        }

        fprintf (stdout, "DHT11_2: Humidity = %.1f %% ",  DHT11_2 -> humidity);
        fprintf (stdout, "Temperature = %.1f *C ",        DHT11_2 -> celcius);
        fprintf (stdout, "(%.1f *F)\n",                   DHT11_2 -> fahrenheit);

        DHT22 -> read (&DHT22);

        if (DHT22 -> cached       == TRUE)
        {
            fprintf (stdout, "[cached] ");
        }
        else
        {
            fprintf (stdout, "         ");
        }

        fprintf (stdout, "DHT22:   Humidity = %.1f %% ",  DHT22 -> humidity);
        fprintf (stdout, "Temperature = %2.1f *C ",       DHT22 -> celcius);
        fprintf (stdout, "(%.1f *F)\n",                   DHT22 -> fahrenheit);

        fprintf (stdout, "-------------------------------------------------------\n");
        delay (2000); /* wait 2 seconds before next read */
    }
    return (0);
}
