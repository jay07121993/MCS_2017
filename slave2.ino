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
//end
