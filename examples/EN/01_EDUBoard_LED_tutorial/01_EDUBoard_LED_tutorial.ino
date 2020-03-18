/*
  EDU Board - LED tutorial
  It sequentially lights up all the LEDs on the board.
  ----------------------------------------------
  Updated 2.11.2018
  Updated By Jiří Povolný (www.geplabs.com)
*/

//Constants
const int DELAY_MS = 500;      //Dwell time in ms.
const int LPIN_1 = 4;          //Pin number where LED 1 is connected.
const int LPIN_2 = 5;          //Pin number where LED 2 is connected.
const int LPIN_3 = 6;          //Pin number where LED 3 is connected.

//Function setup() runs once after the board is connected.
void setup() {
  pinMode(LPIN_1, OUTPUT);     //Setting the digital pin as output.
  pinMode(LPIN_2, OUTPUT);     //Setting the digital pin as output.
  pinMode(LPIN_3, OUTPUT);     //Setting the digital pin as output.
}

//The loop() function continues to run until the end of the board or the world.
void loop() {
  digitalWrite(LPIN_1, HIGH);  //Turns on the LED (HIGH means logical one).
  delay(DELAY_MS);             //Waits for delayMS.
  digitalWrite(LPIN_1, LOW);   //The LED goes off (LOW is logic zero).
  
  digitalWrite(LPIN_2, HIGH);  //Turns on the LED (HIGH means logical one).
  delay(DELAY_MS);             //Waits for delayMS.
  digitalWrite(LPIN_2, LOW);   //The LED goes off (LOW is logic zero).
  
  digitalWrite(LPIN_3, HIGH);  //Turns on the LED (HIGH means logical one).
  delay(DELAY_MS);             //Waits for delayMS.
  digitalWrite(LPIN_3, LOW);   //The LED goes off (LOW is logic zero).
  delay(DELAY_MS);             //Waits for delayMS.
          
}
