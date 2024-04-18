/*
7.13 - Sleep con Arduino UNO
*/

//includo le librerie per lo sleep
#include <avr/sleep.h>
#include <avr/power.h>

//funzione richiama al risveglio
void pin2Interrupt(void) {
  //disabilita l'interrupt
  detachInterrupt(digitalPinToInterrupt(2));
  //accende il led
  digitalWrite(13, HIGH);
}

void enterSleep(void) {
  //collegao una funzione all'interrupt
  attachInterrupt(digitalPinToInterrupt(2), pin2Interrupt, LOW);
  delay(100);
  //spengo il led
  digitalWrite(13, LOW);
  //configuro la modalità di sleep
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  //abilito lo sleep
  sleep_enable();  
  //entro in sleep
  sleep_mode();
  /* il programma qui è in sleep e attende l'evento di risveglio */

  /* Il programma riprende qui dopo lo sleep */  
  //disabilito lo sleep
  sleep_disable(); 
}

void setup() {
  //configuro la seriale
  Serial.begin(9600);
  //imposto i pin
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);

  //scrivo un messaggio
  Serial.println("Sleep Test sketch");
  //accendo il led sul pin 13
  digitalWrite(13, HIGH);
}

//variabile conteggio secondi
int count = 0;

void loop() {
  //ogni secondo che passa aumento il valore di count
  delay(1000);
  count++;
  //scrivo un messaggio
  Serial.print("Attivo da ");
  Serial.print(count);
  Serial.println(" s.");

  //a tre secondi attivo lo sleep
  if(count == 3) {
    Serial.println("Sleep!");    
    delay(200);
    count = 0;
    enterSleep();
  } 
}
