//#include <SoftwareSerial.h>
#define RED 9
#define GREEN 10
#define BLUE 11

//SoftwareSerial btSerial(2, 3); //RX, TX 

void setup() {
//  btSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
/*  if (btSerial.available()) {
    char c = btSerial.read();
    switch (c) {
    case 'r':
      analogWrite(RED, btSerial.parseInt());
      break;
    case 'g':
      analogWrite(GREEN, btSerial.parseInt());
      break;
    case 'b':
      analogWrite(BLUE, btSerial.parseInt());
      break;
    }
  }
*/
  if (Serial.available()) {
    char c = Serial.read();
    switch (c) {
    case 'r':
      analogWrite(RED, Serial.parseInt());
      break;
    case 'g':
      analogWrite(GREEN, Serial.parseInt());
      break;
    case 'b':
      analogWrite(BLUE, Serial.parseInt());
      break;
    case 'z':
      analogWrite(BLUE, 255);
      analogWrite(GREEN, 255);
      analogWrite(RED, 255);
      break;
    }
  }
}

