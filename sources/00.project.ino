#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo;
SoftwareSerial BTSerial(2, 3); //RX, TX

const int trigPin = 6;
const int echoPin = 5;
long duration;
int distanceCm, distanceInch;

#define buzzer1 4
#define buzzer2 11

#define button_octave_high 7
#define button_octave_low 8

int tones[] = {261, 294, 330, 349, 392, 440, 494, 523};
char char_tones[] = {'d', 'r', 'm', 'f', 's', 'l', 'c', 't'};

const int max_octave_level = 4;
const int min_octave_level = 1;

int pos = 0;
int level;
int octave_state;
char bell_tone;

boolean already_connected;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(button_octave_high, INPUT);
  pinMode(button_octave_low, INPUT);
  BTSerial.begin(9600);
  pinMode(buzzer2, OUTPUT);
  Serial.begin(9600);
  level = 0;
  already_connected = false;
  octave_state = 2;
  for (int i = 10; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  myservo.attach(9);
  myservo.write(40);
}

void loop() {
  Serial.println(analogRead(A0));
  int vol = map(analogRead(A0), 10, 956, 0, 100);

  //Serial.println(BTSerial.available());
  if((BTSerial.read() == 'q') && (already_connected == false)) {
    already_connected = true;
    Serial.println(already_connected);
    connect();
    Serial.println("Bluetooth On");
  }
  
  /* 수정필요 작동안됨
  //&& (already_connected == true)
  //Serial.println(BTSerial.readBytes());
  if((BTSerial.read() == 'x')) {
    already_connected = false;
    Serial.println(already_connected);
    disconnect();
    Serial.println("Bluetooth Off");
  }
  */
  
  if((vol >= 0) && (vol < 33)) {
    volume_red1();
  } else if ((vol >= 33) && (vol < 67)) {
    volume_red2();
  } else if ((vol >= 67) && (vol <= 100)) {
    volume_red3();
  }

  if (already_connected == true) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distanceCm= duration*0.034/2;

    while(!digitalRead(button_octave_high) == HIGH) {
      if ((octave_state >= min_octave_level) && (octave_state < max_octave_level)) {
        Serial.println("HIGH");
        level += 261;
        octave_state += 1;
        Serial.println(octave_state);
        switch (octave_state) {
          case 2:
            Serial.println(octave_state);
            Serial.println("2");
            octave(octave_state);
            break;
          case 3:
            Serial.println(octave_state);
            Serial.println("3");
            octave(octave_state);
            break;
          case 4:
            Serial.println(octave_state);
            Serial.println("4");
            octave(octave_state);
            break;
          default:
            octave(octave_state);
            break;
        }
        delay(200);
      }
    }

    while(!digitalRead(button_octave_high) == HIGH) {
      if ((octave_state > min_octave_level) && (octave_state <= max_octave_level))
      {
        Serial.println("LOW");
        octave_state -= 1;
        level -= 261;
        switch (octave_state) {
          case 1:
            Serial.println(octave_state); 
            //Serial.println("1");
            octave(octave_state);
            break;
          case 2:
            Serial.println(octave_state);
            //Serial.println("2");
            octave(octave_state);
            break;
          case 3:
            Serial.println(octave_state);
            //Serial.println("3");
            octave(octave_state);
            break;
          default:
            octave(octave_state);
            break;
        }
        delay(200);
      }
    }
    

    if (distanceCm >= 2 && distanceCm < 27) {
      Serial.print("Distance: ");
      Serial.print(distanceCm);
      Serial.println(" cm");
      delay(100);
      
      if ((distanceCm > 2) && (distanceCm <= 6))  {
        bell_tone = char_tones[0];
      } else if (((distanceCm > 6) && (distanceCm <= 9))) {
        bell_tone = char_tones[1];
      } else if (((distanceCm > 9) && (distanceCm <= 12))) {
        bell_tone = char_tones[2];
      } else if (((distanceCm > 12) && (distanceCm <= 15))) {
        bell_tone = char_tones[3];
      } else if (((distanceCm > 15) && (distanceCm <= 18))) {
        bell_tone = char_tones[4];
      } else if (((distanceCm > 18) && (distanceCm <= 21))) {
        bell_tone = char_tones[5];
      } else if (((distanceCm > 21) && (distanceCm <= 24))) {
        bell_tone = char_tones[6];
      } else if (((distanceCm > 24) && (distanceCm <= 27))) {
        bell_tone = char_tones[7];
      }
      tone(buzzer1, play_bell(bell_tone, level));
    } else {
      noTone(buzzer1);
    }
  }
}


int play_bell(char bell_tone, int level) {
  int  doremi = 0;
  switch (bell_tone) {
    case 'd':
      Serial.println("도");
      doremi = tones[0]+level;
      break;
    case 'r':
      Serial.println("레");
      doremi = tones[1]+level;
      break;
    case 'm':
      Serial.println("미");
      doremi = tones[2]+level;
      break;
    case 'f':
      Serial.println("파");
      doremi = tones[3]+level;
      break;
    case 's':
      Serial.println("솔");
      doremi = tones[4]+level;
      break;
    case 'l':
      Serial.println("라");
      doremi = tones[5]+level;
      break;
    case 'c':
      Serial.println("시");
      doremi = tones[6]+level;
      break;
    case 't':
      Serial.println("도");
      doremi = tones[7]+level;
      break;
    default:
      break;
  }
  return doremi;
}

void bell() {
  delay(1000);
  noTone(buzzer1);
  delay(500);
}

void octave(int num) {
  for (int i = 0; i < num; i++)
  {
    digitalWrite(buzzer2,HIGH);
    delay(100);
    digitalWrite(buzzer2,LOW);
    delay(100);
  }
}

void connect() {
  octave(5);
}


/* disconnect 사용불가 -- 수정필요*/
void disconnect() {
  octave(1);
  delay(300);
  octave(2);
}

void volume_red() {
  //delay(400);
  digitalWrite(13,LOW);
  digitalWrite(10,HIGH);
  myservo.write(120);
}

void volume_yellow() {
  //delay(400);
  digitalWrite(10,LOW);
  digitalWrite(12,HIGH);
  myservo.write(80);
}

void volume_green() {
  //delay(400);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  myservo.write(40);
}

void volume_red1() {
  //delay(400);
  myservo.attach(9);
  digitalWrite(10,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  myservo.write(120);
}

void volume_red2() {
  //delay(400);
  myservo.attach(9);
  digitalWrite(10,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  myservo.write(80);
}

void volume_red3() {
  //delay(400);
  myservo.attach(9);
  digitalWrite(10,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  myservo.write(40);
}
