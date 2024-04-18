/*
Pausa lunga
*/ 

//definizione delle note
#define	F3	174.61
#define	Gb3	185.00
#define	G3	196.00
#define	Ab3	207.65
#define	LA3	220.00
#define	Bb3	233.08
#define	B3	246.94
#define	C4	261.63
#define	Db4	277.18
#define	D4	293.66
#define	Eb4	311.13
#define	E4	329.63
#define	F4	349.23
#define	Gb4	369.99
#define	G4	392.00
#define	Ab4	415.30
#define	LA4	440.00

//definizione delle pause o durate
#define Q 500 //tono
#define H 2*Q //mezzotono
#define E Q/2 //ottava
#define S Q/4 //sedicesimo
#define W 4*Q //intero

//creiamo ua variabile per il numero del pin da usare
int pin = 12;

void setup() {}

void loop() {
  //suono una nota
  tone(pin,LA3,Q);
  //faccio una pausa 
  delay(1+Q);
  tone(pin,LA3,Q);
  delay(1+Q);
  tone(pin,LA3,Q);
  delay(1+Q);
  tone(pin,F3,E+S);
  delay(1+E+S);
  tone(pin,C4,S);
  delay(1+S);
    
  tone(pin,LA3,Q);
  delay(1+Q);
  tone(pin,F3,E+S);
  delay(1+E+S);
  tone(pin,C4,S);
  delay(1+S);
  tone(pin,LA3,H);
  delay(1+H);
}

