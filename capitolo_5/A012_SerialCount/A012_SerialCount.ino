/*
Conteggio su seriale
*/ 

int i = 0;

void setup() {
  //imposto la velocità
  Serial.begin(9600);
  //attendo che la seriale sia attiva
  while (!Serial);
}

void loop() {
  //stampo senza andare a capo
  Serial.print("i = ");
  //stampo il valore di i e vado a capo
	Serial.println(i);
  //incremento i
  i++;
  //attendo un secondo
  delay(1000);
}
