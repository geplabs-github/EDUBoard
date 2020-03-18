/*
  EDU Board - Photoresistor tutorial
  Updated 23.7.2019
  Reads analog value from input A7, 
  where a voltage divider with photoresistor is connected.
  ------------------------------------
  Updated By Jiří Povolný (www.geplabs.com)
*/

//Constants
const long SERIAL_BAUD = 115200;
const int  P_RES = A7;             //Photoresistor on A7 input

//Variables
int value;                         //The variable to store value from the input

void setup(){
 Serial.begin(SERIAL_BAUD);        //Serial port initialization
}

void loop(){
  Serial.print("Photoresistor: "); //Write the text "Photoresistor:" to the serial port
  value = analogRead(P_RES);       //Read value from A7
  Serial.println(value);           //Write the read value to the serial port
  delay(600);                      //Wait 600ms
}
