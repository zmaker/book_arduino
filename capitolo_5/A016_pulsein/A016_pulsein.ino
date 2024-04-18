/*
Misurare il tempo di pressione del pulsante
*/ 

void setup() {   
  //configuro il pin
  pinMode(7, INPUT);
  //preparo la seriale
  Serial.begin(9600);
  while (!Serial);
}  

void loop() {
  //misuro il tempo e salvo il risultato i una variabile
  unsigned long durata = pulseIn(7, HIGH);
  if (durata > 0) {
    //se ho un valore lo stampo 
    Serial.print(“durata impulso: ”);
    Serial.print(durata / 1000);
    Serial.println(“ ms.”);
  }
}


