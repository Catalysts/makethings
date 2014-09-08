/*
  Flow 2  
 */
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  8;      // the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  pinMode(ledPin, OUTPUT);  // initialize the LED pin as an output
  pinMode(buttonPin, INPUT);// initialize the pushbutton pin as an input
}

void loop() {

  buttonState = digitalRead(buttonPin);    // read the state of the pushbutton value:

  if (buttonState == HIGH) {  // check if the pushbutton is pressed.
    digitalWrite(ledPin, HIGH);  // turn LED on:
  }
  else {
    digitalWrite(ledPin, LOW);  // turn LED off:
  }
}
