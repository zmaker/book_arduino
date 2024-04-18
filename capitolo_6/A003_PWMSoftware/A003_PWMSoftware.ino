/*
PWM software
*/

//contatore per i passi
int i = 0;
//soglia per impostare il duty cycle (da 0 a 255)
int pwmsw = 17;

void setup() {
  //imposto un pin come uscita
  pinMode(13, OUTPUT);  
}

void loop() {
  //se i è minore della soglia accendo il led
  if (i < pwmsw) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW); //altrimenti il led è spento
  }
  //inseriamo una piccoal pausa  
  delayMicroseconds(100);  
  //incremento i
  i++;
  //se i supera 255, la azzero
  if (i > 255) i = 0;    
}
