/*
  EDU Board - Fotorezistor cvičení
  Upraveno 23.7.2019
  Přečte analogovou hodnotu ze vstupu A7, 
  kde je připojen odporový dělič s fotorezistorem.
  ------------------------------------
  Upravil Jiří Povolný (www.geplabs.com)
*/

//Konstanty (constants)
const long SERIAL_BAUD = 115200;
const int  P_RES = A7;             //Fotorezistor na vstupu A7

//Proměnné (variables)
int value;                         //Proměnná pro uložení hodnoty ze vstupu

void setup(){
 Serial.begin(SERIAL_BAUD);        //Inicializace sériového portu
}

void loop(){
  Serial.print("Fotorezistor: ");  //Vypiš na sériový port text "Fotorezistor: "
  value = analogRead(P_RES);       //Přečti hodnotu z A7
  Serial.println(value);           //Vypiš na sériový port přečtenou hodnotu
  delay(600);                      //Počkej 600ms
}
