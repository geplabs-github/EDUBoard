/*
  EDU Board - RTC, real time clock tutorial
  Updated 30.10.2019
  Example of using RTS circuit DS1399, RTC is on I2C interface.
  ---------------------------------------
  Updated By Jiří Povolný (www.geplabs.com)
*/

// Include library
#include <DSRTCLib.h>

// Variables
String inputStr;
String dt;
int year, month, day, hour, mnt, sec;

// RTC object setting
DS1339 RTC = DS1339();

void setup() {                
  Serial.begin(115200);
  Serial.println("Starting...");
  // Starting RTC
  RTC.start(); 
  
  // Check if the clock is set, if not, prompt to set the time
  if(!RTC.time_is_set()) {
    Serial.print("The clock is not set. ");
    setTime();
  }
  
  // Retry whether the clock is set, if not, end in an infinite loop (while (true))
  if(!RTC.time_is_set()) {
    Serial.println("Failed to set clock! EDUBoard may be defective.");
    while(true){}
  }
}

void loop() {
  // Print a simple menu to the serial port
  Serial.println ("\nRTC menu \n 1) Read time \n 2) Set time \n");

  // This loop waits until something appears on the serial port
  // it means until you type something on the keyboard and press return
  while(!Serial.available()){}

  // Read serial port and write to variable "inputStr"
  inputStr = Serial.readString();

  // If the input is "1", we call the function "readTime()"
  // If the input is "2", we call the function "setTime()"
  // If the input is something else, we write the error and jump back to the beginning
  if (inputStr == "1") {
    readTime();
  }
  else if (inputStr == "2") {
    setTime();
  }
  else {
    Serial.println("Bad choice");
  }
}

void readTime() {
  Serial.print ("The current time is ");

  // Reads the time from the RTC and writes the time to the serial port ( printTime() )
  RTC.readTime(); 
  printTime();
  Serial.println();

}

void setTime() {
  Serial.println("Enter date and time (YYYYMMDD HH:MM:SS)");

  // It waits for keyboard input
  while(!Serial.available()){}

  // Reads from serial port and writes back for checking
  dt = Serial.readString();
  Serial.println(dt);

  // A simple length check is performed
  if(dt.length() == 17) {

    // The following code parse a string of characters and assigns them to each variable.
    year = dt.substring(0,4).toInt();
    month = dt.substring(4,6).toInt();
    day = dt.substring(6,8).toInt();
    hour = dt.substring(9,11).toInt();
    mnt = dt.substring(12,14).toInt();
    sec = dt.substring(15,17).toInt();

    // Set data to the RTC
    RTC.setSeconds(sec);
    RTC.setMinutes(mnt);
    RTC.setHours(hour);
    RTC.setDays(day);
    RTC.setMonths(month);
    RTC.setYears(year);
    RTC.writeTime();

    // Read the date and time for checking and write to the serial port
    readTime();  
  }
  else {
    // Report of wrong date and time
    Serial.println("Bad format.");
  }
}

void printTime() {
  // Sequentially reads and then prints the date and time from the RTC to the serial port
  Serial.print(RTC.getDays());
  Serial.print("/");  
  Serial.print(RTC.getMonths());
  Serial.print("/");  
  Serial.print(RTC.getYears());
  
  Serial.print("  ");
  Serial.print(RTC.getHours());
  Serial.print(":");
  Serial.print(RTC.getMinutes());
  Serial.print(":");
  Serial.print(RTC.getSeconds());  
}
