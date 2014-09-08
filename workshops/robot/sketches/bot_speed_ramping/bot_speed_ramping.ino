#include <Servo.h>

Servo rightServo;
Servo leftServo;

#define MAX_FORWARD  1800
#define NEUTRAL 1500
#define MAX_BACKWARD 1200
#define SPEED_CORRECTION 40

int leftSpeed = NEUTRAL;
int rightSpeed = NEUTRAL;
int leftSpeedCurrent = NEUTRAL;
int rightSpeedCurrent = NEUTRAL;

#define LED 13

void setup() { 
  pinMode(A0, INPUT);
  pinMode(LED, OUTPUT);
  attachServos();
//  Serial.begin(9600);
} 


int sign(int x) { return ((x>0)-(x<0)); }

void correctSpeed() {
  int diff = leftSpeed - leftSpeedCurrent;
  if (diff != 0) {
    leftSpeedCurrent += sign(diff) * min(SPEED_CORRECTION, abs(diff));
  }
  diff = rightSpeed - rightSpeedCurrent;
  if (diff != 0) {
    rightSpeedCurrent += sign(diff) * min(SPEED_CORRECTION, abs(diff));
  }
  rightServo.writeMicroseconds(leftSpeedCurrent);
  leftServo.writeMicroseconds(rightSpeedCurrent);
}

void attachServos() {
  if (!rightServo.attached()) {
    rightServo.attach(9);
  }
  if (!leftServo.attached()) {
    leftServo.attach(10);
  }
}
void detachServos() {
  if (rightServo.attached()) {
    rightServo.detach();
  }
  if (leftServo.attached()) {
    leftServo.detach();
  }
}

void forward () {
  attachServos();
  rightSpeed = MAX_FORWARD;
  leftSpeed = MAX_BACKWARD;
}
void backward () {
  attachServos();
  rightSpeed = MAX_FORWARD;
  leftSpeed = MAX_BACKWARD;
}
void left() {
  attachServos();
  rightSpeed = MAX_BACKWARD;
  leftSpeed = MAX_BACKWARD;
}
void right() {
//  attachServos();
  rightSpeed = MAX_FORWARD;
  leftSpeed = MAX_FORWARD;
}
void stop() {
  rightSpeed = NEUTRAL;
  leftSpeed = NEUTRAL;
//  rightSpeedCurrent = NEUTRAL;
//  leftSpeedCurrent = NEUTRAL;
//  detachServos();
}
int look() {
  return analogRead(A0);
}
int dir = 0;



void loop() { 
  Serial.println(look());
  delay(100);
  int l = look();
  if (l < 300) {
    backward();
  } else 
  if (l > 500) {
    stop();
    if (dir == 0) {
      randomSeed(millis());
      dir = random(1, 3);
    }
    if (dir == 1) {
      left();
    } else {
      right();
    }
  } else {
    forward();
    dir = 0;
  }
  correctSpeed(); // speed rampling
}
