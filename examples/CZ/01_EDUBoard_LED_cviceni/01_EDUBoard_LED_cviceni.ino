/*
  EDU Board - LED cvičení
  Postupně roszvěcuje všechny LED diody na desce
  ----------------------------------------------
  Upraveno 2.11.2018
  Upravil Jiří Povolný (www.geplabs.com)
*/

//Konstanty (constants)
const int DELAY_MS = 500;      //Čas prodlevy v ms.
const int LPIN_1 = 4;          //Číslo pinu (vývodu), na kterém je LED dioda připojena.
const int LPIN_2 = 5;          //Číslo pinu (vývodu), na kterém je LED dioda připojena.
const int LPIN_3 = 6;          //Číslo pinu (vývodu), na kterém je LED dioda připojena.

//Funkce setup proběhne jednou po připojení desky
void setup() {
  pinMode(LPIN_1, OUTPUT);     //Nastavení digitalního pinu jako výstup.
  pinMode(LPIN_2, OUTPUT);     //Nastavení digitalního pinu jako výstup.
  pinMode(LPIN_3, OUTPUT);     //Nastavení digitalního pinu jako výstup.
}

//Funkce loop běží stále dokola, do skonání desky nebo světa.
void loop() {
  digitalWrite(LPIN_1, HIGH);  //Rozsvítí LED diodu (HIGH znamená logickou jedničku).
  delay(DELAY_MS);             //Počká po dobu delayMS.
  digitalWrite(LPIN_1, LOW);   //Zhasne LED diodu (LOW je logická nula).
  
  digitalWrite(LPIN_2, HIGH);  //Rozsvítí LED diodu (HIGH znamená logickou jedničku).
  delay(DELAY_MS);             //Počká po dobu delayMS.
  digitalWrite(LPIN_2, LOW);   //Zhasne LED diodu (LOW je logická nula).
  
  digitalWrite(LPIN_3, HIGH);  //Rozsvítí LED diodu (HIGH znamená logickou jedničku).
  delay(DELAY_MS);             //Počká po dobu delayMS.
  digitalWrite(LPIN_3, LOW);   //Zhasne LED diodu (LOW je logická nula).
  delay(DELAY_MS);             //Počká po dobu delayMS.
          
}
