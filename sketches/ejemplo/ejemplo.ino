#include"librerias/laberinto.h"
char incomingByte=0;
void setup() {
Serial.begin(9600);
Serial1.begin(9600);
}

void loop() {

  if(Serial1.available()>0){
    incomingByte=Serial1.read();
    Serial.write(incomingByte);
  }
  if(Serial.available())
  {
    Serial1.write(Serial.read());
    
  }
  
}
