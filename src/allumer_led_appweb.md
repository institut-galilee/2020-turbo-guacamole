```C
#include <WiFi.h>

// Remplacer "" par son réseau, nom et mot de passe de son réseau
const char* ssid = "";
const char* password = "";

// Entrées des leds
int led1 = 25;
int led2 = 26;
int led3 = 27;

// On initialise les états des leds a off au début
String etat_led1 = "off";
String etat_led2 = "off";
String etat_led3 = "off";

// Port pour le serveur web
WiFiServer server(80);

// Stocker la requette HTTP
String header;

void setup() {
  Serial.begin(115200);
  
  // initialisation des sorties des leds
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  // on met les leds en éteinte
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  
  // Connexion wifi
  Serial.print("Connexion à ");
  Serial.println(ssid);
	WiFi.begin(ssid, password);
	
	while(WiFi.status() != WL_CONNECTED)
	{
	  delay(500);
		Serial.print(".");	
	}
	
	Serial.println("Connexion etablie");
	Serial.print("Adresse IP: ");
	Serial.println(WiFi.localIP()); // On utilise pour se connecter a l'application
	
	// Démmarrage du serveur.
  server.begin();
}

void loop() {
  // On vérifie si un client se connecte
  WiFiClient client = server.available();
  
  if (client) {
    Serial.println("Nouveau client");
    while (client.connected()) {            
      if (client.available()) { // On vérifie si le client a envoyé une requete            
        char c = client.read();             
        Serial.write(c);                    
        header += c;
         if (c == '\n') {   
          // Fin de la requette HTTP du client
          if (currentLine.length() == 0) {
            // HTTP headers 
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // Allumer et eteindre leds
            if (header.indexOf("GET /1/on") >= 0) {
              Serial.println("led 1 on");
              etat_led1 = "on";
              digitalWrite(led1, HIGH);
            } else if (header.indexOf("GET /1/off") >= 0) {
              Serial.println("led 1 off");
              etat_led1 = "off";
              digitalWrite(led1, LOW);
            } else if (header.indexOf("GET /2/on") >= 0) {
              Serial.println("led 2 on");
              etat_led2 = "on";
              digitalWrite(led2, HIGH);
            } else if (header.indexOf("GET /2/off") >= 0) {
              Serial.println("led 2 off");
              etat_led2 = "off";
              digitalWrite(led2, LOW);
            } else if (header.indexOf("GET /3/on") >= 0) {
              Serial.println("led 3 on");
              etat_led3 = "on";
              digitalWrite(led3, HIGH);
            } else if (header.indexOf("GET /3/off") >= 0) {
              Serial.println("led 3 off");
              etat_led3 = "off";
              digitalWrite(led3, LOW);
            }
          
          
            // Affichage de la page html
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<script src=\"https://kit.fontawesome.com/a076d05399.js\"></script>");
            client.println("<script src=\"https://code.jquery.com/jquery-3.2.1.slim.min.js\" integrity=\"sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN\"></script>");
            client.println("<script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.11.0/umd/popper.min.js\" integrity=\"sha384-b/U6ypiBEHpOf/4+1nzFpr53nxSS+GLCkfwBdFNTxtclqqenISfwAzpKaMNFNmj4\"></script>");
            client.println("<script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/js/bootstrap.min.js\" integrity=\"sha384-h0AbiXch4ZDo7tp9hKZ4TsHbi047NrKGLO3SEJAg45jXxnGIfYzk4Si90RDIqNm1\"></script>");
            
            // CSS
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            client.println("<body><h4>Gestion des fonctionalités</h4>");
            
            client.println("<div  class=\"row justify-content-center no-gutters outer-div\">");
            
              // On vérifie l'état des leds 
              client.println("<div  class=\"col-xs-6 col-sm-6 col-md-6 col-lg-6 justify-content-center inner-div\">");
                client.println("<p>Etat Led 1 : " + etat_led1 + "</p>");      
                if (etat_led1=="off") {
                  client.println("<p><a href=\"/1/on\"><button class=\"button\">ON</button></a></p>");
                } else {
                  client.println("<p><a href=\"/1/off\"><button type=\"button\" class=\"btn btn-info col-xs-6 col-sm-6 col-md-6 col-lg-6 button2\">OFF</button></a></p>");
                } 
              client.println("</div>");
            
              // On vérifie l'état des leds
              client.println("<div  class=\"col-xs-6 col-sm-6 col-md-6 col-lg-6 inner-div"\>");
                client.println("<p>Etat Led 2 : " + etat_led2 + "</p>");      
                if (etat_led2=="off") {
                  client.println("<p><a href=\"/2/on\"><button type=\"button\" class=\"btn btn-info col-xs-6 col-sm-6 col-md-6 col-lg-6\">ON</button></a></p>");
                } else {
                  client.println("<p><a href=\"/2/off\"><button type=\"button\" class=\"btn btn-info col-xs-6 col-sm-6 col-md-6 col-lg-6 button2\">OFF</button></a></p>");
                } 
              client.println("</div>");
            
            
              // On vérifie l'état des leds
              client.println("<div  class=\"col-xs-6 col-sm-6 col-md-6 col-lg-6 inner-div"\>");
                client.println("<p>Etat Led 3 : " + etat_led3 + "</p>");      
                if (etat_led3=="off") {
                  client.println("<p><a href=\"/3/on\"><button type=\"button\" class=\"btn btn-info col-xs-6 col-sm-6 col-md-6 col-lg-6\">ON</button></a></p>");
                } else {
                  client.println("<p><a href=\"/3/off\"><button type=\"button\" class=\"btn btn-info col-xs-6 col-sm-6 col-md-6 col-lg-6 button2\">OFF</button></a></p>");
                } 
              client.println("</div>");
            client.println("</div>");
            
            client.println("</body></html>");
            
            client.println();
            
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {  // on vérifie si il n'y est pas de retour a la ligne
          currentLine += c;
        }
      }
    }
    // On met le header a vide
    header = "";
  
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
    
}

```
