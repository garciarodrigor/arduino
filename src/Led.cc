/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.

 */

#include <Arduino.h>

#define LED_PIN 13

void setup()
{
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);   // set the LED on
  delay(100);              // wait for a second
  
  digitalWrite(LED_PIN, LOW);    // set the LED off
  delay(1000);              // wait for a second
  
  Serial.println(millis());
}

