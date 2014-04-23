//Import libraries

#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Wire.h>

/** Framework and pseudocode for the Ball2.0 project 
 * Much of this code is derived from examples in various
 * libraries,for instance the TinyGPS++ library and so on.
 * 
 **/


//Initialize constants for pins
static const int GPSRXPin = 3, GPSTXPin = 2;
static const uint32_t GPSBaud = 4800;


//Initialize variables for stuff

//Gps-related
TinyGPSPlus gps;
SoftwareSerial ss(GPSRXPin, GPSTXPin);


void setup() {

}


void loop() {

}

