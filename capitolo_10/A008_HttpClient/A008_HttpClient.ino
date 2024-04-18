/*
10.8 - Web Client HTTP con Ehternet e modulo W5500
*/

//librerie
#include <SPI.h>
#include <Ethernet.h>

//imposto il mac address
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0xD5, 0xB1 };
//indirizzo del server a cui collegarsi
char server[] = "www.zeppelinmaker.it";
//client per ethernet
EthernetClient client;

void setup() {
  //configuro la seriale
  Serial.begin(9600);
  while (!Serial) {}
  //avvio il modulo e chiedo un IP (uso DHCP)
  Ethernet.begin(mac);

  delay(1000);
  //provo a collegarmi al server
  Serial.println("connessione…");
  if (client.connect(server, 80)) {
    Serial.println("connesso");
    // invio la richiesta HTTP epr la risorsa helloworld.txt
    client.println("GET /helloworld.txt HTTP/1.1");
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  } else {    
    Serial.println("connessione fallita");
  }

  while(true) {
    // se arrivano dei byte dal server li stampo  
    if (client.available()) {
      char c = client.read();
      Serial.print(c);
    }

    // se il server mi disconnette...
    if (!client.connected()) {
      Serial.println();
      Serial.println("disconnecting.");
      //fermo il client
      client.stop();
      break;
    }
  }  
}

void loop() {}


