/*
8.8 - Rilevatore ostacoli con sensore IR e LED emettitore

- utilizza un sensore PNA PNA4602 e un LED IR
*/

//dichiarazione della funzione per la lettura del sensore
int letturaIR(int readPin, int triggerPin); 

void setup() {    
  //imposto i pin
  pinMode(4, OUTPUT);    
  pinMode(5, INPUT);   
  //inizializzo la seriale
  Serial.begin(9600);    
}  

void loop() {
  //richiamo la funzione di misura della distanza
  int obst = letturaIR(5,4);     
  //stampo la distanza
  Serial.print("ostacolo: "); 
  Serial.println(obst); 
  //attendo per la prossima misura
  delay(100); 
}  

int letturaIR (int readPin, int triggerPin) {   
  //per generare 38.5KHz serve un periodo di 26 microsecondi
  int halfPeriod = 13; 
  // 38 cicli sono pari a circa un impulso della durata di un millisecondo
  int cycles = 38; 
  //invio il segnale sul LED
  for (int i=0; i <=cycles; i++)   {     
    digitalWrite(triggerPin, HIGH);      
    delayMicroseconds(halfPeriod);     
    digitalWrite(triggerPin, LOW);      
    delayMicroseconds(halfPeriod - 1);   //12 us per compensare i ritardi delle digitalWrite
  }   
  //restituisco lo stato del pin a cui è collegato il sensore
  return digitalRead(readPin); 
}
