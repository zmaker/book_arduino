/*
Invio di messaggi nel loop
*/ 

void setup() {
  //imposto la velocità
  Serial.begin(9600);
  //attendo che la seriale sia attiva
  while (!Serial);
}

void loop() {
  //trasmetto un messaggio
  Serial.println("Hello World!");
  //attendo un secondo
  delay(1000);
}
