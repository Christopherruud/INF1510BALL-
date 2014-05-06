//Import libraries

#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <SD.h>
#include<stdlib.h>

/** Framework and pseudocode for the Ball2.0 project 
 * Much of this code is derived from examples in various
 * libraries,for instance the TinyGPS++ library and so on.
 * 
 **/


//Initialize constants for pins
static const int GPSRXPin = 3, GPSTXPin = 2; //note that TX on arduino connects to RX on gps, and vice versa
static const uint32_t GPSBaud = 9600;
static const int SD_PIN_OUT = 10; // for sdcard
static const int chipSelect = 4; //for SD card
/** PIN - assignment for the SD Card Reader
 * MOSI - pin 11
 * MISO - pin 12
 * CLK - pin 13
 * CS - pin 4
 **/
/**PIN - reservation from wire.h for the gyro/acc
 * SLC - A5
 * SDA - A4
 **/


//Initialize variables for stuff

//Gps-related
TinyGPSPlus gps;
SoftwareSerial ss(GPSRXPin, GPSTXPin);

// SD-card related stuff
File logFile;


//general

long timeStamp;

void setup() {
  Serial.begin(115200);

  //SD-related stuff
  pinMode(SD_PIN_OUT, OUTPUT);

  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");

  //GPS-related stuff 
  ss.begin(GPSBaud);

  //set Time NOW
  timeStamp = millis();
}


void loop() {

  String dataString = "";


  //read timestamp, add to string
  dataString += String(millis());
  dataString += ",";
  //read from GPS, append to String
  dataString += getGPSdata();
  dataString += ",";

  //read from Accelerometer, append to string
  dataString += getAccelData();
  dataString += ",";
  //read from Gyroscope, append to string
  dataString += getGyroData();

  // open the file
  logFile = SD.open("datalog.txt", FILE_WRITE);
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

  //be a bastard
  smartDelay(100);
}

String getGPSdata() {
  String gpsData ="";

  //read the gpsData

  //return gpsData;
  //printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);
  //printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);
  //dtostrf(FLOAT,WIDTH,PRECSISION,BUFFER);
  String gpsData += dtostrf(gps.location.lat(), 8, 6, );
  return "GPS data OK";
}

String getGyroData() {
  String gyroData ="";

  //read the gyroData

  //return gyroData;
  return "Gyro data OK";
}

String getAccelData() {
  String accelData ="";

  //read the accelData

  //return accelData;
  return "Accelerometer data OK";
}

//Custom Delay - method for making sure the GPS - object doesn't time out
static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } 
  while (millis() - start < ms);
}


