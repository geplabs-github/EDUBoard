/*
  EDU Board - Potenciometr cvičení
  Upraveno 2.2.2019
  Přečte analogovou hodnotu ze vstupu A6, 
  kde je připojen jezdec potenciometru.
  ------------------------------------
  Upravil Jiří Povolný (www.geplabs.com)
*/

//Konstanty (constants)
const long SERIAL_BAUD = 115200;
const int  P_POT = A6;            //Potenciometr na vstupu A6

//Proměnné (variables)
int value;                        //Proměnná pro uložení hodnoty ze vstupu

void setup(){
 Serial.begin(SERIAL_BAUD);       //Inicializace sériového portu
}

void loop(){
  Serial.print("Potenciometr: "); //Vypiš na sériový port text "Potenciometr: "
  value = analogRead(P_POT);      //Přečti hodnotu z A6
  Serial.println(value);          //Vypiš na sériový port přečtenou hodnotu
  delay(600);                     //Počkej 600ms
}
