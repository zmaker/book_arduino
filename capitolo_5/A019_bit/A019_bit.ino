/*
stampiamo i bit di un numero
*/ 

void setup() {
  //imposto la porta seriale
  Serial.begin(9600);
  while(!Serial);
  //il numero da elaborare:
  unsigned int n = 42258;
  //stampo il numero
  Serial.println(n);
  //un ciclo di 16 passi (da destra a sinistra)
  for (int i = 15; i >= 0; i = i - 1) {
    //estraggo il valore del bit alla posizione i
    byte b = bitRead(n, i); 
    Serial.print(b);  
  }  //stampa 1010010100010010 
}

void loop() {
}
