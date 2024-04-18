/*
Shift register con Arduino
*/

void setup() {
  //imposto i pin 
  pinMode(3, OUTPUT); //clock
  pinMode(4, OUTPUT); //clear
  pinMode(5, OUTPUT); //dati
  //inviamo un segnale di reset
  digitalWrite(4, LOW);
  delay(100);
  digitalWrite(4, HIGH);

  //preparo il clock
  digitalWrite(3, LOW);

  //carichiamo un solo bit pari a 1
  //il clock sale
  digitalWrite(3, HIGH);
  //trasmetto il primo bit
  digitalWrite(5, HIGH);
  delay(10);
  //il clock scende
  digitalWrite(3, LOW);
}

void loop() {
    //il clock sale
    digitalWrite(3, HIGH);
    delay(300);   
    //trasmetto solo zeri…
    digitalWrite(5, LOW);
    //il clock scende e i dati scorrono
    digitalWrite(3, LOW);
}
