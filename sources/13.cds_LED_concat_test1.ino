int ledPin=13;
int sensoPin=0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(0);
  Serial.println(val);
  if(val > 200) {
    digitalWrite(ledPin, HIGH);
    delay(1);
  } else {
    digitalWrite(ledPin, LOW);
    delay(1);
  }
}
