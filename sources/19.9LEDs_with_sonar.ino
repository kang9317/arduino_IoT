int trig = 4;
int echo = 3;
int led[] = {5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  for (int i = 0; i <= 9 ; i++ )
  {
    pinMode(led[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  int duration = pulseIn(echo, HIGH);
  int dis = duration / 29 / 2;
  Serial.print(dis);
  Serial.println("cm");
  for (int i = 12;i >= 0 ;i-- ) {
    if(dis < (12-i) ) {
      digitalWrite(led[i],HIGH);
    } else {
      digitalWrite(led[i],LOW);
    }
  }
}
