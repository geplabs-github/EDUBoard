/*
  EDU Board - RTC, hodiny reálného času
  Upraveno 30.10.2019
  Příklad použití RTS obvodu DS1399,
  RTC je na I2C rozhraní.
  ---------------------------------------
  Upravil Jiří Povolný (www.geplabs.com)
*/

// Vložení knihoven
#include <DSRTCLib.h>
#include <U8glib.h>

// Proměnné (variables)
String vstup;
String dt;
int rok, mes, den, hod, mnt, sek;

// Deklarace objektů
U8GLIB_SSD1306_128X64 mujDisplej(U8G_I2C_OPT_NONE);
DS1339 RTC = DS1339();

void setup() {                
  Serial.begin(115200);
  Serial.println("Startuji...");
  
  // Nastavení objektu RTC
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
  // a neodešleme. 
  // Také se zde opakované čtou údaje z RTC a zobrazují na displej.
  while(!Serial.available()){
    RTC.readTime();
    rok = RTC.getYears();
    mes = RTC.getMonths();
    den = RTC.getDays();
    hod = RTC.getHours();
    mnt = RTC.getMinutes();
    sek = RTC.getSeconds();
    
    mujDisplej.firstPage();  
    do {
      zobraz();
    } while(mujDisplej.nextPage());  
  }

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
} // loop

void zobraz() {
  // Nastavení fontu
  mujDisplej.setFont(u8g_font_unifont);
  // Nastavení pozice, odkud se bude zobrazovat
  mujDisplej.setPrintPos(25, 20); 

  mujDisplej.print(format2(String(den)));
  mujDisplej.print("/");  
  mujDisplej.print(format2(String(mes)));
  mujDisplej.print("/");  
  mujDisplej.print(rok);

  mujDisplej.setFont(u8g_font_fub20n);
  mujDisplej.setPrintPos(10, 55);
  mujDisplej.print(format2(String(hod)));
  mujDisplej.print(":");
  mujDisplej.print(format2(String(mnt)));
  mujDisplej.print(":");
  mujDisplej.print(format2(String(sek)));

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

    // Následující kód "rozebere řetězec znaků a přiřadí je do jednotlivých proměnných.
    rok = dt.substring(0,4).toInt();
    mes = dt.substring(4,6).toInt();
    den = dt.substring(6,8).toInt();
    hod = dt.substring(9,11).toInt();
    mnt = dt.substring(12,14).toInt();
    sek = dt.substring(15,17).toInt();

    // Zde se nastaví jednotlivé údaje do obvodu RTC
    RTC.setSeconds(sek);
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

String format2(String hodnota){
  if (hodnota.length() < 2){
    hodnota = "0" + hodnota;
  } 
  return(hodnota);  
}
