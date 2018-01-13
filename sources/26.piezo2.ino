#define C 262
#define D 294
#define E 330
#define F 349
#define G 392
#define A 440
#define B 494

int piezoPin = 8;
int tempo = 200;
int notes[25] = {G, G, A, A, G, G, E, G, G, E, E, D, G, G, A, A, G, G, E, G, E, D, E, C };

void setup() {
  pinMode(piezoPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 12; i++) {
    tone(piezoPin, notes[i], tempo);
    delay(300);
  }
  delay(100);

  for (int i = 12; i < 25; i++) {
    tone(piezoPin, notes[i], tempo); 
    delay(300);
  }
}
