/*
  EDU Board - Tlačítka cvičení
  Upraveno 2.11.2018
  Přečte tlačítko a rozsvítí LED diodu
  ------------------------------------
  Upravil Jiří Povolný (www.geplabs.com)
*/

//Konstanty (constants)
const int LPIN_1 = 4;     //Číslo pinu (vývodu), na kterém je LED 1 dioda připojena.
const int LPIN_2 = 5;     //Číslo pinu (vývodu), na kterém je LED 2 dioda připojena.
const int LPIN_3 = 6;     //Číslo pinu (vývodu), na kterém je LED 3 dioda připojena.

const int BUTT_1 = 14;    //Číslo pinu (vývodu), na kterém je tlačítko 1 připojeno.
const int BUTT_2 = 15;    //Číslo pinu (vývodu), na kterém je tlačítko 2 připojeno.
const int BUTT_3 = 16;    //Číslo pinu (vývodu), na kterém je tlačítko 3 připojeno.

//Funkce setup proběhne jednou po připojení desky
void setup() {
  //Nastavení pinů, kde jsou připojeny LED diody, jako výstup
  pinMode(LPIN_1, OUTPUT);
  pinMode(LPIN_2, OUTPUT);
  pinMode(LPIN_3, OUTPUT);
  //Nastavení pinů, kde jsou připojena tlačítka, jako vstup
  pinMode(BUTT_1, INPUT);
  pinMode(BUTT_2, INPUT);
  pinMode(BUTT_3, INPUT);
}

//Funkce loop běží stále dokola, do skonání desky nebo světa.
void loop() {
  //Funkce digitalRead() přečte, zda je stisknuto tlačítko. 
  //Pokud ano, výsledek funkce je logická jednička.
  //To se může hned použít jako parametr funkce digitalWrite(), 
  //která podle toho rozsvítí nebo zhasne LED diodu.
  digitalWrite(LPIN_1, digitalRead(BUTT_1));
  digitalWrite(LPIN_2, digitalRead(BUTT_2));
  digitalWrite(LPIN_3, digitalRead(BUTT_3));
}
