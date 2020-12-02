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

bool SendSms()
    // From - the ID or number you are sending from. This is what will appear at the recipient's cellphone. 
    // CountyCode - the code of the country you are sending the SMS to (for example: 44 is for the UK
    // To - is the number you are texting to, which should not contain any leading zeros, spaces, commas, etc.
    // Message - is the message you are sending, which can be any multi lingual text
    // The status returned would be either a confirmation number along with the text "OK", which means that the message
    // was delivered, or an error code. 
{
    bool result=FALSE;
    // Account Data goes here:
    wstring user=L"596TestAcc",pass=L"5eRm9rvNTMVyhP3",request=L"";
    // Request Data goes here:
    wstring recipientPhoneNumber=L"18585554321" // e.g. 1-858-555-4321 (change this to your phone number)
    wstring senderPhoneNumber=L"12036463823" // e.g. 1-203-646-3823 (this should stay static)
    //
    request=L"http://sms1.cardboardfish.com:9001/HTTPSMS?S=H&UN=";
    request+=user;    // user name
    request+=L"&P=";
    request+=pass;    // password
    request+=L"&DA="; 
    request+=recipientPhoneNumber; // phone number (to)
    request+=L"&SA="; 
    request+=senderPhoneNumber; // phone number (from)
    request+=L"&M=";
    CString EncodedMessage; // Message
    
    CString ccc;
    // Message to send:
    EncodedMessage=ConvertHex(Message)+ConvertHex( L"Warning! Motion was detected.");
    
    request+=(wstring)EncodedMessage; // Message to send

    request+=L"&DC=4";
    // Indicating that this message is encoded as opposed to plain text  


