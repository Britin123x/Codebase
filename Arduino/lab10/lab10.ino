#define STATE_IDLE 0
#define STATE_WAIT 1
#define STATE_LOW 2
int state = STATE_IDLE;
unsigned long timer;
void setup()
  {
  DDRD &= 0xEF; // pinMode( 4, INPUT );
  Serial.begin( 9600 );
  pinMode(LED_BUILTIN, OUTPUT);
  }
void loop()
  {
    switch (state)
    {
      case STATE_IDLE : if( (PIND & 0x10) == LOW ) // if( digitalRead( 4 ) == LOW )
      {
            state = STATE_WAIT;
            timer = millis();
      }
      break;
      case STATE_WAIT : if( (PIND & 0x10) != LOW) // if( digitalRead( 4 ) == HIGH )
      {
            state = STATE_IDLE;
      }
      else
      {
            if( millis() - timer > 5 )
            {
            state = STATE_LOW;
            Serial.println( "Pressed" );
            digitalWrite( LED_BUILTIN, HIGH );
            }
      }
      break;
      case STATE_LOW : if( (PIND & 0x10) != LOW ) // if( digitalRead( 4 ) == HIGH )
      {
            state = STATE_IDLE;
            Serial.println( "Released" );
            digitalWrite( LED_BUILTIN, LOW );
      }
break;
      default : state = STATE_IDLE;
    }
}