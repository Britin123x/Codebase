#define STATE_IDLE 0
#define STATE_WAIT 1
#define STATE_LOW 2
#include <LiquidCrystal.h>
LiquidCrystal LcdDriver ( A5, A4, 5, 6, 7, 8 );

int state = STATE_IDLE;
unsigned long debounceTimer;
unsigned long counter;
int counterToggle;
unsigned long stopWatch;

void setup()
{
  DDRD &= 0xEF; // pinMode( 4, INPUT );
  counter = 0;
  counterToggle = -1;
  stopWatch = millis();
  Serial.begin( 9600 );
  pinMode(LED_BUILTIN, OUTPUT);
  LcdDriver.begin( 16 , 2 );
  LcdDriver.clear();
  LcdDriver.setCursor( 0 , 0);
  LcdDriver.print( "Welcome" );
  delay(1500);
  LcdDriver.clear();
  LcdDriver.print( counter );
}


void loop() 
{
  switch (state) //switch de-bouncer, the program is looking for STATE_LOW to read as ON
  {
    case STATE_IDLE : if( (PIND & 0x10) == LOW ) // if( digitalRead( 4 ) == LOW )
    {
      state = STATE_WAIT;
      debounceTimer = millis();
    }
    
    break;
    
    case STATE_WAIT : if( (PIND & 0x10) != LOW) // if( digitalRead( 4 ) == HIGH )
    {
      state = STATE_IDLE;
    }
    else
    {
      if( millis() - debounceTimer > 5 )
      {
        state = STATE_LOW;
        Serial.println( "Pressed" );
        stopWatch = millis();

        if (counterToggle == 1)
        {
          counterToggle = -1;
        }
        else 
        {
          counterToggle = 1;
        }
      }
    }
    
    break;

    case STATE_LOW : 
    
    if( (PIND & 0x10) != LOW ) // if( digitalRead( 4 ) == HIGH )
    {
      state = STATE_IDLE;
      Serial.println( "Released" );

    }

    if( millis() - stopWatch >= 50 )
    {
      if (counter >= 1 && counterToggle == -1) // countdown stopping underflow
        {
        counter = counter + counterToggle;
        stopWatch += 50;
        LcdDriver.clear();
        LcdDriver.setCursor( 0, 0);
        LcdDriver.print( counter );
        }
      else if (counterToggle == 1) // count up
        {
        counter = counter + counterToggle;
        stopWatch += 50;
        LcdDriver.clear();
        LcdDriver.setCursor( 0 , 0 );
        LcdDriver.print( counter );
        }
    }

    break;
    
    default : state = STATE_IDLE;
  }

  if (Serial.available())
  {
    if (Serial.read() == 'R')
    {
      counter = 0;
      counterToggle = 1;
      stopWatch = millis();
      LcdDriver.clear();
      LcdDriver.setCursor( 0 , 0);
      LcdDriver.print( "Welcome" );
      delay(1500);
      LcdDriver.clear();
      LcdDriver.print( counter );
      counterToggle = -1;
      state = STATE_IDLE;
    }
  } 

}