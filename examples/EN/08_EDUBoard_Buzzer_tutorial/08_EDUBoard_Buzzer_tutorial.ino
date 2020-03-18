/*
  EDU Board - Buzzer tutorial 
  Updated 30.7.2019
  An example of using a buzzer, makes 
  a beeping noise at a frequency of 1000 Hz (1kHz).
  ---------------------------------------
  Updated By Jiří Povolný (www.geplabs.com)
*/

//Constants
const int BUZZ = 7;
const int DELAY_MS = 1000;
const int FREQ = 1000;

void setup() {
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  tone(BUZZ, FREQ);
  delay(DELAY_MS);
  noTone(BUZZ);
  delay(DELAY_MS);
}
