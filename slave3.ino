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

