/*
8.4 - Lettura termistore

Collegare il sensore in serie con una resistenza. 
Il punto centrale della serie va al pin A0

Collegare un led sul pin 13
*/

void setup() {
  //imposto la seriale
  Serial.begin(9600);
  //imposto il pin 13 per il LED
  pinMode(13, OUTPUT);
}

void loop() {
  //leggo il valore sul pin A0
  int temp = analogRead(A0);
  //lo stampo
  Serial.println(temp);
  //se il valore è sopra alla soglia...
  if (temp >= 308) {
    //accendo il LED
    digitalWrite(13, HIGH);
  } else {
    //altrimenti: spengo il LED
    digitalWrite(13, LOW);
  }
  delay(200);
}
