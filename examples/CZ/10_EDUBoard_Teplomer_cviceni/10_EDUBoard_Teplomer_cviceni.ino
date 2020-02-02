/*
  EDU Board - Teploměr cvičení 
  Upraveno 30.7.2019
  Příklad použití teplotního čidla DS18b20. 
  ---------------------------------------
  Upravil Jiří Povolný (www.geplabs.com)
*/

#include <OneWire.h>
#include <DallasTemperature.h>

//Konstanty (constants)
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
  
  Serial.print("Teplota: ");
  Serial.println(sensors.getTempCByIndex(0));
}
