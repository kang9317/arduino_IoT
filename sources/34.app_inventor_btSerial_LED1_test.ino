#include <SoftwareSerial.h>
#define LED 9

SoftwareSerial btSerial(2, 3); //arduino 에서는 RX3, TX2, HC-06 에서는 rx2, tx3  

void setup() {
  pinMode(LED, OUTPUT);
  btSerial.begin(9600);
  Serial.begin(9600);
}

char myChar;

void loop() {
  while(Serial.available()){
    myChar = Serial.read();
    Serial.print(myChar);
  }
  if (btSerial.available()) {
    char c = btSerial.read();
    switch (c) {
      case 'a':
        digitalWrite(LED, HIGH);
        break;
      case 'b':
        digitalWrite(LED, LOW);
        break;
    }
  }
}
