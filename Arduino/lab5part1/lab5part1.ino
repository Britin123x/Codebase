#include <LiquidCrystal.h>

LiquidCrystal LcdDriver ( A5, A4, 5, 6, 7, 8 );

int count;
unsigned long timer;

void setup() 
{
  LcdDriver.begin( 16 , 2 );
  LcdDriver.clear();
  count = 0;
  timer = millis();
}

void loop() {
  if ( millis() - timer >= 1000)
  {
    timer += 1000;
    LcdDriver.setCursor( 0 , 0);
    LcdDriver.print( count );
    count++;
  }

}
