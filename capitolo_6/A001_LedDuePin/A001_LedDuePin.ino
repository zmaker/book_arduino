/*
Controllo di un LED con due pin GPIO
*/

void setup() {
  //imposto un pin come uscita
  pinMode(2, OUTPUT);
  //imposto un pin come ingresso
  pinMode(3, OUTPUT);

  //il pin 3 riceve la corrente
  digitalWrite(3, LOW);
  //il pin 2 la fornisce
  digitalWrite(2, HIGH);
}

void loop() {}
