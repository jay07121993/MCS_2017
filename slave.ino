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
  byte status[6] = {0,0,1,0,-1,-1};
  Wire.write(status,6);
}*/
//end


