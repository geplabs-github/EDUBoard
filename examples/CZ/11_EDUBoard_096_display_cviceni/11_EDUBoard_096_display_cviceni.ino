/*
  EDU Board - Oled displej
  Upraveno 30.10.2019
  Příklad použití OLED displeje přes I2C,
  vypsání textu, řadič SSD1306.
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
  // Tzv. picture loop
  mujDisplej.firstPage();  
  do {
    // Nastavení fontu
    mujDisplej.setFont(u8g_font_unifont);
    // Vypsání textu na pozici 0,40
    mujDisplej.drawStr(0, 40, "Muj prvni text!");
  } while(mujDisplej.nextPage());
  
  delay(500);
}
