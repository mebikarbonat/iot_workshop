//Muhammad Azizi Mohd Ariffin
//mazizi@tmsk.uitm.edu.my
//DHT11 Sensor non_blocking

#include "DHT.h"

#define DHTTYPE DHT11
uint8_t DHTPin = D4; 

DHT dht(DHTPin, DHTTYPE);

float Temperature;
float Humidity;

long previousMillis = 0; 
long interval = 1000; 

void setup() 
{
  Serial.begin(9600);
  pinMode(DHTPin, INPUT);
  dht.begin();
}

void loop()
{

  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval)
  {

   previousMillis = currentMillis;
   Temperature = dht.readTemperature();
   Humidity = dht.readHumidity();

   Serial.print("Temperature: ");
   Serial.println(Temperature);
   Serial.print("Humidity: ");
   Serial.println(Humidity);
  }
  
  
}
