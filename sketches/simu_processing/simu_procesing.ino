int x=0,y=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.write(x);
Serial.write(y);
Serial.println();
delay(1000);
x=0;
y++;   
} 
