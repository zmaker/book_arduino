/*
8.16 - Lettore rfid/NFC PN532 

libreria PN532 - 
https://learn.adafruit.com/adafruit-pn532-rfid-nfc/arduino-library
*/

//aggiungo le librerie necessarie
#include <Wire.h>
#include <Adafruit_PN532.h>

//definisco i pin per interrupt e reset della scheda 
#define PN532_IRQ   (2)
#define PN532_RESET (3) 
//creo l'oggetto pn532
Adafruit_PN532 nfc(PN532_IRQ, PN532_RESET);

//array/buffer di lettura
char buf[4];
//array con l'UID del tag
uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 }; 
// dimensione dello UID (4 o 7 byte  dipende dal tipo di tag)
uint8_t uidLength;                       
  

void setup(void) {
  //attivo la porta seriale
  Serial.begin(9600);
  //avvio e configuro il lettore PN532
  nfc.begin();
  nfc.SAMConfig();   
}

void loop(void) {  
  //provo a leggere una carta (se presente!)
  int success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);
  //se è stata rilevata una carta ed ho letto 4 byte...
  if ((success) && (uidLength == 4)) {
    //leggo i 4 byte e li scrivo nel buffer buf
    for (int i = 0; i < 4; i++) {  
      sprintf(buf, "%03u", uid[i]);    
      //stampo l'uid
      Serial.print(uid[i]);  
      Serial.print(" ");  
    }
    //vado a capo
    Serial.println("");
    //attendo 1 secondo prima di leggere di nuovo
    delay(1000);
  }
}