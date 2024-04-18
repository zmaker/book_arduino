/*
Pilotaggio di display a 7 segmenti
*/

//definisco delle costanti associate ai pin
#define A 6
#define B 7
#define C 8
#define D 10
#define E 11
#define F 12
#define G 13

void setup(){
  //imposto i pin 
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {
  //visualizzo uno zero
  zero(); 
  delay(1000);
  //visualizzo un "uno"
  uno();
  delay(1000);
  //e così via…
}

void zero(){
  //accendo i pin necessari a formare un o zero.
  digitalWrite(G, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);  
}

void uno(){
  //accendo i pin necessari a formare un uno.
  digitalWrite(G, LOW);
  digitalWrite(F, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(DP, LOW);
}


