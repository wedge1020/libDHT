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
    DHT *DHT11                     = NULL;
    DHT *DHT22                     = NULL;

    fprintf (stdout, "wiringPi / libDHT DHT11/DHT22 temperature/humidity sensor test\n");

    if (wiringPiSetup ()          == -1)
    {
        fprintf (stderr, "[ERROR] Could not initialize wiringPi\n");
        exit (1);
    }

    DHT_init (&DHT11, 12, SENSOR_TYPE_DHT11);
    DHT_init (&DHT22, 13, SENSOR_TYPE_DHT22);

    while (1)
    {
        read_DHT_data (&DHT11);

        if (DHT11 -> cached       == TRUE)
        {
            fprintf (stdout, "[cached] ");
        }

        fprintf (stdout, "DHT11: Humidity = %.1f %% ",    DHT11 -> humidity);
        fprintf (stdout, "Temperature = %.1f *C ",        DHT11 -> celcius);
        fprintf (stdout, "(%.1f *F)\n",                   DHT11 -> fahrenheit);

        read_DHT_data (&DHT22);

        if (DHT22 -> cached       == TRUE)
        {
            fprintf (stdout, "[cached] ");
        }

        fprintf (stdout, "DHT22: Humidity = %.1f %% ",    DHT22 -> humidity);
        fprintf (stdout, "Temperature = %.1f *C ",        DHT22 -> celcius);
        fprintf (stdout, "(%.1f *F)\n",                   DHT22 -> fahrenheit);

        delay (2000); /* wait 2 seconds before next read */
    }
    return (0);
}
