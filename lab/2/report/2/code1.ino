/*
TP 2 Exercice 2 
*/
#include "pitches.h" // pour utiliser la fonction tone

const byte buzzer = 13; //don't use '#define' for pin allocations. It can lead to errors. Use 'const byte'.

void setup() {
  Serial.begin(9600);  // Start serial Serial at 9600 baud
  pinMode(buzzer, OUTPUT);
}

void loop()
{
    if (Serial.available()>0)
    {
        int buzzer_freq = Serial.parseInt(); // on récupère une valeur de frequence en entrer
        //Serial.println(buzzer_freq);
        tone(buzzer, buzzer_freq); // on change la fréquence du buzzer(le son) par celui entré
    }
}
