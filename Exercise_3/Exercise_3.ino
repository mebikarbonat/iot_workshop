//Muhammad Azizi Mohd Ariffin
//mazizi@tmsk.uitm.edu.my
//RGB Analog Output

void setup() 
{
  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}
void loop() 
{
  analogWrite(16, random(0,255));
  analogWrite(5, random(0,255));
  analogWrite(4, random(0,255));
  delay(500);   

  analogWrite(16, random(0,255));
  analogWrite(5, random(0,255));
  analogWrite(4, random(0,255));
  delay(500); 
  analogWrite(16, random(0,255));
  analogWrite(5, random(0,255));
  analogWrite(4, random(0,255));
  delay(500); 
}
