/**********************
 * LDR value to IFTTT *
**********************/

//
// By: Joseba Egia, Hirikilabs hiri laborategia, Tabakalera.
// Date: 10/05/2016 
// V0.1
//
// This simple sketch reads a value from a LDR sensor on pin A0 and compares it to a treshold value, 
// publishing a event when the sensor value goes above the threshold value.
//


const int sensorPin = A0;                   // LDR sensor will be at pin A0
int lightLevel, high = 0, low = 1023;       // Arduino analog reads are discretized from 0=0V to 1023=5V
int treshold = 100;                         // the treshold value to compare our LDR readings (from 0 to 255)
unsigned long ms = 2000;

void loop() {                               // main loop

lightLevel = analogRead(sensorPin);         // we read the sensor value
autoTune();                                 // we autotune our output values converting them to 0-255 range

if (lightLevel < treshold)                  // if light level is below the treshold value, go to it
{
    Particle.publish ("NoLight");           // That simple, publish an event to internet
    delay(ms);                              // we are going to wait at least 20 seconds between each publish
}
}

// The autotune script works deleting from our range the unused values of our discretization. 

void autoTune()                             
{
    if (lightLevel < low)
    {
        low = lightLevel;
    }

    if (lightLevel > high)
    {
        high = lightLevel;
    }
    
    lightLevel = map(lightLevel, low+30, high-30, 0, 255);
    lightLevel = constrain(lightLevel, 0, 255);
}
