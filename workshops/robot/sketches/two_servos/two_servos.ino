#include <Servo.h>

#define NEUTRAL 1500 // pulse width for servo at zero speed
#define MAX_SPEED 300 // diff for pulse width between zero and max speed
#define MAX_FORWARD NEUTRAL+MAX_SPEED // pulse width for max counter-clockwise speed
#define MAX_BACKWARD NEUTRAL-MAX_SPEED // pulse width for max clockwise speed

Servo leftServo, rightServo;

int current = NEUTRAL;
int step = 10;

void setup() { 
  leftServo.attach(10); // attach left servo to pin 10
  rightServo.attach(9); // attach right servo to pin 9
  Serial.begin(9600);
  leftServo.writeMicroseconds(current);
  rightServo.writeMicroseconds(current);
  delay(5000);
} 

void loop() { 
  current += step;
  if (current < MAX_BACKWARD || current > MAX_FORWARD) { step = -step; }
  leftServo.writeMicroseconds(current);
  rightServo.writeMicroseconds(current);
  Serial.println(current);
  delay(100);
}
