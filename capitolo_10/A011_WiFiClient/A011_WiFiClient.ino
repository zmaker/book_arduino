/* 
Listato 10.11 – Simple WiFi Client
*/
//includo le librerie
#include <WiFi.h>

//costanti con password e ssid di rete
#define MY_WIFI_SSID "nomerete"
#define MY_WIFI_PASS "password"

void setup() {
  //attivo la seriale
  Serial.begin(115200);
  delay(1000);
  Serial.println("Simple WiFi Client");

  //avvio la connessione alla rete WiFi
  WiFi.begin(MY_WIFI_SSID, MY_WIFI_PASS);
  //attendo la connessione
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nconnesso");
  //se connesso stampo l'IP che mi hanno assegnato
  Serial.print("IP: ");Serial.println(WiFi.localIP());

  delay(1000);

  //creo un client per le operazioni di rete
  WiFiClient client;
  //il client si collega al server
  if (!client.connect("www.zeppelinmaker.it", 80)) {
    Serial.println("non connesso");
    while(true);
  } else {
    //se connesso chiede una pagina in GET
    client.println("GET /helloworld.txt HTTP/1.1");
    client.println("Host: www.zeppelinmaker.it");
    client.println("Connection: close");
    client.println("");

    //attendo la risposta del server creando un timeout
    unsigned long t1 = millis();
    //se il server non risponde entro 5 sec, interrompo la connessione
    while (client.available() == 0) {
      if ((millis() - t1) > 5000) {
         Serial.println("timeout");
         client.stop();
         while(true);
      }
    }
    
    //ricezione dati 
    while (client.available()) {
      //leggo una linea per volta e la stampo
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
    //chiudo la connessione
    client.stop(); 
  }
  //mi disconnetto dal WiFi
  WiFi.disconnect();
}

void loop() {}
