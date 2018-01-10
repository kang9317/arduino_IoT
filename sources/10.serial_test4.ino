void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
 
void loop() {
  if(Serial.available() > 0){
    char a;
    a = Serial.read();
    if(a=='1'){
      digitalWrite(13,HIGH);
      Serial.println("LED On");
    } else {
      digitalWrite(13, LOW);
      Serial.print("input data : ");
      Serial.println(a);
      Serial.println("LED Off");
    }
  }
}
