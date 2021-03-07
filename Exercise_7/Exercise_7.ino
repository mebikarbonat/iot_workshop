//Muhammad Azizi Mohd Ariffin
//mazizi@tmsk.uitm.edu.my
//Display DHT11 Sensor data via TCP Socket

#include <ESP8266WiFi.h>

#include "DHT.h"

#define DHTTYPE DHT11   // DHT 11

uint8_t DHTPin = D4; 
               
DHT dht(DHTPin, DHTTYPE);                

float Temperature;
float Humidity;

#define SendKey 0

int port = 8888;
WiFiServer server(port);

long previousMillis = 0;
long interval = 5000;

//Server connect to WiFi Network
const char *ssid = "AziSheNetwork2.4@unifi";
const char *password = "0178822437"; 

int count=0;

void setup() 
{
  Serial.begin(9600);
  //pinMode(SendKey,INPUT_PULLUP);  //Btn to send data
  Serial.println();

  pinMode(DHTPin, INPUT);
  dht.begin();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password); //Connect to wifi
 
  // Wait for connection  
  Serial.println("Connecting to Wifi");
  while (WiFi.status() != WL_CONNECTED) {   
    delay(500);
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  
  server.begin();
  Serial.print("Open Telnet and connect to IP:");
  Serial.print(WiFi.localIP());
  Serial.print(" on port ");
  Serial.println(port);
}
//=======================================================================
//                    Loop
//=======================================================================

void loop() 
{
  WiFiClient client = server.available();
  String sendToClient;
  
  if (client) {
    if(client.connected())
    {
      Serial.println("Client Connected");
    }
    
    while(client.connected()){      
      while(client.available()>0){
        // read data from the connected client
        Serial.write(client.read()); 
      }
       unsigned long currentMillis = millis();
       if(currentMillis - previousMillis > interval) {

       previousMillis = currentMillis;
       Temperature = dht.readTemperature();
       Humidity = dht.readHumidity(); 
       client.write(" Temperature:");
       sendToClient = String(Temperature);
       client.print(sendToClient);
       client.write(" Humidity:");
       sendToClient = String(Humidity);
       client.print(sendToClient);
       }
    }
    client.stop();
    Serial.println("Client disconnected");    
  }
}
//=======================================================================
