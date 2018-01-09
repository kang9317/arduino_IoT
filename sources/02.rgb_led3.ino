int REDpin=6, YELLOWpin=5, GREENpin=4;

void setup() {
  pinMode(REDpin, OUTPUT);
  pinMode(YELLOWpin, OUTPUT);
  pinMode(GREENpin, OUTPUT);
}

void loop() {
  LED();
}

void LED() {
  digitalWrite(REDpin, HIGH);
  delay(5000);
  digitalWrite(REDpin, LOW);
  digitalWrite(YELLOWpin, HIGH);
  delay(1000);
  digitalWrite(YELLOWpin, LOW);
  digitalWrite(GREENpin, HIGH);
  delay(5000);
  digitalWrite(GREENpin, LOW);
}

