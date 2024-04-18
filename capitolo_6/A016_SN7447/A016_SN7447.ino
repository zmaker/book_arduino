/*
Pilotaggio di display a 7 segmenti con SN7447
*/

//creo ua variabile globale per generare le cifre da visualizzare
int count = 0;

void setup() {
  //imposto i pin di uscita
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  /* estraggo i bit dalla variabile count
  count | d c b a 
  0     | 0 0 0 0 
  1     | 0 0 0 1
  2     | 0 0 1 0
  3     | 0 0 1 1
  4     | 0 1 0 0
  5     | 0 1 0 1
  */
  int a = bitRead(count, 0);
  int b = bitRead(count, 1);
  int c = bitRead(count, 2);
  int d = bitRead(count, 3);

  //applico i bit alle uscite
  digitalWrite(2, a);
  digitalWrite(3, b);
  digitalWrite(4, c);
  digitalWrite(5, d);
  
  //incremento count
  count++;
  //se count arriva a 16, la azzero
  if (count == 16) count = 0;
  //pausa di 1 secondo
  delay(1000);
}



