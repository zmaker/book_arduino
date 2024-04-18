/*
  Blink.cpp - 
*/

#include "Arduino.h"
#include "Blink.h"

Blink::Blink(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Blink::blink(int tim)
{
  digitalWrite(_pin, HIGH);
  delay(tim);
  digitalWrite(_pin, LOW);
  delay(tim);  
}
