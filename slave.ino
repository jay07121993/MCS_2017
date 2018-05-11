//------------------------ Slave 1 Module status and distance Matrix--------------------------------------//

#include <Wire.h>

int address = 1; //slave's address (unique address)

void setup() {
  Wire.begin(address);
  Wire.onRequest(onRequest);
 // Wire.onRequest(onStatus);
  
}

void loop() {
  }

void onRequest() { //function called to receive request from master
  
  byte buffer[5] = {1,5,8,6,3}; //distance matrix of slave 1 to other slaves
  delay(5000);
  Wire.write(buffer,5);
}
/*
 void onStatus() {
  byte status[6] = {0,0,1,0,-1,-1};// Module status matrix to other slaves
  Wire.write(status,6);
}*/



//-------------------------Slave 2 Module status and distance matrix--------------------------------------//
#include <Wire.h>

int address = 2;

void setup() {
  Wire.begin(address);
  Wire.onRequest(onRequest);
  
}

void loop() {}

void onRequest() {
  byte buffer[5] = {5,1,4,7,10};
  Wire.write(buffer,5);
}
/*
void onRequest() {
  byte status[6] = {0,1,0,-1,0,1};
  Wire.write(status,6);
}
*/


//------------------------------Slave 3 Module status and distance matrix-----------------------------------------//

#include <Wire.h>

int address = 3;

void setup() {
  Wire.begin(address);
  Wire.onRequest(onRequest);
}

void loop() {}

void onRequest() {
  byte buffer[5] = {8,4,1,3,6};
  Wire.write(buffer,5);
}
/*
 void onRequest() {
  byte status[6] = {0,0,1,0,-1,-1};
  Wire.write(status,6);
}
*/
