int R=11, G=10, B=9;
const int trigPin = 3, echoPin = 2;
long duration;
int distanceCm, distanceInch;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  initialize();
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
  delay(10);
  if (distanceCm > 15 && distanceCm < 20) {
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(B, HIGH);
  } else if (distanceCm > 10 && distanceCm < 20) {
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
  } else if (distanceCm > 5 && distanceCm < 20) {
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, LOW);
  } else {
    initialize();
  }
}

void initialize() {
  digitalWrite(R, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(B, HIGH);
}
