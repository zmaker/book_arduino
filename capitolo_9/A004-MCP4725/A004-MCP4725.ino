/*
9.4 - generazione segnali analogici con il DAC MCP4725
*/

//aggiungo le librerie necessarie
#include <Wire.h>
#include <Adafruit_MCP4725.h>

//creo un'istanza del dac
Adafruit_MCP4725 dac;

void setup(void) {
  //inzializzo il DAC fornendo il suo indirizzo i2c
  dac.begin(0x62);  
}

void loop(void) {
  //imposto i valori con un ciclo for
  for (int i = 0; i < 4095; i++) {
      dac.setVoltage(i, false);
      delay(5);
  } 
}
