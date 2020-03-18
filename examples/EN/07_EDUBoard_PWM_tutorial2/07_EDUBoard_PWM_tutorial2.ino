/*
  EDU Board - PWM tutorial 2
  Updated 30.7.2019
  It changes the light intensity of the LEDs, 
  for LED on output 5 according to the potentiometer, 
  for LED on output 6 according to the photoresistor.
  ---------------------------------------
  Updated By Jiří Povolný (www.geplabs.com)

*/

//Constants
const int P_POT = A6;       //Potentiometer on the A6 input
const int P_RES = A7;       //Photoresistor on the A7 input

const int LPIN_1 = 5;       //Pin number where LED is connected
const int LPIN_2 = 6;       //Pin number where LED is connected

//Variables
int value01;                //Variable to store the value from potentiometer
int value02;                //Variable to store the value from the photoresistor

void setup() {
  ////Set pins as output
  pinMode(LPIN_1, OUTPUT);
  pinMode(LPIN_2, OUTPUT);
}

void loop() {
  //Read the values from the potentiometer and the photoresistor
  value01 = analogRead(P_POT);
  value02 = analogRead(P_RES);

  //We write the value to the outputs divided by four
  analogWrite(LPIN_1, value01 / 4);
  analogWrite(LPIN_2, 255 - (value02 / 4));

  delay(2);
}
