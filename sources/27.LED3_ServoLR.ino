#include <Servo.h>
Servo myservo;

int pos = 0;
int servo_interval=15, increment=1;

const int ledPin1=11, ledPin2=12, ledPin3=13;

int ledState1=LOW, ledState2=LOW, ledState3=LOW;

unsigned long previousMillis1 = 0, previousMillis2 = 0, previousMillis3 = 0, ServoPreviousMillis = 0;

const long OnTime1=250;
const long OffTime1=OnTime1;
const long OnTime2=OnTime1*3;
const long OffTime2=OnTime2;
const long OnTime3=OnTime1*5;
const long OffTime3=OnTime3;

void setup() {
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  myservo.attach(9);

  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  if ((ledState1 == HIGH) && (currentMillis - previousMillis1 >= OnTime1)) {
    ledState1 = !ledState1;
    previousMillis1 = currentMillis;
    digitalWrite(ledPin1,ledState1);
  } else if ((ledState1 == LOW) && (currentMillis - previousMillis1 >= OffTime1)) {
    ledState1 = !ledState1;
    previousMillis1 = currentMillis;
    digitalWrite(ledPin1,ledState1);
  }
  if ((ledState2 == HIGH) && (currentMillis - previousMillis2 >= OnTime2)) {
    ledState2 = !ledState2;
    previousMillis2 = currentMillis;
    digitalWrite(ledPin2,ledState2);
  } else if ((ledState2 == LOW) && (currentMillis - previousMillis2 >= OffTime2)) {
    ledState2 = !ledState2;
    previousMillis2 = currentMillis;
    digitalWrite(ledPin2,ledState2);
  }
  if ((ledState3 == HIGH) && (currentMillis - previousMillis3 >= OnTime3)) {
    ledState3 = !ledState3;
    previousMillis3 = currentMillis;
    digitalWrite(ledPin3,ledState3);
  } else if ((ledState3 == LOW) && (currentMillis - previousMillis3 >= OffTime3)) {
    ledState3 = !ledState3;
    previousMillis3 = currentMillis;
    digitalWrite(ledPin3,ledState3);
  }
  if (millis() - ServoPreviousMillis >= servo_interval) {
    ServoPreviousMillis = millis();
    pos += increment;
    myservo.write(pos);
    if ((pos >= 180) || (pos < 0)) {
      increment = -increment;
    }
  }
}
