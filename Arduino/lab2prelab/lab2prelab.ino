unsigned long ledTimer; // Sets a variable for the millis() function, which outputs an unsigned long.
unsigned long ledTimer2; // Variable for 3 second timer.
int onTime1 = 5;
int onTime2 = 10;
// Setup is only ran once and, as the name implies, sets up functions and variables for later.
void setup()
{ 
  pinMode( 13, OUTPUT ); // Assigns pin 13 as an output pin for the light, which means when written to will output a light.
  pinMode(12, OUTPUT); // Established pin 12 as an output for the three second blink
  ledTimer = millis(); // Assigning the millis function to the variable ledTimer, so when it is called it will give how long this code has been running in milliseconds.
  ledTimer2 = millis(); // Three second timer initial variable

} // This setup made our blinking light an output so it will flash, and setup our timer to start running
// The loop function will continuously run forever until the Arduino is turned off.
void loop()
{ 
  if( millis() - ledTimer >= onTime2 )
  { // This function checks if the time since the function has started and now is larger than 1000 ms, or one second.
    if( digitalRead( 13 ) == HIGH )
    { // If the light its on, then it needs to be turned off.
      digitalWrite( 13, LOW ); // This turns the light off.
      
    }
    else
      { // Otherwise, if the light is off when the time has passed, this happens.
      digitalWrite( 13, HIGH );
      } // This function will make sure that whatever the state of the light was, if the correct time 
    ledTimer += onTime2; // This pushes the ledTimer variable forward 1000, meaning that another 1000 seconds must occur before the light changes states again.
  } // In total, this makes the light change state every 1000ms from either being on or off, which in effect makes it blink.

  if( millis() - ledTimer2 >= onTime1 )
  { // This function checks if the time since the function has started and now is larger than 3000 ms, or three seconds.
    if( digitalRead( 12 ) == HIGH )
    { // If the light its on, then it needs to be turned off.
      digitalWrite( 12 , LOW ); // This turns the light off.
    }
    else
      { // Otherwise, if the light is off when the time has passed, this happens.
      digitalWrite( 12 , HIGH );
      } // This function will make sure that whatever the state of the light was, if the correct time 
    ledTimer2 += onTime1; // This pushes the ledTimer variable forward 3000, meaning that another 1000 seconds must occur before the light changes states again.
  } // In total, this makes the light change state every 3000ms from either being on or off, which in effect makes it blink. 
} // This is repeated until the Arduino is turned off.


