/*
7.9 - Impostazione dei pin utilizzando i registri di R4      
*/

void setup() {
  //imposto il pin 13 come uscita
  //pinMode(13, OUTPUT); // D13 -> P111
  R_PORT1->PDR |= bit(11); 
}

void loop() {
  //attivo il pin 13
  //digitalWrite(13, HIGH);
  R_PORT1->POSR = bit(11);
  delay(100);
  //spengo il pin 13
  R_PORT1->PORR = bit(11);
  delay(500);
}
