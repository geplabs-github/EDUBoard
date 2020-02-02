/*
  EDU Board - Buzzer cvičení 
  Upraveno 30.7.2019
  Příklad použití buzzeru. 
  Stiskem tlačítka 1 se spustí siréna.
  ---------------------------------------
  Upravil Jiří Povolný (www.geplabs.com)
*/

//Konstanty (constants)
const int BUZZ = 7;
const int BUTT = 14;     //Číslo pinu (vývodu), na kterém je tlačítko 1 připojeno.

//Proměnné (variables)
bool jeTlacitko = false; //Proměnná, kde je uloženo, zda má siréna houkat.

void setup() {
  //Nastavení pinů na vstup nebo výstup podle použití
  pinMode(BUZZ, OUTPUT);
  pinMode(BUTT, INPUT);
}

void loop() {
  jeTlacitko = digitalRead(BUTT);

  if(jeTlacitko) {
    for (int i = 100; i < 3000; i++) {
      tone(BUZZ, i, 50);
    }
  }
}
