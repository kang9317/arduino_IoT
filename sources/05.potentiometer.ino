int sensorPin = 0;
const int ledPin=9;

//int sensorPin = A0;

void setup() {
  pinMode(ledPin,OUTPUT);
}

void loop() {
  int value = analogRead(sensorPin);
  int intensity = map(value, 0, 1023, 0, 255);
  analogWrite(ledPin, intensity);
}
