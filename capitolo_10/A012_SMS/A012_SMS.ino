/* 
Listato 10.12 – Invio di SMS con SIM800
*/
//serve la software serial
#include <SoftwareSerial.h>

//seriale per la comunicazine con il modulo SIM800
SoftwareSerial sim800(3, 2);

//variabile per leggere il pulsante
int bt, prevbt;

void setup() {
  //pin per il pulsante
  pinMode(4, INPUT);
  //setup della seriale
  Serial.begin(9600);  
  //setup della seriale verso sim800
  sim800.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);

  //verifico se la SIM800 risponde
  sim800.println("AT");
  //stampo quello che ricevo
  updateSerial();

  //imposto la modalità SMS
  sim800.println("AT+CMGF=1");
  updateSerial();
}

void loop() {
  //leggo lo stato del pin
  bt = digitalRead(4);

  //intervetto il fronte di discesa - rilascio del pulsante
  if (prevbt && !bt) {
    Serial.println("SMS..."); 
    //configuro il numero a cui mandare il messaggio
    String cmd = "AT+CMGS=\"+39numeroditel\"";
    sim800.println(cmd);
    updateSerial();
    //inserisco il messaggio
    sim800.print("Hello zeppelinmaker");
    updateSerial();
    //dò l'invio (CTRL Z)
    sim800.write(26);     
    Serial.println("SMS inviato"); 
  }
  //salvo lo stato del pulsante
  prevbt = bt;
}

void updateSerial(){
  delay(500);
  while (Serial.available()) {
    sim800.write(Serial.read());
  }
  while(sim800.available()) {
    Serial.write(sim800.read());
  }
}
