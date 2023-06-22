

/*
            *******Some Important Resource which help's me to write this code**********
         -----------------------------------------------------------------------------------------

    The core explanation of this code: https://www.electroinvention.co.in/wifi-controlled-home-automation-using-esp8266-node-mcu/
    Link of Blynk Cloud HTTPS REST API Documentation:  https://docs.blynk.io/en/blynk.cloud/https-api-overview
    Reading virtual Pin value: https://community.blynk.cc/t/virtual-pin-reading/1185/3       &       https://forum.arduino.cc/t/reading-a-blynk-virtual-pin/507922
    Using BLYNK_WRITE() into loop():  https://community.blynk.cc/t/solved-using-blynk-write-with-loop/10369
    
 */









//If D1,D2,D3 aren't work then select board as "NodeMcu 1.0(ESP-12E Module)" from Tools->Board.

// wifi controlled home automation using Blynk App & ESP8266



#define BLYNK_TEMPLATE_ID "TMPLmnbflYhu" //blynk template ID
#define BLYNK_TEMPLATE_NAME "Quickstart Template" //blynk template  name
#define BLYNK_AUTH_TOKEN "3yj65_OKC42XbMAsbzoHicMcTb8iiXOo" // enter your blynk auth token

#define BLYNK_PRINT Serial
#include <gpio.h>
#include <ESP8266WiFi.h>
#include <Blynk.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Millat"; // Your Wifi Name
char pass[] = "12345678"; // Your Wifi Password

//in the below code, we have set all values reverse
//For value==1, digitalWrite is "LOW" as the realy module is active "LOW" to turn device ON.
//For value==0, digitalWrite is "HIGH" as Optocoupler based relay is turned OFF when HIGH Input is given
BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if (value == 1)
  {
    digitalWrite(D0, LOW);
    Serial.println("LED ON"); //Setting Digital PIN as LOW to turn ON Device if relay module is "active low"
  }
  if (value == 0)
  {
    digitalWrite(D0, HIGH);
    Serial.println("LED OFF");//Setting Digital PIN as HIGH to turn OFF Device if relay module is "active low"
  }
}

BLYNK_WRITE(V2)
{
  int value = param.asInt();
  Serial.println(value);
  if (value == 1)
  {
    digitalWrite(D1, LOW);
    Serial.println("LED ON");
  }
  if (value == 0)
  {
    digitalWrite(D1, HIGH);
    Serial.println("LED OFF");
  }
}

BLYNK_WRITE(V3)
{
  int value = param.asInt();
  Serial.println(value);
  if (value == 1)
  {
    digitalWrite(D2, LOW);
    Serial.println("LED ON");
  }
  if (value == 0)
  {
    digitalWrite(D2, HIGH);
    Serial.println("LED OFF");
  }
}

BLYNK_WRITE(V4)
{
  int value = param.asInt();
  Serial.println(value);
  if (value == 1)
  {
    digitalWrite(D3, LOW);
    Serial.println("LED ON");
  }
  if (value == 0)
  {
    digitalWrite(D3, HIGH);
    Serial.println("LED OFF");
  }
}


void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(D0, OUTPUT); //GPIO 16 (equivalent to PIN 16 of Arduino)
  pinMode(D1, OUTPUT); //GPIO 05 (equivalent to PIN 05 of Arduino)
  pinMode(D2, OUTPUT); //GPIO 04 (equivalent to PIN 16 of Arduino)
  pinMode(D3, OUTPUT); //GPIO 00 (equivalent to PIN 00 of Arduino)
}

void loop()
{
  Blynk.run();
}
