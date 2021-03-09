//Muhammad Azizi Mohd Ariffin
//mazizi@tmsk.uitm.edu.my
//LM35 Analog Sensor non_blocking

long previousMillis = 0; 
long interval = 1000; 

#define led1 D0

void setup() 
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
}
void loop() 
{
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis > interval)
  {
  previousMillis = currentMillis;
  int Dout = analogRead(A0);
  float Vin = (Dout*0.00488);
  float temp = Vin*100;
  Serial.println(temp);

  if(temp >= 50.0)
  {
    digitalWrite(led1, HIGH);
  }
  else
  {
    digitalWrite(led1, LOW);
  }
  
  }
}
