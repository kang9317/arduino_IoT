#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(9);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  myservo.write(90);
  delay(500);
}

void loop() {
  if(digitalRead(2) == HIGH){
    myservo.attach(9);
    myservo.write(150);
  } else if(digitalRead(3) == HIGH){
    myservo.attach(9);
    myservo.write(0);
  }
  delay(15);
}
