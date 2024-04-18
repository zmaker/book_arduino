/*
7.11 - Utilizzo dei Timer con Arduino UNO - modalità CTC
*/

//variabile modificata dal timer
volatile int tick = 0;

void setup() {
  //configuro il pin
  pinMode(13, OUTPUT);
  //disabilito le interrupt
  cli();
  //imposto i registri per i timer
  TCCR1A = 0x00;   
  //prescaler
  TCCR1B = 0b00000100; 
  //conteggio da raggiungere
  OCR1A = 0x0A00;

  //Attivo il CTC mode: 1 sul quarto bit del registro: 0b 0000 1000
  TCCR1B |= 0b00001000;

  //abilita l'interrupt
  TIMSK1 = 0b00000010;

  //riabilito le interrupt
  sei();
}

void loop() {
  //se tick è impostata...
  if (tick == 1) {
    //la azzero
    tick = 0;
    //cambio stato del pin
    digitalWrite(13, !digitalRead(13));
  }
}

//funzione chiamata allo scadere del timer
//Timer1 Overflow interrupt.
ISR(TIMER1_COMPA_vect) {
  //imposto a uno la variabile tick   
   tick = 1;
}

