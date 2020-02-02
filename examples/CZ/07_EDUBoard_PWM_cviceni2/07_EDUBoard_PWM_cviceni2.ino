/*
  EDU Board - PWM cvičení 2
  Upraveno 30.7.2019
  Mění intenzitu světla LED diod, u LED
  na výstupu 5 podle potencimetru,
  u LED na výstupu 6 podle fotorezistoru.
  ---------------------------------------
  Upravil Jiří Povolný (www.geplabs.com)

*/

//Konstanty (constants)
const int P_POT = A6;       //Potenciometr na vstupu A6
const int P_RES = A7;       //Fotorezistor na vstupu A7

const int LPIN_1 = 5;       //Číslo pinu (vývodu), na kterém je LED dioda připojena.
const int LPIN_2 = 6;       //Číslo pinu (vývodu), na kterém je LED dioda připojena.

//Proměnné (variables)
int value01;                //Proměnná pro uložení hodnoty z potenciometru
int value02;                //Proměnná pro uložení hodnoty z fotorezistoru

void setup() {
  // Nastavení digitalních pinů jako výstup.
  pinMode(LPIN_1, OUTPUT);
  pinMode(LPIN_2, OUTPUT);
}

void loop() {
  //Přečteme hodnoty z potenciometru a fotorezistoru
  value01 = analogRead(P_POT);
  value02 = analogRead(P_RES);

  //Zapíšeme na výstup hodnotu vydělenou čtyřmi
  analogWrite(LPIN_1, value01 / 4);
  analogWrite(LPIN_2, 255 - (value02 / 4));

  delay(2);
}
