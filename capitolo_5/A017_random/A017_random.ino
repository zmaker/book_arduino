/*
Generiamo numeri casuali
*/ 

void setup() {
  //imposto la porta seriale
  Serial.begin(9600);
  while(!Serial);
  //inserisco un seme casuale leggendo da un ingresso analogico scollegato
  randomSeed(analogRead(A0));  
}

void loop() {
  //estraggo un numero da 0 a 99
  long n = random(100);
  //lo stampo
  Serial.println(n);
  //attendo 1 secondo
  delay(1000);
}



