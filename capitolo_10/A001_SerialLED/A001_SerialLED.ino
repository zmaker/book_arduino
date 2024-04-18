/*
10.1 - controllo LED via Seriale
*/

void setup() {
  //imposto la seriale a 9600 baud
  Serial.begin(9600);
  //configuro il pin 13 come uscita
  pinMode(13, OUTPUT);
}

void loop() {
  //attendo la ricezione di caratteri - fino a che non ricevo caratteri...
  while (Serial.available() > 0) {
    //se arriva un carattere lo salvo in una variabile
    char ch = Serial.read(); 
    //se ch vale 'a': accendo il LED
    if (ch == 'a') digitalWrite(13, HIGH);
    //se ch vale 's': spengo il LED
    if (ch == 's') digitalWrite(13, LOW);      
  }
}
