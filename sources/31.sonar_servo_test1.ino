#include <Servo.h>
#define TRIG 2
#define ECHO 3

Servo servo;
boolean isNear = false;

void setup() {
  init_sonar();
}

void loop() {
  initialize_sonar();
  long distance = pulseIn(ECHO,HIGH)/58;

  if (distance < 30) {
    if (!isNear) {
      isNear = true;
      servo.write(0);
    }
  } else {
    if (isNear) {
      isNear = false;
      servo.write(90);
      delay(1000);
    }
  }
  delay(100);
}

void initialize_sonar() {
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIG,LOW);
}

void init_sonar() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  servo.attach(9);
  servo.write(90);
}
