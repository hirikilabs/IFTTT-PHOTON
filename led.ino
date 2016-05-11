/**********************
 *   IFTTT to LED    *
**********************/

//
// By: Joseba Egia, Hirikilabs hiri laborategia, Tabakalera.
// Date: 10/05/2016 
// V0.1
//
// This simple sketch takes a IFTTT published event on particle cloud and activates a led for 2 seconds.
//



const int ledPin = D0;                                          // Led will be on pin D0
unsigned long ms = 2000;                                        // We will wait for 2 seconds in between events

void setup()                            
{
  pinMode(ledPin, OUTPUT);                                      // D0 pin as output
  Particle.subscribe("event", shine);                           // When event called "event" happens, do shine loop
}

void shine(const char *event, const char *data)                 // shine lopp will be done for each event
{
    digitalWrite(ledPin, HIGH);                                 // sets the LED on
    delay(ms);                                                  // wait
    digitalWrite(ledPin, LOW);                                  // sets the LED off
}
