/******************************************************************************
AlphaNumeric_Serial.ino
Serial control of Alphanumeric Drivers with the AlphaNumeric Driver Library
Jim Lindblom @ SparkFun Electronics
Original Creation Date: Nov 30, 2010
Edit Date: March 25, 2014
https://github.com/sparkfun/Serial_Alphanumeric_Display_Driver

After uploading this code, open up the serial monitor (9600 bps). Characters 
you send to the Arduino, over serial, will be displayed on the alphanumeric
displays.

Before uploading, make sure you set the NUMBER_OF_DISPLAYS variable at the
top. You may also wish to un-comment out FLIPDISPLAY, if your displays are
upside-down.

Development environment specifics:
	IDE: Arduino 1.0.5
	Hardware Platform: SparkFun Redboard

Hardware hookup:
	AlphaNumeric Display Driver -----------	Arduino
			SDI ----------------------------- 11
			CLK ----------------------------- 13
			LE ------------------------------ 10
			OE ------------------------------  9
			GND ----------------------------- GND
			VCC ----------------------------- VIN (or 5V)

This code is beerware; if you see me (or any other SparkFun employee) at the
local, and you've found our code helpful, please buy us a round!

Distributed as-is; no warranty is given.
******************************************************************************/

//#define FLIPDISPLAY  // Un-comment this out if you want the characters flipped 180 degrees

#include <AlphaNumeric_Driver.h>  // Include AlphaNumeric Display Driver Library
#define NUMBER_OF_DISPLAYS 4  // This value is currently only used by the library for the clear() command.

// --------- Pin Definitions -----------
int SDIpin = 11;
int CLKpin = 13;
int LEpin = 10;
int OEpin = 9;
// -------------------------------------

alphaNumeric myDisplay(SDIpin, CLKpin, LEpin, OEpin, NUMBER_OF_DISPLAYS);  // Create an instance of Alpha Numeric Displays

char displayString[] = "I'm now displaying a defined array of characters ";  // Static string to scroll on displays

void setup()
{
  Serial.begin(9600);
  /* This was for testing purposes
  myDisplay.scroll("####################", 0);
  Serial.println("All set");*/
}

void loop()
{
  // --------------------------
  // Begin Serial Print Example
  // --------------------------
  while(!Serial.available())
    ;
  myDisplay.print(Serial.read());
  // --------------------------
  // End Serial Print Example
  // --------------------------
  
  // --------------------------
  // Begin Scroll/On/Off/Clear Example
  // --------------------------
  /*myDisplay.scroll("Hello World ", 100);
  delay(1000);
  myDisplay.off();
  delay(1000);
  myDisplay.on();
  delay(1000);
  myDisplay.clear();
  delay(1000);
  myDisplay.scroll(displayString, 500);
  delay(1000);*/
  // --------------------------
  // End Scroll/On/Off/Clear Example
  // --------------------------
}
