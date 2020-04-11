#include <WiFi.h>
#include <Servo.h>

// Remplacer "" par son réseau, nom et mot de passe de son réseau
const char* ssid = "";
const char* password = "";

// Entrées du servo
int servoPin = 13;

// Controle du servo
Servo servo;

int pos = 0;

// On initialise les états a close au début
String etat_porte1 = "close";
String etat_porte2 = "close";

// Port pour le serveur web
WiFiServer server(80);

// Stocker la requette HTTP
String header;

void setup() {
  Serial.begin(115200);
  servo.attach(servoPin); // recupere le servo
  
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
    String currentLine = "";
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
            
            // Ouvrir et fermer porte
            if (header.indexOf("GET /p1/open") >= 0) {
              Serial.println("porte 1 open");
              etat_porte1 = "open";
              for (pos = 0; pos <= 90; pos += 1) { // on tourne jusqu'a 90 degrés 
                servo.write(pos);
                delay(10);
              }
            } else if (header.indexOf("GET /p1/close") >= 0) {
                Serial.println("porte 1 close");
                etat_porte1 = "close";
                for (pos = 90; pos >= 0; pos -= 1) { // on tourne jusqu'a 0 degrés 
                  servo.write(pos);
                  delay(10);
                }
            } else if (header.indexOf("GET /p2/open") >= 0) {
                Serial.println("porte 2 open");
                etat_porte2 = "open";
                for (pos = 0; pos <= 90; pos += 1) { // on tourne jusqu'a 90 degrés 
                  servo.write(pos);
                  delay(10);
                }
            } else if (header.indexOf("GET /p2/close") >= 0) {
                Serial.println("porte 2 close");
                etat_porte2 = "close";
                for (pos = 90; pos >= 0; pos -= 1) { // on tourne jusqu'a 0 degrés 
                  servo.write(pos);
                  delay(10);
                }
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
            
            // Position des boutons dans la div
            client.println("<div  class=\"row justify-content-center no-gutters outer-div\">");
            
              // On vérifie l'état des portes 
              client.println("<div  class=\"col-xs-6 col-sm-6 col-md-6 col-lg-6 justify-content-center inner-div\">");
                client.println("<p>Etat porte 1 : " + etat_porte1 + "</p>");      
                if (etat_porte1=="close") {
                  client.println("<p><a href=\"/p1/open\"><button class=\"button\">OPEN</button></a></p>");
                } else {
                  client.println("<p><a href=\"/p1/close\"><button type=\"button\" class=\"btn btn-info col-xs-6 col-sm-6 col-md-6 col-lg-6 button2\">CLOSE</button></a></p>");
                } 
              client.println("</div>");
              
              client.println("<div  class=\"col-xs-6 col-sm-6 col-md-6 col-lg-6 justify-content-center inner-div\">");
                client.println("<p>Etat porte 2 : " + etat_porte2 + "</p>");      
                if (etat_porte2=="close") {
                  client.println("<p><a href=\"/p2/open\"><button class=\"button\">OPEN</button></a></p>");
                } else {
                  client.println("<p><a href=\"/p2/close\"><button type=\"button\" class=\"btn btn-info col-xs-6 col-sm-6 col-md-6 col-lg-6 button2\">CLOSE</button></a></p>");
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

