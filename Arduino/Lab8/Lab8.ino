unsigned long timer; // create a timer
//create arrays to hold the calculated voltage values
double circuitVoltage[50];
double theveninsVoltage[50];
double ammeterCurrent; //this will be for the calculated current
int loopCount = 0; // we will look 50 times and average the voltages for a more stable measurment
//setup
void setup()
{
analogReference( EXTERNAL );// Aref needs to be attached to 3.3 Volt.
timer = millis(); //initialize the timer to the current time
Serial.begin(9600); //open serial communications at a baud rate of 9600
//set up the analog pins as inputs
pinMode( A1, INPUT );
pinMode( A2, INPUT );
}// end setup
//main loop
void loop()
{
//if 10 ms has passed we calculate the voltages based on ADC values
if ( millis() - timer >= 10 )
{
circuitVoltage[loopCount] = 3.3 * analogRead(A1) / 1024; //Voltmeter Voltage
theveninsVoltage[loopCount] = 3.3 * analogRead(A2) / 1024; //Voltmeter Voltage
loopCount++;//increment our loop counter
//if we have looped 50 times we will average out voltages across all 50 values and display the average.
if ( loopCount >= 50 )
{
loopCount = 0;// reset the loop count
//print out the results to the serial monitor
Serial.print("Starting Circuit Voltage: ");
Serial.print(average(circuitVoltage));
Serial.print(" V, Equivalent Circuit Voltage: ");
Serial.print(average(theveninsVoltage));
Serial.print(" V\n\r");
}//end if
timer += 10;//increment the timer
}//end if
}//end loop
//this function takes an array of 50 values and returns the average.
double average( double numbers[50] )
{
float sum = 0; // initialize a summing variable
//add up all the voltage values
for ( int i = 0; i < 50; i++ )
{
sum += numbers[i];
}//end for
return sum / 50;// return the average value
}//end function