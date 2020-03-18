/*
  EDU Board - OLED display
  Updated 30.10.2019
  Example of using OLED display via I2C interface, graphic example, SSD1306 controller.
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
  myOLED.setFont(u8g_font_6x10);
  myOLED.setFontPosTop();

  // Draws circles
  myOLED.firstPage();  
  do {
    myOLED.drawStr( 0, 0, "Filled circle");
    myOLED.drawDisc(10,18,9);
    myOLED.drawDisc(24,16,7);
    myOLED.drawStr( 0, 30, "Empty circle");
    myOLED.drawCircle(10,18+30,9);
    myOLED.drawCircle(24,16+30,7);
  } while(myOLED.nextPage());
  
  delay(2000);

  // Draws rectangles
  myOLED.firstPage();  
  do {
    myOLED.drawStr( 0, 0, "Filled rectangle");
    myOLED.drawBox(5,10,20,10);
    myOLED.drawBox(10,15,30,7);
    myOLED.drawStr( 0, 30, "Empty rectangle");
    myOLED.drawFrame(5,10+30,20,10);
    myOLED.drawFrame(10,15+30,30,7);
  } while(myOLED.nextPage());
  
  delay(2000);

  // Draws lines
  myOLED.firstPage();  
  do {
    myOLED.drawStr( 0, 0, "Lines");
    myOLED.drawLine(7, 10, 40, 55);
    myOLED.drawLine(7, 10, 60, 55);
    myOLED.drawLine(7, 10, 80, 55);
    myOLED.drawLine(7, 10, 100, 55);
  } while(myOLED.nextPage());
  
  delay(2000);

  // Draws a triangle
  myOLED.firstPage();  
  do {
    myOLED.drawStr( 0, 0, "Triangle");
    myOLED.drawTriangle(24,7, 45,30, 20,40);
  } while(myOLED.nextPage());
  
  delay(2000);
}
