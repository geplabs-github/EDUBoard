/*
  EDU Board - Thermometer tutorial
  Updated 30.7.2019
  Example of use of DS18b20 temperature sensor. 
  ---------------------------------------
  Updated By Jiří Povolný (www.geplabs.com)
*/

#include <OneWire.h>
#include <DallasTemperature.h>

//Constants
const long SERIAL_BAUD = 115200;
const byte DS = 8;
 
OneWire ourWire(DS);
DallasTemperature sensors(&ourWire);
  
void setup() {
  Serial.begin(SERIAL_BAUD);
  sensors.begin();
  delay(100);
}
 
void loop() {
  sensors.requestTemperatures();
  delay(2000);
  
  Serial.print("Temperature: ");
  Serial.println(sensors.getTempCByIndex(0));
}
