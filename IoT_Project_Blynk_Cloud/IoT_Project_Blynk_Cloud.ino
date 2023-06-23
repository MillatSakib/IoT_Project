


/*
            *******Some Important Resource which help's me to write this code**********
         -----------------------------------------------------------------------------------------

    The core explanation of this code: https://www.electroinvention.co.in/wifi-controlled-home-automation-using-esp8266-node-mcu/
    Link of Blynk Cloud HTTPS REST API Documentation:  https://docs.blynk.io/en/blynk.cloud/https-api-overview
    Reading virtual Pin value: https://community.blynk.cc/t/virtual-pin-reading/1185/3       &       https://forum.arduino.cc/t/reading-a-blynk-virtual-pin/507922
    Using BLYNK_WRITE() into loop():  https://community.blynk.cc/t/solved-using-blynk-write-with-loop/10369
    Programme Related helps:https://www.youtube.com/watch?v=tCeiSfuuGmY
    Switch related help: https://www.youtube.com/watch?v=psQk6hVZSAw


    API Link:Read Data stream value: https://blynk.cloud/external/api/get?token=3yj65_OKC42XbMAsbzoHicMcTb8iiXOo&v2   //light 3
Read Multiple Data Stream Value: https://blynk.cloud/external/api/get?token=3yj65_OKC42XbMAsbzoHicMcTb8iiXOo&v1&v2&v3&v4
Update Data Stream Value: https://blynk.cloud/external/api/update?token=3yj65_OKC42XbMAsbzoHicMcTb8iiXOo&v2=1
 */









//If D1,D2,D3 aren't work then select board as "NodeMcu 1.0(ESP-12E Module)" from Tools->Board.

// wifi controlled home automation using Blynk App & ESP8266

//D0 can't use as a input because it is not input pin

#define Switch1 D4 
#define Switch2 D1 
#define Switch3 D2 
#define Switch4 D3 
#define BLYNK_TEMPLATE_ID "TMPLmnbflYhu" //blynk template ID
#define BLYNK_TEMPLATE_NAME "Quickstart Template" //blynk template  name
#define BLYNK_AUTH_TOKEN "3yj65_OKC42XbMAsbzoHicMcTb8iiXOo" // enter your blynk auth token
int load1,load2,load3,load4;
#define BLYNK_PRINT Serial
#include <EEPROM.h>
#include <gpio.h>
#include <ESP8266WiFi.h>
#include <Blynk.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "T19i"; // Your Wifi Name
char pass[] = "55mEd@42"; // Your Wifi Password

void update_blynk(){
Blynk.virtualWrite(V0, load1);  
Blynk.virtualWrite(V1, load2);
Blynk.virtualWrite(V2, load3);
Blynk.virtualWrite(V3, load4);
}


//in the below code, we have set all values reverse
//For value==1, digitalWrite is "LOW" as the realy module is active "LOW" to turn device ON.
//For value==0, digitalWrite is "HIGH" as Optocoupler based relay is turned OFF when HIGH Input is given
BLYNK_WRITE(V0)
{
  load1 = param.asInt();
  Serial.println(load1);
  digitalWrite(D5, load1);
  EEPROM.write(1,load1);
  EEPROM.commit();
}
BLYNK_WRITE(V1)
{
  load2 = param.asInt();
  Serial.println(load2);
  digitalWrite(D6, load2);
  EEPROM.write(2,load2);
  EEPROM.commit();
}
BLYNK_WRITE(V2)
{
  load3 = param.asInt();
  Serial.println(load3);
  digitalWrite(D7, load3);
  EEPROM.write(3,load3);
  EEPROM.commit();
}
BLYNK_WRITE(V3)
{
  load4 = param.asInt();
  Serial.println(load4);
  digitalWrite(D8, load4);
  EEPROM.write(4,load4);
  EEPROM.commit();
}



void switchcntrl(){
     
    if(digitalRead(Switch1) == 0){
      load1 = !load1;
      digitalWrite(D5, load1);
      EEPROM.write(1,load1);
      EEPROM.commit();
      update_blynk();
      delay(1000); 
    }
    if(digitalRead(Switch2) == 0){
      load2 = !load2;
      digitalWrite(D6, load2);
      EEPROM.write(2,load2);
      EEPROM.commit();
      update_blynk();
      delay(1000); 
    }
    if(digitalRead(Switch3) == 0){
      load3 = !load3;
      digitalWrite(D7, load3);
      EEPROM.write(3,load3);
      EEPROM.commit();
      update_blynk();
      delay(1000); 
    }
    if(digitalRead(Switch4) == 0){
      load4 = !load4;
      digitalWrite(D8, load4);
      EEPROM.write(4,load4);
      EEPROM.commit();
      update_blynk();
      delay(1000); 
    }
}


void setup()
{
  Serial.begin(9600);
  EEPROM.begin(512);
  Blynk.begin(auth, ssid, pass);
  pinMode(Switch1, INPUT_PULLUP);
  pinMode(Switch2, INPUT_PULLUP);
  pinMode(Switch3, INPUT_PULLUP);
  pinMode(Switch4, INPUT_PULLUP);
  pinMode(D0,OUTPUT);
  pinMode(D5, OUTPUT); 
  pinMode(D6, OUTPUT); 
  pinMode(D7, OUTPUT); 
  pinMode(D8, OUTPUT);
  load1=EEPROM.read(1);
  digitalWrite(D5, load1);
  load2=EEPROM.read(2);
  digitalWrite(D6, load2);
  load3=EEPROM.read(3);
  digitalWrite(D7, load3);
  load4=EEPROM.read(4);
  digitalWrite(D8, load4);
  update_blynk();
}

void loop()
{
  Blynk.run();
  if((digitalRead(Switch1) && digitalRead(Switch2) && digitalRead(Switch3) && digitalRead(Switch4))==0){
  switchcntrl();
  Serial.println(digitalRead(Switch1));
  Serial.println(digitalRead(Switch2));
  Serial.println(digitalRead(Switch3));
  Serial.println(digitalRead(Switch4));
  }

  //if blynk couldn't connect
  if(!Blynk.connected()){
    digitalWrite(D0,HIGH);
    for(;Blynk.connected()==0;){
      Blynk.run();
      if((digitalRead(Switch1) && digitalRead(Switch2) && digitalRead(Switch3) && digitalRead(Switch4))==0){
  switchcntrl();
  Serial.println(digitalRead(Switch1));
  Serial.println(digitalRead(Switch2));
  Serial.println(digitalRead(Switch3));
  Serial.println(digitalRead(Switch4));
  
    }
   }
   update_blynk();
  }
  else{
    digitalWrite(D0,LOW);
  }
  
}
