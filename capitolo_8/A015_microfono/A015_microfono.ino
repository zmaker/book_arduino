/*
8.15 - Clap control con microfono

- led su pin 13
- sensore microfonico su pin A0
*/

//variabile soglia di attivazione
int soglia = 0;

void setup() {
  //imposto il pin per il LED
  pinMode(13, OUTPUT);
  
  //accendo il led durante la procedura di calibrazioe automatica
  digitalWrite(13, HIGH);
  //calibrazione automatica
  calibra();
  //spendo il led
  digitalWrite(13, LOW);  
}

void loop() {
  //leggo il segnale rilevato dal mic
  int n = analogRead(A0);
  //se supera la soglia...
  if (n > soglia) {
    //cambio stato al pin
    digitalWrite(13, !digitalRead(13));
    //piccola pausa / debouncing
    delay(100);
  }   
}

void calibra() {
  //per 100 volte...
  for (int i = 0; i < 100; i++) {
    //leggo il valore del microfono
    soglia += analogRead(A0);  
    delay(50);
  }  
  //calcolo la media
  soglia = soglia/100;
  //incremento del 20% il valore
  soglia = (int)((float)soglia * 1.2f);
}