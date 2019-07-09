/*
  EDU Board - Tlačítka cvičení
  Upraveno 2.11.2018
  Přečte tlačítko a rozsvítí LED diodu
  ------------------------------------
  Upravil Jiří Povolný (www.geplabs.com)
 */

const int ledPin1 = 4;     // Číslo pinu (vývodu), na kterém je LED dioda připojena.
const int ledPin2 = 5;     // Číslo pinu (vývodu), na kterém je LED dioda připojena.
const int ledPin3 = 6;     // Číslo pinu (vývodu), na kterém je LED dioda připojena.

const int buttPin1 = 14;   // Číslo pinu (vývodu), na kterém je LED dioda připojena.
const int buttPin2 = 15;   // Číslo pinu (vývodu), na kterém je LED dioda připojena.
const int buttPin3 = 16;   // Číslo pinu (vývodu), na kterém je LED dioda připojena.

// Funkce setup proběhne jednou po připojení desky
void setup() {
  // Nastavení pinů, kde jsou připojeny LED diody, jako výstu
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  // Nastavení pinů, kde jsou připojena tlačítka, jako vstup
  pinMode(buttPin1, INPUT);
  pinMode(buttPin2, INPUT);
  pinMode(buttPin3, INPUT);
}

// Funkce loop běží stále dokola, do skonání desky nebo světa.
void loop() {
  // Funkce digitalRead() přečte, zda je stisknuto tlačítko. 
  // Pokud ano, výsledek funkce je logická jednička.
  // To se může hned použít jako parametr funkce digitalWrite(), 
  // která podle toho rozsvítí nebo zhasne LED diodu.
  digitalWrite(ledPin1, digitalRead(buttPin1));
  digitalWrite(ledPin2, digitalRead(buttPin2));
  digitalWrite(ledPin3, digitalRead(buttPin3));
  
}
