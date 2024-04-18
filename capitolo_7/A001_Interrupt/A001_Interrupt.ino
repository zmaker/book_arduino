/*
7.1 - Interrupt
*/

/**
 * Test interrupt (su arduino UNO solo pin 2 e 3)
 * 
 * collegare un tasto al pin 3
 * collegare un led al pin 13
 */

void setup() {
  //configuro i pin
  pinMode(13, OUTPUT);
  pinMode(3, INPUT);
  //collego la funzione di gestione delle interrupt al pin 3
  // la funzione è richiamata quando il segnale passa da HIGH a LOW
  attachInterrupt(digitalPinToInterrupt(3), cambia, FALLING);
}

// stato del LED - può essere cambiata da altre parti di codice
volatile int stato = LOW; 

void loop() {
  //imposto lo stato del LED
  digitalWrite(13, stato);  
}

/*
 * Funzione di gestione dell'interrupt: non riceve parametri e non 
 * restituisce nulla.
 * Deve essere rapida e può usare solo variabili volatili e globali
 */
void cambia() {
  //cambia lo stato del LED
  stato = !stato;  
}