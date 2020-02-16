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
