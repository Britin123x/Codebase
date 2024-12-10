char alpha = 'A' ; 
char number = '0' ;
unsigned long timer;

void setup() 
{
  Serial.begin( 38400 );
  timer = millis();
}

void loop() 
{
  if (millis() - timer >= 500) 
  {
    Serial.print( alpha );
    Serial.println( number );
    alpha++;
    number++;
    timer = timer + 500;
  }

  if (alpha > 'Z')
    {
      alpha = 'A';
    }

    if (number > '9' )
    {
      number = '0' ;
    }

  if (Serial.available())
  {
    if (Serial.read() == 'R')
    {
      alpha = 'A' , number = '0' ;
    }
  } 
}
