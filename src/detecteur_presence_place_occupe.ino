// définition des broches utilisées 
int trig_place1 = 34; 
int echo_place1 = 35;

int trig_place2 = 14; 
int echo_place2 = 12; 

int trig_place3 = 16; 
int echo_place3 = 17; 

int trig_place4 = 19; 
int echo_place4 = 18; 

// stocker les distances
long lecture_echo_place1; // durée aller-retour du signal
long lecture_echo_place2;
long lecture_echo_place3;
long lecture_echo_place4;
long cm_place1;
long cm_place2;
long cm_place3;
long cm_place4;

// Entrées des leds
int led_voiture_place1 = 32;
int led_voiture_place2 = 33;
int led_voiture_place3 = 15;
int led_voiture_place4 = 13;

void setup() 
{ 
  // initialisation des sorties
  pinMode(trig_place1, OUTPUT); 
  pinMode(trig_place2, OUTPUT); 
  pinMode(trig_place3, OUTPUT); 
  pinMode(trig_place4, OUTPUT);
  pinMode(led_voiture_place1, OUTPUT);
  pinMode(led_voiture_place2, OUTPUT);
  pinMode(led_voiture_place3, OUTPUT);
  pinMode(led_voiture_place4, OUTPUT);
  
  // on met en etat éteint les composants
  digitalWrite(trig_place1, LOW);
  digitalWrite(trig_place2, LOW);
  digitalWrite(trig_place3, LOW);
  digitalWrite(trig_place4, LOW);
  digitalWrite(led_voiture_place1, LOW);
  digitalWrite(led_voiture_place2, LOW);
  digitalWrite(led_voiture_place3, LOW);
  digitalWrite(led_voiture_place4, LOW);
  
  // initialisation des entrées
  pinMode(echo_place1, INPUT);
  pinMode(echo_place2, INPUT); 
  pinMode(echo_place3, INPUT);
  pinMode(echo_place4, INPUT); 
  
  Serial.begin(9600); 
}
 
void loop() 
{ 
  
  // On démarre le signal
  demarre_trig(trig_place1);
  demarre_trig(trig_place2);
  demarre_trig(trig_place3);
  demarre_trig(trig_place4);
  
  // Calcul des distances 
  cm_place1 = calcul_distance(echo_place1);
  cm_place2 = calcul_distance(echo_place2);
  cm_place3 = calcul_distance(echo_place3);
  cm_place4 = calcul_distance(echo_place4);
  
  // Si on détecte une présence on allume les leds
  detecter_presence(cm_place1,led_voiture_place1);
  detecter_presence(cm_place2,led_voiture_place2);
  detecter_presence(cm_place3,led_voiture_place3);
  detecter_presence(cm_place4,led_voiture_place4);
  
}

void demarre_trig(int trig_place){
  digitalWrite(trig_place, HIGH); // on démarre le signal
  delayMicroseconds(10); // durée trig de 10 microsecondes
  digitalWrite(trig_place, LOW); // on stop le signal
}

long calcul_distance(int echo_place){
  long cm_place;
  long lecture_echo_place;
  lecture_echo_place = pulseIn(echo_place, HIGH); // met la durée de l'impulsion de niveau high dans la variable
  cm_place = lecture_echo_place / 58; // lecture_echo*340/(2*10000) // on convertit en cm la durée 
  return cm_place;
}

void detecter_presence(long cm_place, int led_voiture_place){
  // Si on détecte une présence on allume les leds
  if(cm_place > 0 && cm_place < 5){
    digitalWrite(led_voiture_place, HIGH);
    delay(100);
  } else { 
    digitalWrite(led_voiture_place, LOW);
    delay(100);
  }
}
