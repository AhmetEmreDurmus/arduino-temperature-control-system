#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

#define LED_PIN 8
#define FAN_PIN 9

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);

  dht.begin();
}

void loop() {

  float temp = dht.readTemperature();

  Serial.print("Sicaklik: ");
  Serial.println(temp);

  
  if(temp >= 30) {
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }

  
  if(temp >= 35) {
    digitalWrite(FAN_PIN, HIGH);
  }
  else {
    digitalWrite(FAN_PIN, LOW);
  }

  delay(1000);
}