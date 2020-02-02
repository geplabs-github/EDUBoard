/*
  EDU Board - Buzzer cvičení 
  Upraveno 30.7.2019
  Příklad použití buzzeru, vydává přeru-
  šovaný tón o frekvenci 1000Hz (1kHz).
  ---------------------------------------
  Upravil Jiří Povolný (www.geplabs.com)
*/

//Konstanty (constants)
const int BUZZ = 7;
const int DOBA = 1000;
const int FREQ = 1000;

void setup() {
  pinMode(BUZZ, OUTPUT);
}

void loop() {
  tone(BUZZ, FREQ);
  delay(DOBA);
  noTone(BUZZ);
  delay(DOBA);
}
