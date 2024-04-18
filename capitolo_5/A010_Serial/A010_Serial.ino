/*
utilizzo porta seriale
*/

void setup() {
  //imposto la velocità
  Serial.begin(9600);
  //attendo che la seriale sia attiva
  while (!Serial);
  //trasmetto un messaggio
  Serial.println("Hello World!");
}

void loop() {
}
