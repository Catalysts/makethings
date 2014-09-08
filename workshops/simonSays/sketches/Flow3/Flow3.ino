/*
  Flow 3
 */

const int numColors = 3;              //num of couples btn+led		
const int buttonPins[] = {2, 3, 4};  //pins of the buttons
const int ledPins[] =  {8, 9, 10};  //pins of the leds

void setup() {
  Serial.begin(9600);
  for(int i=0; i<numColors; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  for(int i=0; i<numColors; i++) {
    pinMode(buttonPins[i], INPUT);
  }
}


void loop() {
  for(int i=0; i<numColors; i++){
    if (digitalRead(buttonPins[i]) == HIGH){
      digitalWrite(ledPins[i], HIGH);
    }
  }
}
