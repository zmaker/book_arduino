/*
9.2 - controllo potenziometro digitale - DS1804-010
*/

//definisco i nomi dei pin
#define CS 12
#define UD 11
#define INC 10

void setup() {
  //imposto i pin 
  pinMode(CS, OUTPUT);
  pinMode(UD, OUTPUT);
  pinMode(INC, OUTPUT);
  //attivo il chip
  digitalWrite(CS, LOW);
}

void loop() {
  //per 100 volte...
  for (int i = 0; i < 100; i++){
    //incremento il valore del potenziometro
    stepup();
    delay(200);    
  }
  //per 100 volte...
  for (int i = 0; i < 100; i++){
    //decremento il valore del potenziometro
    stepdown();
    delay(200);
    Serial.begin(analogRead(A0));
  }
}

//funzione per incrementare il valore del potenziometro
void stepup(){
  digitalWrite(INC, LOW);
  digitalWrite(UD, HIGH);
  digitalWrite(INC, HIGH);
}

//funzione per decrementare il valore del potenziometro
void stepdown(){
  digitalWrite(INC, LOW);
  digitalWrite(UD, LOW);
  digitalWrite(INC, HIGH);
} 
