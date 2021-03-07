//Muhammad Azizi Mohd Ariffin
//mazizi@tmsk.uitm.edu.my
//LM35 Analog Sensor non_blocking

long previousMillis = 0; 
long interval = 1000; 

void setup() 
{
  Serial.begin(9600);
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
  }
}
