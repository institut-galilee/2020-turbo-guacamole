## **Exercice 2**
Dans cette exercice nous devions changer la fréquence(son) émise par le buzzer passif suite à une valeur entré

Matériels :
  - Arduino
  - Câbles
  - Breadboard
  - Buzzer passif

### Pour le code du changement de fréquence nous avons :
```
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
```
![buzzer_passif](https://user-images.githubusercontent.com/60176240/74606658-96b4b180-50d2-11ea-8567-a41a4eb944d4.jpeg)

![sketch_buzzer](https://user-images.githubusercontent.com/60176240/74606667-a8965480-50d2-11ea-9f5f-8c96bab08b3b.png)

![schematic_buzzer](https://user-images.githubusercontent.com/60176240/74606676-b2b85300-50d2-11ea-969d-ac24c744c3b7.png)


### Pour le code du capteur LDR nous avons :
Dans cette exercice nous devions envoyé les données capté par le capteur LDR à notre ordinateur

Matériels :
  - Arduino
  - Câbles
  - Breadboard
  - Capteur LDR
  - Résistance
  
### Pour le code du capteur LDR nous avons :
```
int analogInPin = A0;  // Analog input pin LDR

int sensorValue = 0; // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);  // Start serial Serial at 9600 baud
}

void loop() {
  sensorValue = analogRead(analogInPin);  // read the value from the sensor
  Serial.println(sensorValue);            //prints the values coming from the sensor 
  delay(500);                             // spacing the time between the different values coming from the sensor
}
```
![capteur_ldr](https://user-images.githubusercontent.com/60176240/74606772-66214780-50d3-11ea-99c6-d18dd4c3f96f.jpeg)

![sketch_ldr](https://user-images.githubusercontent.com/60176240/74606788-805b2580-50d3-11ea-981c-2596e702ffd6.jpeg)

![schematic_ldr](https://user-images.githubusercontent.com/60176240/74606799-8e10ab00-50d3-11ea-86ed-7eabaae95ab1.jpeg)


