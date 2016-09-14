    int incomingByte=0;
      void setup() {
        Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    //Serial.write(48);
    //Serial. println(123,BIN);
    //Serial. println(123,HEX);
    //Serial. println(1.2345,3);
    //Serial. println(F("HOLA MUNDO"));
    if(Serial.available()>0){
      incomingByte=Serial.read();
      Serial.print("Datos recibidos: ");
      Serial.println(incomingByte,DEC);
      }
    delay(100);
}
