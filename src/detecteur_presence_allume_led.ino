// définition des broches utilisées 
int trig_presence = 12; 
int echo = 11; 

// stocker les distances
long lecture_echo; 
long cm;

// Entrées des leds
int led_presence1 = 25;
int led_presence2 = 26;
 
void setup() 
{ 
  // initialisation des sorties
  pinMode(trig_presence, OUTPUT); 
  pinMode(led_presence1, OUTPUT);
  pinMode(led_presence2, OUTPUT);
  
  // on met en etat éteint les composants
  digitalWrite(led_presence1, LOW);
  digitalWrite(led_presence2, LOW);
  digitalWrite(trig_presence, LOW);
  
  Serial.begin(9600); 
}
 
void loop() 
{ 
  digitalWrite(trig_presence, HIGH); 
  delayMicroseconds(10); // envoi d'une impulsion sur trig de 10 microsecondes
  digitalWrite(trig_presence, LOW); 
  lecture_echo = pulseIn(echo, HIGH); 
  cm = lecture_echo / 58; // lecture_echo*340/(2*10000)
  
  // Si on détecte une présence on allume les leds
  if(cm > 0 && cm < 40){
    digitalWrite(led_presence1, HIGH);
    digitalWrite(led_presence2, HIGH);
    delay(500);
  } else {
    digitalWrite(led_presence1, LOW);
    digitalWrite(led_presence2, LOW);
    delay(100);
  }
  
  Serial.print("Distance en cm : "); 
  Serial.println(cm); 
  
  
}
