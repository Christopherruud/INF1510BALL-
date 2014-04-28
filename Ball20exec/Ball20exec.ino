//Import libraries

#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <SD.h>

/** Framework and pseudocode for the Ball2.0 project 
 * Much of this code is derived from examples in various
 * libraries,for instance the TinyGPS++ library and so on.
 * 
 **/


//Initialize constants for pins
static const int GPSRXPin = 3, GPSTXPin = 2;
static const uint32_t GPSBaud = 4800;
static const int SD_PIN_OUT = 10;


//Initialize variables for stuff

//Gps-related
TinyGPSPlus gps;
SoftwareSerial ss(GPSRXPin, GPSTXPin);

// SD-card related stuff
File logFile;


//general

long timeStamp;

void setup() {
  pinMode(SD_PIN_OUT, OUTPUT);

timeStamp = millis();
}


void loop() {

  String dataString = "";

  /**  read three sensors and append to the string:
   * Will need to be changed for our data.
   *
   *
   * for (int analogPin = 0; analogPin < 3; analogPin++) {
   * int sensor = analogRead(analogPin);
   * dataString += String(sensor);
   * if (analogPin < 2) {
   * dataString += ","; 
   * }
   }**/
//read timestamp, add to string

//read from GPS, append to String

//read from Accelerometer, append to string

//read from Gyroscope, append to string



  // if the file is available, write to it:
  if (logFile) {
    logFile.println(dataString);
    logFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  } 

//stop - conditions, close file, stop logging

}



