## **Exercice 1**

Dans cette exercice nous devions allumer une led avec et sans microcontrôleur.

Matériels :
  - LED
  - Résistance
  - Arduino
  - Câbles
  - Breadboard
### **- Sans microcontrôleur**

![github-small](https://github.com/institut-galilee/2020-turbo-guacamole/blob/master/lab/1/Exercice/1/img/ex1.1.jpeg)


### **- Avec microcontrôleur**

Pour cette partie, nous avons écris un code qui fait clignoter la led.

```C
int led =11;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
  digitalWrite(led, HIGH);
  delay(1000);
}
```

![github-small](https://github.com/institut-galilee/2020-turbo-guacamole/blob/master/lab/1/Exercice/1/img/ex1.2_allume_clignote.jpg)

![github-small](https://github.com/institut-galilee/2020-turbo-guacamole/blob/master/lab/1/Exercice/1/img/ex1.2_eteint_clignote.jpg)


### **Conclusion**

La différence est qu'avec l'utilisation d'un microcontrôleur, il est possible de régler la luminosité de la led, alors que sans microcontrôleur il est seulement possible d'allumer ou d'éteindre la led. Avec le microcontrôleur nous pouvons faire clignoter la led par exemple.
