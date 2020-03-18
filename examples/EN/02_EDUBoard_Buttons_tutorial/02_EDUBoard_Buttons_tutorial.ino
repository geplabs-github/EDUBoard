/*
  EDU Board - Buttons tutorial
  Updated 2.11.2018
  Reads if the button is pressed and lights the LED
  ------------------------------------
  Updated By Jiří Povolný (www.geplabs.com)
*/

//Constants
const int LPIN_1 = 4;     //Pin number where LED 1 is connected.
const int LPIN_2 = 5;     //Pin number where LED 2 is connected.
const int LPIN_3 = 6;     //Pin number where LED 3 is connected.

const int BUTT_1 = 14;    //Pin number where button 1 is connected.
const int BUTT_2 = 15;    //Pin number where button 2 is connected.
const int BUTT_3 = 16;    //Pin number where button 3 is connected.

//Function setup() runs once after the board is connected.
void setup() {
  //Setting the pins where LEDs are connected as output.
  pinMode(LPIN_1, OUTPUT);
  pinMode(LPIN_2, OUTPUT);
  pinMode(LPIN_3, OUTPUT);
  //Setting the pins where buttons are connected as input.
  pinMode(BUTT_1, INPUT);
  pinMode(BUTT_2, INPUT);
  pinMode(BUTT_3, INPUT);
}

//The loop() function continues to run until the end of the board or the world.
void loop() {
  //Function digitalRead() reads whether a button is pressed.
  //If so, the result is a logical one.
  //This can be used immediately as a parameter of the digitalWrite () function,
  //which turns the LED on or off accordingly.
  digitalWrite(LPIN_1, digitalRead(BUTT_1));
  digitalWrite(LPIN_2, digitalRead(BUTT_2));
  digitalWrite(LPIN_3, digitalRead(BUTT_3));
}
