/**
* Basic line-following algorithm
*/
#include <Servo.h>

// #define DEBUG 1 // uncomment line to get debug info

// servo is controlled with PWM signal with pulse width from 1000 to 2000 microseconds
#define NEUTRAL 1500 // pulse width for servo at zero speed
#define MAX_SPEED 50 // diff for pulse width (from 0 to 500 (max speed))
#define MAX_FORWARD NEUTRAL+MAX_SPEED // pulse width for max counter-clockwise speed
#define MAX_BACKWARD NEUTRAL-MAX_SPEED // pulse width for max clockwise speed

#define LED 13 // on-board Arduino LED

// Move directions
#define UNKNOWN -1
#define FORWARD 0
#define LEFT 1
#define RIGHT 2
#define BACKWARD 3

Servo rightServo;
Servo leftServo;

void attachServos() {
  if (!rightServo.attached()) { rightServo.attach(9); }
  if (!leftServo.attached()) { leftServo.attach(10); }
}

void move(int dir) {
  switch (dir) {
    case FORWARD:
      rightServo.writeMicroseconds(MAX_BACKWARD);
      leftServo.writeMicroseconds(MAX_FORWARD);
      break;
    case LEFT:
      rightServo.writeMicroseconds(MAX_BACKWARD);
      leftServo.writeMicroseconds(MAX_BACKWARD);
      break;
    case RIGHT:
      rightServo.writeMicroseconds(MAX_FORWARD);
      leftServo.writeMicroseconds(MAX_FORWARD);
      break;
    case BACKWARD:
      rightServo.writeMicroseconds(MAX_FORWARD);
      leftServo.writeMicroseconds(MAX_BACKWARD);
      break;
    default:
      rightServo.writeMicroseconds(NEUTRAL);
      leftServo.writeMicroseconds(NEUTRAL);
  }
}

#define LINE_LEFT 5
#define LINE_CENTER 6
#define LINE_RIGHT 7

int checkLine(int pos) {
  return digitalRead(pos);
}

void setup() { 
  pinMode(A0, INPUT);
  pinMode(LED, OUTPUT);
  attachServos();
#ifdef DEBUG
  Serial.begin(9600);
#endif
} 

int currentDirection = UNKNOWN;

void loop() { 
  // read sensors
  int l = checkLine(LINE_LEFT);
  int c = checkLine(LINE_CENTER);
  int r = checkLine(LINE_RIGHT);
#ifdef DEBUG
  Serial.print(l);
  Serial.print(c);
  Serial.println(r);
#endif
  // main algorithm
  if (l == LOW && r == HIGH) {
    currentDirection = LEFT;
  } else if (l == HIGH && r == LOW) {
    currentDirection = RIGHT;
  } else {
    currentDirection = FORWARD; 
  }
  // indicate getting back on path
  digitalWrite(LED, currentDirection != FORWARD);
  move(currentDirection);
  delay(50); // 50 ms delay
}
