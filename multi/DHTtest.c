//
// DHTtest.c: test program that uses libDHT to read from two temperature sensors
//
////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
//
// Pre-processor directives
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <wiringPi.h>
#include <DHT.h>

int32_t  main (void)
{
    ////////////////////////////////////////////////////////////////////////////////////
    //
    // Declare and initialize variables for sensors
    //
    DHT *DHT11                     = NULL;
    DHT *DHT22                     = NULL;

    ////////////////////////////////////////////////////////////////////////////////////
    //
    // Initialize the wiringPi library
    //
    if (wiringPiSetup ()          == -1)
    {
        fprintf (stderr, "[ERROR] Could not initialize wiringPi\n");
        exit (1);
    }

    ////////////////////////////////////////////////////////////////////////////////////
    //
    // Configure the sensors as a DHT11 and DHT22 (on the indicated wiringPi pins)
    //
    DHT_init (&DHT11, 12, SENSOR_TYPE_DHT11);
    DHT_init (&DHT22, 13, SENSOR_TYPE_DHT22);

    fprintf (stdout, "wiringPi / libDHT temperature/humidity sensor test\n");
    fprintf (stdout, "Program starting (CTRL-c to interrupt) ...\n");

    while (1)
    {
        ////////////////////////////////////////////////////////////////////////////////
        //
        // Perform a read transaction on our DHT11 sensor
        //
        DHT11 -> read (&DHT11);

        ////////////////////////////////////////////////////////////////////////////////
        //
        // Check if the read was successful; if not, we use previously obtained
        // (cached) data
        //
        if (DHT11 -> cached       == TRUE)
        {
            fprintf (stdout, "[cached] ");
        }
        else
        {
            fprintf (stdout, "         ");
        }

        ////////////////////////////////////////////////////////////////////////////////
        //
        // Display the results of our recent transaction
        //
        fprintf (stdout, "DHT11: Humidity = %.1f %% ",    DHT11 -> humidity);
        fprintf (stdout, "Temperature = %.1f *C ",        DHT11 -> celcius);
        fprintf (stdout, "(%.1f *F)\n",                   DHT11 -> fahrenheit);

        ////////////////////////////////////////////////////////////////////////////////
        //
        // Perform a read transaction on our DHT22 sensor
        //
        DHT22 -> read (&DHT22);

        ////////////////////////////////////////////////////////////////////////////////
        //
        // Check if the read was successful; if not, we use previously obtained
        // (cached) data
        //
        if (DHT22 -> cached       == TRUE)
        {
            fprintf (stdout, "[cached] ");
        }
        else
        {
            fprintf (stdout, "         ");
        }

        ////////////////////////////////////////////////////////////////////////////////
        //
        // Display the results of our recent transaction
        //
        fprintf (stdout, "DHT22: Humidity = %.1f %% ",    DHT22 -> humidity);
        fprintf (stdout, "Temperature = %.1f *C ",        DHT22 -> celcius);
        fprintf (stdout, "(%.1f *F)\n",                   DHT22 -> fahrenheit);

        fprintf (stdout, "-------------------------------------------------------\n");

        ////////////////////////////////////////////////////////////////////////////////
        //
        // According to specifications, we must wait at least 2 seconds before the
        // next attempted read
        //
        delay (2000);
    }

    return (0);
}
