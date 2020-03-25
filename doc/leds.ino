int led =11;

void setup() {
  pinMode (2, OUTPUT) ;
  pinMode (3, OUTPUT) ;
  pinMode (4, OUTPUT) ;
  pinMode (5, OUTPUT) ;
}

void loop() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);

  delay(500);
  
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  
}


/*
// Initialisation des lignes 4 à 9 en sortie
void setup () {
  pinMode (2, OUTPUT) ;
  pinMode (3, OUTPUT) ;
  pinMode (4, OUTPUT) ;
  pinMode (5, OUTPUT) ;
}
 
// Fonction loop
void loop () {
  // Extinction de toutes les DEL au départ du programme
  for (byte i = 2 ; i <= 5 ; i++) {
    digitalWrite (i, LOW) ; // éteint la DEL reliée à la broche i
  }
 
  // Boucle pour faire flasher les DEL
  for (byte i = 2 ; i <= 5 ; i++) {
    digitalWrite (i, HIGH) ; // allume la DEL sur broche i
    delay (50) ; // durée du flash 50 millisecondes
    digitalWrite (i, LOW) ; // éteint la DEL
  }
 
  // délai de 500 millisecondes
  delay (500) ;
 
  // Recommence la séquence
}
*/
