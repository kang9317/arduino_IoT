void setup() {
  Serial.begin(9600);
}
 
void loop() {
  Serial.print("read : ");
  Serial.println((char)Serial.read());
  delay(1000);
}
