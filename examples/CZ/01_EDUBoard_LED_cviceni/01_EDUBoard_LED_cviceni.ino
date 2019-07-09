/*
  EDU Board - LED cvičení
  Postupně roszvěcuje všechny LED diody na desce
  ----------------------------------------------
  Upraveno 2.11.2018
  Upravil Jiří Povolný (www.geplabs.com)
 */

const int delayMS = 500;  // Čas prodlevy v ms.
const int ledPin1 = 4;     // Číslo pinu (vývodu), na kterém je LED dioda připojena.
const int ledPin2 = 5;     // Číslo pinu (vývodu), na kterém je LED dioda připojena.
const int ledPin3 = 6;     // Číslo pinu (vývodu), na kterém je LED dioda připojena.

// Funkce setup proběhne jednou po připojení desky
void setup() {
  // Nastavení digitalního pinu 9 jako výstuo.
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

// Funkce loop běží stále dokola, do skonání desky nebo světa.
void loop() {
  digitalWrite(ledPin1, HIGH);  // Rozsvítí LED diodu (HIGH znamená logickou jedničku).
  delay(delayMS);               // Počká po dobu DELAY_MS.
  digitalWrite(ledPin1, LOW);   // Zhasne LED diodu (LOW je logická nula).
  
  digitalWrite(ledPin2, HIGH);  // Rozsvítí LED diodu (HIGH znamená logickou jedničku).
  delay(delayMS);               // Počká po dobu DELAY_MS.
  digitalWrite(ledPin2, LOW);   // Zhasne LED diodu (LOW je logická nula).
  
  digitalWrite(ledPin3, HIGH);  // Rozsvítí LED diodu (HIGH znamená logickou jedničku).
  delay(delayMS);               // Počká po dobu DELAY_MS.
  digitalWrite(ledPin3, LOW);   // Zhasne LED diodu (LOW je logická nula).
  delay(delayMS);               // Počká po dobu DELAY_MS.
              
}
