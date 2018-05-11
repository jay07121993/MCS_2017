// --------------------Master Code for module status and Module distance-----------------------------------------//

#include <Wire.h>

//byte i2cdata[3];

void setup() {
  
  Wire.begin();
  Serial.begin(9600);

   //Distance Matrix..............................
   
  //accessing data from slave 1
   Wire.requestFrom(1, 3); //(slaves_address,no. of bytes requested)
  
  int a = Wire.available();
  
  Serial.print("Arduino - Modul 1 distance to other arduino: ");
  Serial.println(a);
    while (Wire.available()) {
    Serial.print(Wire.read());
    Serial.print(" ");
  } 

  Serial.println();
 
  delay(500);
  // accessing data from slave 2
  
  Wire.requestFrom(2, 1);
  
  int b = Wire.available();
  
  Serial.print("Arduino - Modul 2 distance to other arduino: ");
  Serial.println(b);
    while (Wire.available()) {
    Serial.print(Wire.read());
    Serial.print(" ");
  } 

  Serial.println();

  //memset(&i2cdata, 0, 3);

  delay(500);
 
  //accessing data from slave 3
  
  Wire.requestFrom(3, 2);
  
  int c = Wire.available();
  
  Serial.print("Arduino Modul 3 distance to other arduino: ");
  Serial.println(c);
  while (Wire.available()) {
    Serial.print(Wire.read());
    Serial.print(" ");
  } 

  Serial.println();

  //memset(&i2cdata, 0, 3);

  delay(500);
  //accessing data from Slave 4
  
  Wire.requestFrom(4, 4);
    
  
  int d = Wire.available();
  
  Serial.print("Arduino - Modul 4 distance to other arduino: ");
  Serial.println(d);
    while (Wire.available()) {
    Serial.print(Wire.read());
    Serial.print(" ");
  } 

  Serial.println();
  delay(500);
 
 //accessing data from Slave 5
  Wire.requestFrom(5, 3);
    
  
  int e = Wire.available();
  
  Serial.print("Arduino - Modul 5 distance to other arduino: ");
  Serial.println(e);
    while (Wire.available()) {
    Serial.print(Wire.read());
    Serial.print(" ");
  } 

  Serial.println();
delay(500);


//---------------------------Master code for module-status matrix-----------------------------------//
   //slave 1
   Wire.requestFrom(1, 6);
    
  
  int a = Wire.available();
  
  Serial.print("\nArduino 1 in line with Arduino(M) and Arduino 3: ");
  Serial.println(a);
    while (Wire.available()) {
    Serial.print(Wire.read());
    Serial.print(" ");
  } 

   //slave 2
   Wire.requestFrom(2, 6);
    
  
  int b = Wire.available();
  
  Serial.print("\nArduino 2 in line with Arduino(M) and Arduino 1 : ");
  Serial.println(b);
    while (Wire.available()) {
    Serial.print(Wire.read());
    Serial.print(" ");
  } 

  Serial.println();
 
  delay(500);

   //slave 3
   Wire.requestFrom(3, 6);
    
  
  int c = Wire.available();
  
  Serial.print("\nArduino 3 in line with Arduino(M) and Arduino 1: ");
  Serial.println(c);
    while (Wire.available()) {
    Serial.print(Wire.read());
    Serial.print(" ");
  } 

  Serial.println();
 
  delay(500);

   //slave 4
   Wire.requestFrom(4, 6);
    
  
  int d = Wire.available();
  
  Serial.print("\nArduino 4 in line with Arduino(M) and Arduino 2: ");
  Serial.println(d);
    while (Wire.available()) {
    Serial.print(Wire.read());
    Serial.print(" ");
  } 
  Serial.println();
 
  delay(500);

   //slave 5
   Wire.requestFrom(5, 6);
    
  
  int e = Wire.available();
  
  Serial.print("\nArduino 5 in line with and Arduino 1: ");
  Serial.println(e);
    while (Wire.available()) {
    Serial.print(Wire.read());
    Serial.print(" ");
  } 

  Serial.println();
 
  delay(500);
 
}

void loop() {}
