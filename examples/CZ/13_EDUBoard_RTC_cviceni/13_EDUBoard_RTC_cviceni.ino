/*
  EDU Board - RTC, hodiny reálného času
  Upraveno 30.10.2019
  Příklad použití RTS obvodu DS1399,
  RTC je na I2C rozhraní.
  ---------------------------------------
  Upravil Jiří Povolný (www.geplabs.com)
*/

#include <DSRTCLib.h>

// Proměnné (variables)
String vstup;
String dt;
int rok, mes, den, hod, mnt, sec;

// Nastavení objektu RTC
DS1339 RTC = DS1339();

void setup() {                
  Serial.begin(115200);
  Serial.println("Startuji...");
  // Spustí obsluhu RTC
  RTC.start(); 
  
  // Zkusí, jestli jsou hodiny nastaveny, pokud ne, vyzve k nastavení času
  if(!RTC.time_is_set()) {
    Serial.print("Hodiny nejsou nastaveny. ");
    nastavCas();
  }
  
  // Znovu zkusí, zda jsou hodiny nastaveny, pokud ne, skončí v nekonečné smyčce ( while(true) )
  if(!RTC.time_is_set()) {
    Serial.println("Hodiny se nepodařilo nastavit! EDUBoard je možná vadný.");
    while(true){}
  }
}

void loop() {
  // Vypíše na seriový port jednoduché menu
  Serial.println ("\nRTC menu \n 1) Cist cas \n 2) Nastavit cas \n");

  // V této smyčce se čeká, dokud se na sériovém portu 
  // něco nebjeví, tedy dokud na klávesnici něco nenapíšeme
  // a neodešleme
  while(!Serial.available()){}

  // Přečteme sériový port a zapíšeme do proměnné "vstup"
  vstup = Serial.readString();

  // Pokud je vstup "1", zavoláme funkci "ctiCas()"
  // Pokud je vstup "2", zavoláme funkci "nastavCas()"
  // Pokud je vstup něco jiného, vypíšeme chybu a skočíme zase na začátek
  if (vstup == "1") {
    ctiCas();
  }
  else if (vstup == "2") {
    nastavCas();
  }
  else {
    Serial.println("Spatna volba");
  }
}

void ctiCas() {
  Serial.print ("Aktualni cas je ");

  // Přečte čas z RTC obvodu a vypíše čas na sériový port ( ukazCas() )
  RTC.readTime(); 
  ukazCas();
  Serial.println();

}

void nastavCas() {
  Serial.println("Zadej datum a cas (RRRRMMDD HH:MM:SS)");

  // Opět čeká na vstup z klávesnice, tentokrát na zadání data a času
  while(!Serial.available()){}

  // Přečte ze sériového portu a pro kontrolu vypíše zpět
  dt = Serial.readString();
  Serial.println(dt);

  // Provede se jednoduchá kontrola na délku
  if(dt.length() == 17) {

    // Následují kód "rozebere" řetězec znaků a přiřadí je do jednotlivých proměnných.
    rok = dt.substring(0,4).toInt();
    mes = dt.substring(4,6).toInt();
    den = dt.substring(6,8).toInt();
    hod = dt.substring(9,11).toInt();
    mnt = dt.substring(12,14).toInt();
    sec = dt.substring(15,17).toInt();

    // Zde se nastaví jednotlivé údaje do obvodu RTC
    RTC.setSeconds(sec);
    RTC.setMinutes(mnt);
    RTC.setHours(hod);
    RTC.setDays(den);
    RTC.setMonths(mes);
    RTC.setYears(rok);
    RTC.writeTime();

    // Tady přečteme pro kontrolu datum a čas a vypíšeme na sériový port
    ctiCas();  
  }
  else {
    // Hlášení o zadání špatného datumu a času
    Serial.println("Spatny format.");
  }
}

void ukazCas() {
  // Postupně přečte a následně vypíše datum a čas z RTC na sériový port
  Serial.print(RTC.getDays());
  Serial.print("/");  
  Serial.print(RTC.getMonths());
  Serial.print("/");  
  Serial.print(RTC.getYears());
  
  Serial.print("  ");
  Serial.print(RTC.getHours());
  Serial.print(":");
  Serial.print(RTC.getMinutes());
  Serial.print(":");
  Serial.print(RTC.getSeconds());  
}
