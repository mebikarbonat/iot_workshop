//Muhammad Azizi Mohd Ariffin
//mazizi@tmsk.uitm.edu.my
//LED Blink and Push Button Non-Blocking

#define pushButton D0
#define led1 D1
#define led2 D2

int ledState = LOW;        
long previousMillis = 0;
long interval = 1000; //berapa lama nak tunggu

void setup() 
{
  pinMode(pushButton, INPUT); //Initialized PushButton
  pinMode(led1, OUTPUT); //Initialized LED1
  pinMode(led2, OUTPUT); //Initialized LED2
}
void loop() 
{
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;   

    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
 
    digitalWrite(led1, ledState);
  }

  if(digitalRead(pushButton) == HIGH)
  {
    digitalWrite(led2, HIGH);
  }
  else
  {
    digitalWrite(led2, LOW);
  }
}
