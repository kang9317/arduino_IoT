#include <Servo.h>

Servo myservo;
Servo myservo2;
int pos = 90;

void setup() {
  myservo.attach(9);
  myservo2.attach(10);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  myservo.write(90);
  delay(500);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(2) == HIGH){
    pos++;
  }
  if(digitalRead(3) == HIGH){
    pos--;
  }

  if (pos < 0) {
    pos = 0;
  } else if (pos > 180) {
    pos = 180;
  }
  myservo.write(pos);
  Serial.println(myservo.read());
  myservo2.write(myservo.read());
  delay(1);
}
