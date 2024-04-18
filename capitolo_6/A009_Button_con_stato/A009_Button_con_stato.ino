/*
Pulsante con stato
*/

//variabile che memorizza lo stato del LED
int stato_led = LOW;

void setup() {
  //configuro il pin per il pulsante
  pinMode(2, INPUT);
  //configuro il pin per il lED
  pinMode(3, OUTPUT);
}

void loop() {
  //verifico se è stato premuto il pulsante
  if (digitalRead(2)) {
    //cambio lo stato
    stato_led = !stato_led;
    //attendo prima di uscire dall'if
    //e leggere di nuovo lo stato del pulsante
    delay(300);
  }
  
  //applico lo stato al pin del LED
  digitalWrite(3, stato_led);
}
