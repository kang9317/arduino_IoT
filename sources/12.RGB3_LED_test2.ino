int R=9, G=10, B=11;

void setup() {
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  byte data;
  data = Serial.read();
  if (data == '1') {
    analogWrite(R, 0);
    analogWrite(G, 255);
    analogWrite(B, 255);
    delay(200);
  } else if (data == '2') {
    analogWrite(R, 0);
    analogWrite(G, 161);
    analogWrite(B, 255);
    delay(200);
  } else if (data == '3') {
    analogWrite(R, 0);
    analogWrite(G, 68);
    analogWrite(B, 255);
    delay(200);
  } else if (data == '4') {
    analogWrite(R, 0);
    analogWrite(G, 27);
    analogWrite(B, 255);
  } else if (data == '5') {
    analogWrite(R, 84);
    analogWrite(G, 13);
    analogWrite(B, 255);
  } else if (data == 'r') {
    analogWrite(R, 255);
    analogWrite(G, 255);
    analogWrite(B, 255);
  }
}
