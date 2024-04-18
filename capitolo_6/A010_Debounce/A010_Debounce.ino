/*
LED con stato e debounce non bloccante
*/

//definisco con delle costanti i nomi dei pin da usare
#define BUTTON 2
#define LED 13

//creo una variabile per lo stato del LED
int stato = LOW;

//creo una variabile in cui salvare l'istante in cui ho premuto il tasto
unsigned long t = 0;
//definisco qual'è il tempo di debounce (in cui ignorerò ogni azione sul tasto)
const unsigned long debounce_delay = 200;

void setup() {
  //configuro i pin di ingresso e uscita
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  //imposto lo stato inziale del pin
  digitalWrite(LED, stato);
}

void loop() {
  //leggo lo stato del tasto e lo memorizzo in una variabile
  int tasto = digitalRead(BUTTON);

  //se il tasto è premuto 
  if (tasto) {    
    //se il tempo trascorso dalla prima pressione del tasto è maggiore del tempo di debounce...
    if ((millis()-t) > debounce_delay) {
      //i rimbalzi sono finiti e posso cambiare lo stato
      stato = !stato;
      //imposto il pin con lo stato impostato
      digitalWrite(LED, stato);
      //salvo il tempo corrente
      t = millis();
    }
  }
}

