/*
  EDU Board - Oled displej
  Upraveno 30.10.2019
  Příklad použití OLED displeje přes I2C,
  ukázka grafiky, řadič SSD1306.
  ---------------------------------------
  Upravil Jiří Povolný (www.geplabs.com)
*/

// Vložení knihovny U8glib pro obsluhu displeje
#include <U8glib.h>

// Deklarace objektu displeje
U8GLIB_SSD1306_128X64 mujDisplej(U8G_I2C_OPT_NONE);

void setup(void) {
  
}

void loop(void) {
  mujDisplej.setFont(u8g_font_6x10);
  mujDisplej.setFontPosTop();

  // Vykreslí kruhy a kružnice
  mujDisplej.firstPage();  
  do {
    mujDisplej.drawStr( 0, 0, "Kruh");
    mujDisplej.drawDisc(10,18,9);
    mujDisplej.drawDisc(24,16,7);
    mujDisplej.drawStr( 0, 30, "Kruznice");
    mujDisplej.drawCircle(10,18+30,9);
    mujDisplej.drawCircle(24,16+30,7);
  } while(mujDisplej.nextPage());
  
  delay(2000);

  // Vykreslí obdélníky
  mujDisplej.firstPage();  
  do {
    mujDisplej.drawStr( 0, 0, "Obdelnik plny");
    mujDisplej.drawBox(5,10,20,10);
    mujDisplej.drawBox(10,15,30,7);
    mujDisplej.drawStr( 0, 30, "Obdelnik ramecek");
    mujDisplej.drawFrame(5,10+30,20,10);
    mujDisplej.drawFrame(10,15+30,30,7);
  } while(mujDisplej.nextPage());
  
  delay(2000);

  // Vykreslí čáry
  mujDisplej.firstPage();  
  do {
    mujDisplej.drawStr( 0, 0, "Linka");
    mujDisplej.drawLine(7, 10, 40, 55);
    mujDisplej.drawLine(7, 10, 60, 55);
    mujDisplej.drawLine(7, 10, 80, 55);
    mujDisplej.drawLine(7, 10, 100, 55);
  } while(mujDisplej.nextPage());
  
  delay(2000);

  // Vykreslí trojúhelník
  mujDisplej.firstPage();  
  do {
    mujDisplej.drawStr( 0, 0, "Trojuhelnik");
    mujDisplej.drawTriangle(24,7, 45,30, 20,40);
  } while(mujDisplej.nextPage());
  
  delay(2000);
}
