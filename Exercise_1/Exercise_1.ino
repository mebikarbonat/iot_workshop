//Muhammad Azizi Mohd Ariffin
//mazizi@tmsk.uitm.edu.my

#define pushButton D0
#define led1 D1
#define led2 D2

void setup() 
{
  pinMode(pushButton, INPUT); //Initialized PushButton
  pinMode(led1, OUTPUT); //Initialized LED1
  pinMode(led2, OUTPUT); //Initialized LED2
}
void loop() 
{
  digitalWrite(led1, HIGH); //Turn on D0
  delay(1000);
  digitalWrite(led1, LOW); //Turn off D0
  delay(1000);

  if(digitalRead(pushButton) == HIGH)
  {
    digitalWrite(led2, HIGH);
  }
  else
  {
    digitalWrite(led2, LOW);
  }
}
