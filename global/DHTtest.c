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

////////////////////////////////////////////////////////////////////////////////////////
//
// for the global variant, declare our variable in global scope
//
DHT *sensor;

int32_t  main (void)
{
    ////////////////////////////////////////////////////////////////////////////////////
    //
    // for the global variant, declare our variable in global scope
    //
    sensor                         = NULL;

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
    // Configure the sensor as a DHT11 (on the indicated wiringPi pin)
    //
    DHT_init (12, SENSOR_TYPE_DHT11);

    fprintf (stdout, "wiringPi / libDHT temperature/humidity sensor test\n");
    fprintf (stdout, "Program starting (CTRL-c to interrupt) ...\n");

    while (1)
    {
        ////////////////////////////////////////////////////////////////////////////////
        //
        // Perform a read transaction on our sensor
        //
        sensor     -> read ();

        ////////////////////////////////////////////////////////////////////////////////
        //
        // Check if the read was successful; if not, we use previously obtained
        // (cached) data
        //
        if (sensor -> cached      == TRUE)
        {
            fprintf (stdout, "[cached] ");
        }

        ////////////////////////////////////////////////////////////////////////////////
        //
        // Display the results of our recent transaction
        //
        fprintf (stdout, "DHT11: Humidity = %.1f %% ",    sensor -> humidity);
        fprintf (stdout, "Temperature = %.1f *C ",        sensor -> celcius);
        fprintf (stdout, "(%.1f *F)\n",                   sensor -> fahrenheit);

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
