void setup() {
  Serial.begin(9600);
}
 
void loop() {
  Serial.print("available : ");
  Serial.println(Serial.available());
  delay(1000);
  //Serial.parseInt(); 는 숫자로 받아서 시리얼에 쓰는것 버퍼에 저장.
}
