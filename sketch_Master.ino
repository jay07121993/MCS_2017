#include <Wire.h>

void setup()
{
  Wire.begin(0);   
  Serial.begin(9600);             
}
int x=10;
int y=80;

void loop()
{
  while(Serial.available())
  {
    char z = Serial.read();
  switch(z){
    case '+' :
    Serial.println("Addition carried out by Slave 1");
    break;
    case '*':
    Serial.println("Multiplication carried out by Slave 2");
    break;
    case '-':
    Serial.println("Subtraction carried out by Slave 3");
    break;
    case '(':
    Serial.println("Maximum of two nos carried out by Slave 4");
    break;
    case ')':
    Serial.println("Minimum of two nos carried out by Slave 5");
    break;
  }
  }
  delay(500);

 
 Wire.beginTransmission(2);
  Wire.write(x); 
  Wire.write(y);
Wire.endTransmission();
Wire.beginTransmission(3);
  Wire.write(x); 
  Wire.write(y);
Wire.endTransmission();
Wire.beginTransmission(4);
  Wire.write(x); 
  Wire.write(y);
Wire.endTransmission();
Wire.beginTransmission(5);
  Wire.write(x); 
  Wire.write(y);
Wire.endTransmission();
Wire.beginTransmission(6);
  Wire.write(x); 
  Wire.write(y);
Wire.endTransmission();

Wire.requestFrom(2,17);
while(Wire.available())
{ 
  char c = Wire.read();
  Serial.print(c);
}
Wire.requestFrom(3,17);
while(Wire.available())
{ 
  char d = Wire.read();
  Serial.print(d);
}
Wire.requestFrom(4,17);
while(Wire.available())
{ 
  char e = Wire.read();
  Serial.print(e);
}
Wire.requestFrom(5,17);
while(Wire.available())
{ 
  char f = Wire.read();
  Serial.print(f);
}
Wire.requestFrom(6,17);
while(Wire.available())
{ 
  char g = Wire.read();
  Serial.print(g);
 }
delay(5500);
}                  
