/*
8.9 - Misura distanza con HC SR04 Sensore ultrasuoni
*/

//definizione dei pin
const int triggerPort = 9;
const int echoPort = 10;
const int led = 13;
 
void setup() {
  //impostazione dei pin
  pinMode(triggerPort, OUTPUT);
  pinMode(echoPort, INPUT);
  pinMode(led, OUTPUT);
  //configurazione della seriale
  Serial.begin(9600);
  Serial.print( "Sensore Ultrasuoni: ");
}
 
void loop() {
  //invia un impulso di 10 microsec su trigger
  digitalWrite( triggerPort, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( triggerPort, LOW );
 
  //misuro la durata dell'impulso restituito sul pin di echo
  long durata = pulseIn( echoPort, HIGH );
  //calcolo distanza
  long distanza = durata / 58;
 
  Serial.print("distanza: ");
 
  //dopo 38ms è fuori dalla portata del sensore
  if( durata > 38000 ){
    Serial.println("Fuori portata   ");
  } else{ 
    Serial.print(distanza); 
    Serial.println(" cm     ");
  }
 
  //se la distanza è minore di 10 cm accendo il LED
  if(distanza < 10){
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
 
  //Aspetta 1000 microsecondi
  delay(1000);
}
