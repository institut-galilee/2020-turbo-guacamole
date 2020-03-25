/* Utilisation du capteur Ultrason HC-SR04 */
 
// définition des broches utilisées 
int trig = 12; 
int echo = 11; 
long lecture_echo; 
long cm;
 
void setup() 
{ 
  pinMode(trig, OUTPUT); 
  digitalWrite(trig, LOW); 
  pinMode(echo, INPUT); 
  Serial.begin(9600); 
}
 
void loop() 
{ 
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); // envoi d'une impulsion sur trig de 10 microsecondes
  digitalWrite(trig, LOW); 
  lecture_echo = pulseIn(echo, HIGH); 
  cm = lecture_echo / 58; // lecture_echo*340/(2*10000)
  Serial.print("Distance en cm : "); 
  Serial.println(cm); 
  delay(1000); 
}
