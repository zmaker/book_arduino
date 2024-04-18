/*
  Blink.h – Libreria per far lampeggiare un LED
*/
#ifndef Blink_h
#define Blink_h

#include "Arduino.h"

class Blink
{
  public:
    Blink(int pin);
    void blink(int tim);    
  private:
    int _pin;
};

#endif
