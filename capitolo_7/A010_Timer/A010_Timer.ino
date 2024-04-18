/*
7.10 - Utilizzo dei Timer con Arduino UNO
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
  // prescaler a  1:1024
  TCCR1B = 0b00000101;
  //reset del contatore
  TCNT1=0x0000; 
  //abilita l'interrupt
  TIMSK1=0x01;
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
ISR(TIMER1_OVF_vect) {
  //imposto a uno la variabile tick   
   tick = 1;
}

