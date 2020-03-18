/*
  EDU Board - OLED display tutorial
  Updated 30.10.2019
  Example of using OLED display via I2C interface, writing text, SSD1306 controller.
  ---------------------------------------
  Updated By Jiří Povolný (www.geplabs.com)
*/

// Inserting the U8glib library for display handling
#include <U8glib.h>

// Declaration of the display object
U8GLIB_SSD1306_128X64 myOLED(U8G_I2C_OPT_NONE);

void setup(void) {
  
}

void loop(void) {
  // Picture loop
  myOLED.firstPage();  
  do {
    // Font settings
    myOLED.setFont(u8g_font_unifont);
    // Write text to position 0,40
    myOLED.drawStr(0, 40, "Hello world!");
  } while(myOLED.nextPage());
  
  delay(500);
}
