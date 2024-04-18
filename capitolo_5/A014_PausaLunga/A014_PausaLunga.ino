/*
Pausa lunga
*/ 
//variabile per memorizzare il tempo d'inizio
unsigned long t1 = 0;
//durata della pausa
const unsigned long pausa = 1l*60l*1000l; //1 minuto

void setup() {
  //preparo la seriale
  Serial.begin(9600);
  //attendo la seriale
  while(!Serial);
  //il pin 13 è un uscita
  pinMode(13, OUTPUT);
  //salvo il tempo corrente
  t1 = millis();
  //stampo il tempo di partenza a video
  Serial.print("tempo iniziale: ");
  Serial.println(t1);		
}

void loop() {
  //calcolo la differenza tra l'istante corrente e il 
  //tempo salvato
  unsigned long differenza = millis() - t1;
  //se la differenza è maggiore del valore di pausa
  //desiderato...
  if (differenza > pausa) {
    //accendo il LED	
	digitalWrite(13, HIGH);
    //scrivo un messaggio
    Serial.println("Fine pausa.");
    //mi fermo per sempre
    while(true);
  }

}
