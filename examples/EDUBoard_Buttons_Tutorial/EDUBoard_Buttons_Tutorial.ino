/*
  EDU Board - LED cvičení
  Upraveno 2.3.2018
  Upravil Jiří Povolný (www.geplabs.com)
 */

const int delayMS = 500;  // Čas prodlevy v ms.
const int ledPin1 = 4;     // Číslo pinu (vývodu), na kterém je LED dioda připojena.
const int ledPin2 = 5;     // Číslo pinu (vývodu), na kterém je LED dioda připojena.
const int ledPin3 = 6;     // Číslo pinu (vývodu), na kterém je LED dioda připojena.

const int buttPin1 = 14;     // Číslo pinu (vývodu), na kterém je LED dioda připojena.
const int buttPin2 = 15;     // Číslo pinu (vývodu), na kterém je LED dioda připojena.
const int buttPin3 = 16;     // Číslo pinu (vývodu), na kterém je LED dioda připojena.

// Funkce setup proběhne jednou po připojení desky
void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  // Nastavení digitalního pinu 9 jako výstup
  pinMode(buttPin1, INPUT);
  pinMode(buttPin2, INPUT);
  pinMode(buttPin3, INPUT);
}

// Funkce loop běží stále dokola, do skonání desky nebo světa.
void loop() {
  digitalWrite(ledPin1, digitalRead(buttPin1));
  digitalWrite(ledPin2, digitalRead(buttPin2));
  digitalWrite(ledPin3, digitalRead(buttPin3));
  
  /*
  digitalWrite(buttPin1, HIGH);   // Rozsvítí LED diodu (HIGH znamená logickou jedničku).
  digitalWrite(buttPin2, LOW);    // Zhasne LED diodu (LOW je logická nula).
  delay(delayMS);               // Počká po dobu DELAY_MS.
  digitalWrite(buttPin1, LOW);    // Zhasne LED diodu (LOW je logická nula).
  digitalWrite(buttPin2, HIGH);   // Rozsvítí LED diodu (HIGH znamená logickou jedničku).
  delay(delayMS);               // Počká po dobu DELAY_MS.
  digitalWrite(buttPin3, HIGH);    // Zhasne LED diodu (LOW je logická nula).
  delay(delayMS/5);  
  digitalWrite(buttPin3, LOW);   // Rozsvítí LED diodu (HIGH znamená logickou jedničku).
               // Počká po dobu DELAY_MS.

               */
}



