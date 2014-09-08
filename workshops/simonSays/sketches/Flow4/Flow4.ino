/*
  Flow 4 
 */

#include "pitches.h"

const int numColors = 3;
const int buttonPins[] = {2, 3, 4};  //pins of the buttons
const int ledPins[] =  {8, 9, 10};  //pins of the leds
const int notes[] = {NOTE_G3, NOTE_A3, NOTE_B3};  //notes associated to the colors                
const int buzzerPin =  12;  //pin of the buzzer

int notesNextLevel[] = {NOTE_C4, NOTE_C4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5};  //notes played at the beginning of each level
int durationNotesNextLevel[] = {100, 100, 100, 300, 100, 300};  //corresponding duration

int buttonStates[] = {0, 0, 0};         // variable for reading the pushbutton status
int level = 1;
const int maxLevel = 50;  //the max level (level N has N sequence of colors!)
int sequence[maxLevel];  //store the random generated sequence of colors
const int pauseTime = 200;  //pause time between game flow


void setup() {
  Serial.begin(9600);
  for(int i=0; i<numColors; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  for(int i=0; i<numColors; i++) {
    pinMode(buttonPins[i], INPUT);
  }
  randomSeed(analogRead(0));  //create randomness
}

void loop() {
  for(; level<maxLevel; level++){
    Serial.print("Level: ");
    Serial.println(level);
    
    //light + sound intro to the level
    for(int i=0; i<numColors; i++){
      digitalWrite(ledPins[i], HIGH);
    }
    for (int i = 0; i < 6; i++) {
      tone(buzzerPin, notesNextLevel[i], durationNotesNextLevel[i]); 
      delay(durationNotesNextLevel[i] * 1.30);
    }
    for(int i=0; i<numColors; i++){
      digitalWrite(ledPins[i], LOW);
    }
    delay(pauseTime * 2);
    
    //Fill the mysterious sequence of colors
    for(int j=0; j<level; j++){  
      sequence[j] = random(0, numColors);
    }

    //Show the sequence
    for(int j=0; j<level; j++){
      int color = sequence[j];
      digitalWrite(ledPins[color], HIGH);
      tone(buzzerPin, notes[color], pauseTime);
      delay(pauseTime);
      digitalWrite(ledPins[color], LOW);
      delay(pauseTime);
    }

    //read the sequence from the buttons
    boolean sequenceOk = true;
    for(int j=0; j<level && sequenceOk; j++){
      int buttonPushed = -1;
      while(buttonPushed == -1){
        for(int i=0; i<numColors; i++){  //read the buttons
          buttonStates[i] = digitalRead(buttonPins[i]);
          if (buttonStates[i] == HIGH){
            buttonPushed = i;
            digitalWrite(ledPins[i], HIGH);
            tone(buzzerPin, notes[i], pauseTime);
            delay(pauseTime); 
            break;
          }
        }
        
        if (buttonPushed != -1){  //if a button has been pushed
          if (sequence[j] != buttonPushed){
            sequenceOk = false;
          } else {
            delay(50);
            digitalWrite(ledPins[buttonPushed], LOW);
          }
        }  
      }
    }
    
    if (!sequenceOk){
      gameOver();
    }
    
    if (sequenceOk && level == maxLevel-1){
      theEnd();
    }

  }
  
  delay(250);

}

void theEnd(){
  Serial.println("Congratulations! You finished the game!! :)");
  delay(250);
  tone(buzzerPin, NOTE_C4, 250);
  delay(250);
  tone(buzzerPin, NOTE_G4, 500);
  for(int i=0; i<numColors*10; i++){
      digitalWrite(ledPins[i%numColors], HIGH);
      delay(50);
      digitalWrite(ledPins[i%numColors], LOW);
      delay(50);
  }
  delay(500);
  level = 0;
}

void gameOver(){
  Serial.println("Game Over!! :(");
  delay(250);
  tone(buzzerPin, NOTE_G4, 250);
  delay(250);
  tone(buzzerPin, NOTE_C4, 500);
  for(int i=0; i<5; i++){
    for(int j=0; j<numColors; j++){
      digitalWrite(ledPins[j], HIGH);
    }
    delay(50);
    for(int j=0; j<numColors; j++){
      digitalWrite(ledPins[j], LOW);
    }
    delay(50);
  }
  delay(500);
  level = 0;
}
