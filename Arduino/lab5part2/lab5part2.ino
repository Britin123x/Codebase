#include <LiquidCrystal.h>

LiquidCrystal LcdDriver ( A5, A4, 5, 6, 7, 8 );

int count;
int count2;
unsigned long timer;
unsigned long stopWatch;

void setup() 
{
  LcdDriver.begin( 16 , 2 );
  LcdDriver.clear();
  count = 0;
  count2 = 0;
  timer = millis();
  stopWatch = millis();
}

void loop() {
  if ( millis() - stopWatch >= 100)
  {
    if ( digitalRead ( 4 ) == HIGH)
    {
      count2 = 0;
      stopWatch += 100;
    }
    else
    {
      LcdDriver.clear();
      LcdDriver.setCursor( 0, 0 );
      LcdDriver.print( count );
      LcdDriver.setCursor ( 0 , 1);
      LcdDriver.print ( count2 );
      stopWatch += 100;
      count2++;

    }
  }
  if ( millis() - timer >= 1000)
    {
      timer += 1000;
      LcdDriver.setCursor( 0, 0 );
      LcdDriver.print( count );
      count++;
    }


}
