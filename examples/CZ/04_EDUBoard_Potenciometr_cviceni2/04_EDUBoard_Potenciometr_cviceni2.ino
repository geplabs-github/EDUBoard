/*
  EDU Board - Potenciometr cvičení
  Upraveno 22.8.2019
  Přečte analogovou hodnotu ze vstupu A6, 
  kde je připojen jezdec potenciometru 
  a rozsvítí LED diodu podle výchylky.
  ------------------------------------
  Upravil Jiří Povolný (www.geplabs.com)
*/

//Konstanty (constants)
const int P_POT = A6;        //Potenciometr na vstupu A6

const int LPIN_1 = 4;       
const int LPIN_2 = 5;       
const int LPIN_3 = 6;

//Proměnné (variables)
int value;                  //Proměnná pro uložení hodnoty ze vstupu

void setup(){
  //Nastavení pinů, kde jsou připojeny LED diody, jako výstup
  pinMode(LPIN_1, OUTPUT);  
  pinMode(LPIN_2, OUTPUT);  
  pinMode(LPIN_3, OUTPUT);  
}

void loop(){
  value = analogRead(P_POT);       //Přečti hodnotu z A6

  //Pokud je hodnota menší než 300, rozsviť LED 1, ostatní zhasni
  if (value < 300){                
    digitalWrite(LPIN_1, HIGH);  
    digitalWrite(LPIN_2, LOW);
    digitalWrite(LPIN_3, LOW);
  }
  //Pokud je hodnota mezi 300 a 700, rozsviť LED 2, ostatní zhasni
  else if(value <= 700 && value >= 300) {
    digitalWrite(LPIN_1, LOW);  
    digitalWrite(LPIN_2, HIGH);
    digitalWrite(LPIN_3, LOW);
  }
  //Pokud je hodnota větší než 700, rozsviť LED 3, ostatní zhasni
  else if(value > 700) {
    digitalWrite(LPIN_1, LOW);  
    digitalWrite(LPIN_2, LOW);
    digitalWrite(LPIN_3, HIGH);
  }

  delay(100);                     //Počkej 100ms
}
