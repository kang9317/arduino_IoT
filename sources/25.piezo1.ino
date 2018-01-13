int BuzzerPin=12;
int num=8;
int tones[] = {261, 294, 330, 349, 392, 440, 494, 523};

void setup() {
  for (int i = 0; i < num; i++) {
    tone(BuzzerPin, tones[i]);
    delay(1500);
  }
  noTone(BuzzerPin);
}

void loop() {

}
