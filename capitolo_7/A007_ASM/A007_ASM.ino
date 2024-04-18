/*
7.7 - Esempio assembler per AVR - solo per Arduino UNO R3, Nano ecc ecc
*/

void setup() {
  //imposto la seriale
  Serial.begin(9600);
  while (!Serial);

  // messaggio
  Serial.println("Esempio ASM");

  //creo un conto alla rovescia perché se la scheda
  //si resettasse subito non faremmo in tempo a caricare il programma
  for (int i = 0; i < 20; i++) {
    //stampo un punto 
    Serial.print(".");
    //attendo un secondo
    delay(1000);
  }

  //micro pausa (pari a un copo di clock)
  asm volatile ("nop");

  //resetto il programma
  asm volatile ("jmp 0");
    
}

void loop() {}
