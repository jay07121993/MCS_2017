//----------------- Master code for Distance matrix------------------------// 

#include "RS485_protocol.h"
#include <SoftwareSerial.h>
const byte ENABLE_PIN = 2;
SoftwareSerial rs485 (10, 11); // receive pin, transmit pin

char input[5];
int charsRead = 0;
boolean received = false;
char res;
boolean sendnow = false;
void setup()
{

Serial.begin(9600);
rs485.begin (28800);

  pinMode (ENABLE_PIN, OUTPUT);

}

void loop()
{

Serial.flush();
if (Serial.available() == 0)
{

}
delay(200);

while (Serial.available() > 0)
{

charsRead = Serial.readBytesUntil('\n', input, sizeof(input) - 1); 
sendnow = true;

}
if (sendnow)
{
digitalWrite (ENABLE_PIN, HIGH); // enable sending
rs485.write(input);
Serial.println(input);
//delayMicroseconds (660);
digitalWrite (ENABLE_PIN, LOW);
sendnow = false;
}

delay(1000);
digitalWrite (ENABLE_PIN, LOW);

while (rs485.available() && !sendnow)
{
Serial.println("Receiving Distance Matrix");
int dist;

for (int i = 0; i < 5; i++)
{
dist = rs485.read();
digitalWrite (ENABLE_PIN, HIGH);

Serial.println(dist);
  }
 }
}

//---------------------------- Master code for Module status Matrix-------------------------------------//

#include "RS485_protocol.h"
#include <SoftwareSerial.h>
const byte ENABLE_PIN = 2;
SoftwareSerial rs485 (10, 11); // receive pin, transmit pin

char input[5];
int charsRead = 0;
boolean received = false;
char res;
boolean sendnow = false;

void setup() {
Serial.begin(9600);
rs485.begin (28800);
pinMode (ENABLE_PIN, OUTPUT);
}

void loop()
{
Serial.flush();
if (Serial.available() == 0)
{
}

delay(200);
while (Serial.available() > 0)
{
charsRead = Serial.readBytesUntil('\n', input, sizeof(input) - 1); 
sendnow = true;
}
if (sendnow)
{
digitalWrite (ENABLE_PIN, HIGH); // enable sending
rs485.write(input);
Serial.println(input);
//delayMicroseconds (660);

digitalWrite (ENABLE_PIN, LOW);
sendnow = false;
}

delay(1000);
digitalWrite (ENABLE_PIN, LOW);

while (rs485.available() && !sendnow)
{
  Serial.println("Receiving Module Status Matrix"); 
  int mod;

for (int i = 0; i < 5; i++) {
 mod = rs485.read();
 digitalWrite (ENABLE_PIN, HIGH);
 Serial.println(mod);
  }
 }
}

//end
