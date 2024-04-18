/*
9.3 - generazione segnali analogici con il DAC di R4
*/

//aggiungo la libreria 
#include "analogWave.h"
//creo un'istanza di analogWave e indico il pin da usare
analogWave wave(DAC);
//imposto la frequenza in Hz
int freq = 1000;
 
void setup() {}
 
void loop() {
  //imposto la forma d'onda
  wave.sine(freq);
  wave.begin(freq); 
  //la attivo
  wave.start();

  delay(5000);

  //imposto la forma d'onda "quadrata"
  wave.square(freq);
  wave.begin(freq); 
  //la attivo
  wave.start(); 

  delay(5000);

  //imposto la forma a dente di sega
  wave.saw(freq); 
  wave.begin(freq);
  //la attivo
  wave.start();   

  delay(5000);     
}