```C
#include <WiFi.h>

// Remplacer "" par son réseau, nom et mot de passe de son réseau
const char* ssid = "";
const char* password = "";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
	
  while(WiFi.status() != WL_CONNECTED)
  {
  	delay(500);
	Serial.print("Tentative de connexion");
  }
	
  Serial.println("Connexion etablie");
  Serial.print("Adresse IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
    
}
```
