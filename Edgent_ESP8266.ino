#define BLYNK_TEMPLATE_ID "TMPLWPuirELG"
#define BLYNK_TEMPLATE_NAME "air"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"

#include <OneWire.h>
#include <DallasTemperature.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <Arduino.h>
#include <IRutils.h>
#define LED D0
int countT = 25;
int fanSP = 5;

const uint16_t kIrLed = D5;
IRsend irsend(kIrLed);

const int SENSOR_PIN = D1; 

OneWire oneWire(SENSOR_PIN);         
DallasTemperature sensors(&oneWire); 

float tempCelsius;    
float tempFahrenheit; 

void reconnectBlynk()
{
  if (!Blynk.connected())
  {Serial.println("lost connection");
    if (Blynk.connect())
    {
      Serial.println("Reconnected");
    }
    else
    {
      Serial.println("Not reconnected");
    }
  }
}
BlynkTimer timer;

void setup()
{
  irsend.begin();

#if ESP8266
  Serial.begin(115200, SERIAL_8N1,SERIAL_TX_ONLY);
#else 
  Serial.begin(115200, SERIAL_8N1);
#endif
  
  Serial.begin(115200);
  sensors.begin();    
  

  pinMode(LED, OUTPUT);
  digitalWrite(LED,LOW);
  Blynk.virtualWrite(V0, LOW);
  countT = 25;
  fanSP = 5;
  Blynk.virtualWrite(V10, "SpeedFAN:Auto");
  Blynk.virtualWrite(V11,"25 C");
  delay(3000);
  BlynkEdgent.begin();
}

void loop() {
  timer.run();
  BlynkEdgent.run();
  sensors.requestTemperatures();             
  tempCelsius = sensors.getTempCByIndex(0);  
  tempFahrenheit = tempCelsius * 9 / 5 + 32; 
   
  Serial.print("Temperature: ");
  Serial.print(tempCelsius);    
  Serial.print("°C");
  Serial.print("  ~  ");        
  Serial.print(tempFahrenheit);
  Serial.println("°F");

  Blynk.virtualWrite(V1,tempCelsius);
  Blynk.virtualWrite(V2,tempFahrenheit);

  if (Blynk.connected())
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
  }
  //buttom//
 
  
}
BLYNK_WRITE(V0)
 {
  
  int Butt_On = param.asInt();
  Serial.print(Butt_On);
  if (Butt_On == 1)
  {
    irsend.sendCOOLIX(0xB2BFD0);
    Serial.println("power on");
  }
  if (Butt_On != 1)
  {
    irsend.sendCOOLIX(0xB27BE0);
    Serial.println("power off");
  }
  delay(200);
 }
 BLYNK_WRITE(V6)
 {
  
  int up = param.asInt();
  Serial.println(up);
  if (up == 1)
  {
    Serial.println(countT += 1);
    switch (countT)
    {
      case 20:
        {
          irsend.sendCOOLIX(0xB2BF20);
          Blynk.virtualWrite(V11,"20C");
          break;
        }
        case 21:
        {
          irsend.sendCOOLIX(0xB2BF60);
          Blynk.virtualWrite(V11,"21C");
          break;
        }
        case 22:
        {
          irsend.sendCOOLIX(0xB2BF70);
          Blynk.virtualWrite(V11,"22C");
          break;
        }
        case 23:
        {
          irsend.sendCOOLIX(0xB2BF50);
          Blynk.virtualWrite(V11,"23C");
          break;
        }
        case 24:
        {
          irsend.sendCOOLIX(0xB2BF40);
          Blynk.virtualWrite(V11,"24C");
          break;
        }
        case 25:
        {
          irsend.sendCOOLIX(0xB2BFC0);
          Blynk.virtualWrite(V11,"25C");
          break;
        }
        case 26:
        {
          irsend.sendCOOLIX(0xB2BFD0);
          Blynk.virtualWrite(V11,"26C");
          break;
        }
        case 27:
        {
          irsend.sendCOOLIX(0xB2BF90);
          Blynk.virtualWrite(V11,"27C");
          break;
        }
        case 28:
        {
          irsend.sendCOOLIX(0xB2BF80);
          Blynk.virtualWrite(V11,"28C");
          break;
        }
        case 29:
        {
          irsend.sendCOOLIX(0xB2BFA0);
          Blynk.virtualWrite(V11,"29C");
          break;
        }
        case 30:
        {
          irsend.sendCOOLIX(0xB2BFB0);
          Blynk.virtualWrite(V11,"30C");
          break;
        }
    }
    if (countT>30)
    {
      countT = 30;
    }
    else
    {
      //
    }
  }
  else
  {
    //
  }
  delay(200);
 }
BLYNK_WRITE(V7)
{
  
   int down = param.asInt();
   Serial.println(down);
   if (down ==1)
   {
    Serial.println(countT -=1);
    switch (countT)
    {
      case 20:
        {
          irsend.sendCOOLIX(0xB2BF20);
          Blynk.virtualWrite(V11,"20C");
          break;
        }
      case 21:
        {
          irsend.sendCOOLIX(0xB2BF60);
          Blynk.virtualWrite(V11,"21C");
          break;
        }
      case 22:
        {
          irsend.sendCOOLIX(0xB2BF70);
          Blynk.virtualWrite(V11,"22C");
          break;
        }
      case 23:
        {
          irsend.sendCOOLIX(0xB2BF50);
          Blynk.virtualWrite(V11,"23C");
          break;
        }
      case 24:
        {
          irsend.sendCOOLIX(0xB2BF40);
          Blynk.virtualWrite(V11,"24C");
          break;
        }
      case 25:
        {
          irsend.sendCOOLIX(0xB2BFC0);
          Blynk.virtualWrite(V11,"25C");
          break;
        }
      case 26:
        {
          irsend.sendCOOLIX(0xB2BFD0);
          Blynk.virtualWrite(V11,"26C");
          break;
        }
      case 27:
        {
          irsend.sendCOOLIX(0xB2BF90);
          Blynk.virtualWrite(V11,"27C");
          break;
        }
      case 28:
        {
          irsend.sendCOOLIX(0xB2BF80);
          Blynk.virtualWrite(V11,"28C");
          break;
        }
      case 29:
        {
          irsend.sendCOOLIX(0xB2BFA0);
          Blynk.virtualWrite(V11,"29C");
          break;
        } 
      case 30:
        {
          irsend.sendCOOLIX(0xB2BFB0);
          Blynk.virtualWrite(V11,"30C");
          break;
        }
    }
    if (countT<=19)
    {
      countT = 20;
    }
    else
    {
      //d//
    }
  }
  else
  {
    //d//
  }
  delay(200);
 }
