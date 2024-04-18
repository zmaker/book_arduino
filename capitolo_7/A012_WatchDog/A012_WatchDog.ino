/*
7.12 - Utilizzo dei Watchdog con Arduino UNO
*/

//includo le librerie per AVR
#include <avr/wdt.h>
#include <avr/sleep.h>
#include <avr/power.h>

//variabile modificata dal WD
volatile unsigned int flag = 0;

void setup() {
  //imposto il pin
  pinMode(13, OUTPUT);
  //disattiva il watchdog
  wdt_disable(); 
  //configuro il WD
  wdsetup();
}

void loop() {
  if (flag) {
    //imposto a 0 il flag
    flag = 0;   
    //disattiva il watchdog
    wdt_disable(); 
    //cambio stato al pin
    digitalWrite(13, !digitalRead(13));
    //configuro il WD
    wdsetup();
  }
}

//richiamata quando scatta il WD
ISR(WDT_vect) {
   flag = 1;
}

//imposto il WD
void wdsetup() {
  //disattiva tutti gli interrupt
  cli();
  //imposta il registro del watchdog
  WDTCSR |= ((1<<WDCE) | (1<<WDE));
  //imposta la modalità "interrupt" ed il timeout ad 1 secondo
  WDTCSR = ((1<<WDIE)| (1<<WDP2) | (1<<WDP1)); 
  //riattiviamo gli interrupt globali
  sei();
}