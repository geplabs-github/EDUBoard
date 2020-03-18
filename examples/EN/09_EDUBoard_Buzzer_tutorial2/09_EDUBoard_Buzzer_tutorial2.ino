/*
  EDU Board - Buzzer tutorial 2 
  Updated 30.7.2019
  Example of buzzer usage.
  Press button 1 to sound the siren.
  ---------------------------------------
  Updated By Jiří Povolný (www.geplabs.com)
*/

//Constants
const int BUZZ = 7;
const int BUTT = 14;     //Pin number where button 1 is connected.

//Variables
bool isButton = false;   //The variable to store value from the input

void setup() {
  //Setting pins to input or output according to usage
  pinMode(BUZZ, OUTPUT);
  pinMode(BUTT, INPUT);
}

void loop() {
  isButton = digitalRead(BUTT);

  if(isButton) {
    for (int i = 100; i < 3000; i++) {
      tone(BUZZ, i, 50);
    }
  }
}
