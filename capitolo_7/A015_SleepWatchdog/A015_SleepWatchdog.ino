/*
7.15 - Sleep con Arduino UNO e risveglio con WD
*/

//includo le librerie per lo sleep
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>

//flag modificato dal timer watchdog
volatile int watchdog = 1;

void setup() {
  //imposto i pin
  pinMode(13, OUTPUT);
  //setup del timer watchdog
  MCUSR &= ~(1<<WDRF);
  WDTCSR |= (1<<WDCE) | (1<<WDE);
  //prescaler a 4 secondi
  WDTCSR = 0<<WDP0 | 1<<WDP3; 
  //modo: interrupt
  WDTCSR |= _BV(WDIE);
}

void loop() {
  if (watchdog == 1) {
    //azzero il flag 
    watchdog = 0;
    //modifico lo stato del pin
    digitalWrite(13, !digitalRead(13));    
    //attiva lo sleep mode
    enterSleep();
  }
}

ISR(WDT_vect) {
  watchdog = 1;
}


void enterSleep(void) {
  //configuro lo sleep mode
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);  
  sleep_enable();
  sleep_mode();

  //riprenderà da qui...
  sleep_disable(); 
  //abilita le periferiche del microcontrollore
  power_all_enable();
}
