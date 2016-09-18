    int incomingByte=0;
      void setup() {
        Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    if(Serial.available()>0){
      incomingByte=Serial.read();
      Serial.print("Datos recibidos: ");
      Serial.println(incomingByte,DEC);
      }
    delay(100);
}
