/*
7.14 - Sleep con Arduino UNO e risveglio da timer
*/

//includo le librerie per lo sleep
#include <avr/sleep.h>
#include <avr/power.h>

//flag modificato dal timer
volatile int flag = 0;

void setup() {
  //imposto i pin
  pinMode(13, OUTPUT);
  //setup del timer
  TCCR1A = 0x00; 
  TCNT1=0x0000; 
  //prescaler a 1024
  TCCR1B = 0x05;
  //interrupt su overflow
  TIMSK1=0x01;
}

void loop() {
  if(flag == 1) {
    //azzero il flag 
    flag = 0;
    //modifico lo stato del pin
    digitalWrite(13, !digitalRead(13));    
    //attiva lo sleep mode
    enterSleep();
  }
}

ISR(TIMER1_OVF_vect) {
   flag = 1;
}

void enterSleep(void) {
  //configuro lo sleep mode
  set_sleep_mode(SLEEP_MODE_IDLE);  
  sleep_enable();

  //disabilita le periferiche
  power_adc_disable();
  power_spi_disable();
  power_timer0_disable();
  power_timer2_disable();
  power_twi_disable();  

  sleep_mode();

  //riprenderà da qui...
  sleep_disable(); 
  
  //abilita le periferiche del microcontrollore
  power_all_enable();
}
