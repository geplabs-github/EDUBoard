/*
  EDU Board - PWM cvičení
  Upraveno 30.7.2019
  Mění intenzitu světla LED diody, postup-
  ně ji plynule rozsvěcí a zhasíná.
  ----------------------------------------
  Upravil Jiří Povolný (www.geplabs.com)

*/

//Konstanty (constants)
const int LED_PIN = 6;       //Číslo pinu (vývodu), na kterém je LED dioda připojena.

//Proměnné (variables)
int cnt;                     //Proměnná pro uložení hodnoty v cyklu FOR

void setup() {
  pinMode(LED_PIN, OUTPUT);  //Nastavení pinu jako výstup.
}

void loop() {
  //Postupně rozsvěcí led
  for(cnt = 0; cnt <= 255; cnt++){
    analogWrite(LED_PIN, cnt);
    delay(5);
  }
  
  //Postupně zhasíná led
  for(cnt = 255; cnt >= 0; cnt--){
    analogWrite(LED_PIN, cnt);
    delay(5);
  }
}
