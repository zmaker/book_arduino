/*
9.1 - controllo stepper motor
*/

void setup() {
  //imposto i pin
  //step
  pinMode(13, OUTPUT);  
  //enable
  pinMode(12, OUTPUT);  
  //dir
  pinMode(11, OUTPUT);

  //imposto la direzione
  digitalWrite(11, LOW);
  //attivo il driver
  /* Se il motore non gira provare a impostare lo stato a HIGH 
  Normalmente il driver Polulu richiede lo stato basso per abilitare il 
  driver
   */
  digitalWrite(12, LOW);
  //una pausa prima di partire
  delay(1000);
}

void loop() {
  //cambio lo stato del pin 13 generando impulsi
  digitalWrite(13, !digitalRead(13));
  //diminuendo la pausa aumenta la velocità
  delay(100);
}