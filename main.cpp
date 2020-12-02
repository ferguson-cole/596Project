#include "Arduino.h"
#include "ESP8266WiFi.h"
#include <iostream>
#include <textmagic.h>

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

void sendNotification() {
  if (argc < 3) {
    std::cout << "********* Please enter valid login & api key *********" << std::endl;
    std::cout << ">> bin/messages_example username C7XDKZOQZo6HvhJPtO0MBcWl3qwtp2" << std::endl;
    return 1;
  }

  std::cout << "********* MessagesController example *********" << std::endl;
  Rest::RequestData vars;
  Client tm(argv[1], argv[2]);
  //******************* Send example ***********************
  std::cout << "********* MessagesController.send() *********" << std::endl;
  vars["phones"] = "999";
  vars["text"] = "The simple fake message";
  SendResultModel result = tm.Messages().send(vars);
  if (tm.Messages().isError){
    std::cout
      << tm.Messages().lastError.code << " * "
      << tm.Messages().lastError.message << " * "
      << std::endl;
    return 1;
  } else {
    std::cout
       << result.href << " * "
       << result.type  << " * "
       << result.messageId  << " * "
       << std::endl;
  }

}


