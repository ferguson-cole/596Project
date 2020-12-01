#include "Arduino.h"
#include <ESP8266WiFi.h>

#define SENSOR_PIN  D2

int sensorVal = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT); //Sensor input

//   WiFi.begin("DANGER","TRASH0707");
//   Serial.print("Connecting...");

//   while (WiFi.status() != WL_CONNECTED)
//   {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println();

//   Serial.print("Connected, IP address: ");
//   Serial.println(WiFi.localIP());
}

void loop() {
  sensorVal = digitalRead(SENSOR_PIN);

  if (sensorVal == HIGH){
    Serial.println("MOTION DETECTED");
    delay(500);
  }

  else if (sensorVal == LOW){
    Serial.println("Nothing...");
    delay(500);
  }
}


