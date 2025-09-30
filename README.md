# libDHT

C ports of  Freenove DHT C++ Library for accessing  the DHT11 temperature
and humidity sensor with wiringPi.

The plan is to support both the DHT11 and DHT22.

## Freenove

These ports are based on code  originally written in C++ for the Freenove
Raspberry Pi  electronics kits and  circuits presented in  their Tutorial
(specifically, their `FNK0020` kit).

Source repository can be found at:

  * https://github.com/Freenove/Freenove_Ultimate_Starter_Kit_for_Raspberry_Pi

## C ports

### multi: de-OOP-ified multi-module capable libDHT

An "in  the spirit  of" port of  the original DHT  C++ code,  which could
support **multi**ple DHT modules in a program.

There is  a "DHT" struct  making use of  function pointers to  provide "a
reasonably close" approximation of functionality.

A consequence of this  is that the functions have to  pass (by address) a
pointer to an instance of the DHT struct.

### global: de-OOP-ified single module capable libDHT via global variable

The  de-OOP-ified implementation  above  gets a  lot cleaner-looking  if,
instead of the ability to support multiple `DHT` instances, we only allow
for one, and make that instance a **global** variable.

The same selection  of `DHT` modules is available, just  we're locking in
to using exactly one per program.

This  will  likely be  an  acceptable  "average  case"  for a  number  of
utilizations, especially if following the Freenove Tutorial.

## Building

These  implementations,  like  their   Freenove  C++  ancestor,  build  a
shared-object library  (`libDHT.so`) which is installed  with the `DHT.h`
header  file,  into the  system  directories  where these  resources  are
typically found.

Instead of a `build.sh` script, a UNIX Makefile is provided that does the
work of building and installing.

  0. ensure you have the `wiringPi` package installed
  1. build the library by running: `make`
  2. install the library by running: `sudo make install`
  3. build the `DHTtest` program: `make test`
  4. run the `DHTtest` program: `./DHTtest`

If there are any errors, be sure to address them before proceeding.
