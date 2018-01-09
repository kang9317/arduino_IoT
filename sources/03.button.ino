int LED1=6, LED2=5, LED3=4, BUTTON=2, STATUS=0;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  if (digitalRead(BUTTON) == HIGH){
    STATUS += 1;
    if (STATUS >= 3){
      STATUS = 0;
    }
  }
  switch(STATUS) {
    case 0:
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
      break;
    case 1:
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);
      break;
    case 2:
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,HIGH);
      break;
  }
  delay(100);
}
