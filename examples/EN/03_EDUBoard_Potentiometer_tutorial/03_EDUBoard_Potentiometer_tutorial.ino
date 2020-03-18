/*
  EDU Board - Potentiometer tutorial
  Updated 2.2.2019
  Reads analog value from the input A6,
  where the slider of the potentiometer is connected.
  ------------------------------------
  Updated By Jiří Povolný (www.geplabs.com)
*/

//Constants
const long SERIAL_BAUD = 115200;
const int  P_POT = A6;             //Potentiometer on the input A6 (analog input)

//Variables
int value;                         //The variable to store value from the input

void setup(){
  Serial.begin(SERIAL_BAUD);       //Serial port initialization
}

void loop(){
  Serial.print("Potentiometer: "); //Write the text "Potentiometer:" to the serial port
  value = analogRead(P_POT);       //Read the value from A6
  Serial.println(value);           //Write the read value to the serial port
  delay(600);                      //Wait 600ms
}
