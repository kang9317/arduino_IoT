#include <Servo.h>

Servo myservo;

int servoPin = 5;
int min_value = 544;
int max_value = 2400;

void setup() {
  Serial.begin(9600);
  Serial.println("Servo Value = ?");

  myservo.attach(servoPin, min_value, max_value);
  myservo.write(90);
}

void loop() {
  if (Serial.available() > 0) {
    int servo_value = Serial.parseInt();
    myservo.write(servo_value);
    Serial.println(servo_value);
  }
}
