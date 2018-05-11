//------------------------ Slave 1 distance Matrix--------------------------------------//
#include "RS485_protocol.h"
#include <SoftwareSerial.h>
const byte ENABLE_PIN = 2;

SoftwareSerial rs485 (10, 11); // receive pin, transmit pin boolean replay = false;

int myDistValues[5] = {0, 5, 8, 6, 3};
int i;

void setup()
{
Serial.begin(9600);
rs485.begin (28800);
pinMode (ENABLE_PIN, OUTPUT); // register event
}
void loop()
{
digitalWrite (ENABLE_PIN, LOW);
while (rs485.available())

{
char c = rs485.read();
delay(10);
if (c == '1') //1st slave ID
{
Serial.println("Sending from slave:" );
Serial.println(c);
digitalWrite (ENABLE_PIN, HIGH);
replay = true;
}
delay(600);
if (replay){
  digitalWrite (ENABLE_PIN, HIGH);//enable sending to the master 
  Serial.println("Sending 1st slave Distance Matrix"); 
   for (i = 0; i < 5; i++) {
       rs485.write(myDistValues[i]);
       Serial.println(myDistValues[i]);
       }
digitalWrite (ENABLE_PIN, LOW);
}
replay = false;
}
}

//-----------------------------Slave 2 Distance matrix------------------------------//

#include "RS485_protocol.h"
#include <SoftwareSerial.h>

const byte ENABLE_PIN = 2;

SoftwareSerial rs485 (10, 11); // receive pin, transmit pin boolean replay = false;

int myDistValues[5] = {5, 0, 4, 7, 10};
int i;

void setup()
{
Serial.begin(9600);
rs485.begin (28800);

pinMode (ENABLE_PIN, OUTPUT); // register event
}
void loop()
{
digitalWrite (ENABLE_PIN, LOW);
while (rs485.available())
{
char c = rs485.read();
delay(10);
if (c == '2') //2nd slave ID
{
Serial.println("Sending from slave:" );
Serial.println(c);

digitalWrite (ENABLE_PIN, HIGH);
replay = true;
}
delay(600);

if (replay)
{
digitalWrite (ENABLE_PIN, HIGH);//enable sending to the master
Serial.println("Sending 2nd slave Distance Matrix"); 
  for (i = 0; i < 5; i++) {
   rs485.write(myDistValues[i]);
   Serial.println(myDistValues[i]);
   }
digitalWrite (ENABLE_PIN, LOW);
}
replay = false;
}
}

  
