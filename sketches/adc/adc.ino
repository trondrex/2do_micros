uint8_t width=0;
int pinAnalog=A0;
int value=0;
uint32_t previousMillis=0;
void setup() {
  // put your0A=; setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint32_t currentMillis=millis();
  if(currentMillis-previousMillis>=100)
  {
    previousMillis=currentMillis;
    analogWrite(3,width);
    width++;
    }
  value=analogRead(pinAnalog);
  Serial.println(value);
  

}
