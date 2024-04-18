/*
8.3 - Lettura sensore analogico

Collegare il sensore in serie con una resistenza. 
Il punto centrale della serie va al pin A0
*/

void setup() {
  //imposto la seriale
  Serial.begin(9600);
}

void loop() {
  //leggo il valore sul pin A0
  int lum = analogRead(A0);
  //lo stampo sulla seriale
  Serial.println(lum);
  //un piccolo delay
  delay(200);
}
