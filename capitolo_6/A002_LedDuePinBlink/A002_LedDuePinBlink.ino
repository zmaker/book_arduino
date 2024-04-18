/*
Blink di un LED con due pin GPIO
*/

void setup() {
  //imposto un pin come uscita
  pinMode(2, OUTPUT);
  //imposto un pin come ingresso
  pinMode(3, OUTPUT);
  //inposto il pin 3 a livello basso così che si comporti come GND
  digitalWrite(3, LOW);  
}

void loop() {
  //accendo il LED controllando il pin 2
  digitalWrite(2, HIGH); 
  //pausa 1 secondo
  delay(1000);     
  //spengo il LED controllando il pin 2        
  digitalWrite(2, LOW); 
  //pausa 1 secondo
  delay(1000);         
}
