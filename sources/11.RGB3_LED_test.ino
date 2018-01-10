int R=7, G=5, B=3;
int sw1=12, sw2=10, sw3=8;

void setup() {
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(sw1,INPUT_PULLUP);
  pinMode(sw2,INPUT_PULLUP);
  pinMode(sw3,INPUT_PULLUP);
}

void loop() {
  digitalWrite(R, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(B, HIGH);
  if(digitalRead(sw1) == LOW){
    digitalWrite(R,LOW);
  }
  if(digitalRead(sw2) == LOW){
    digitalWrite(G, LOW);
  }
  if(digitalRead(sw3) == LOW){
    digitalWrite(B, LOW);
  }
}
