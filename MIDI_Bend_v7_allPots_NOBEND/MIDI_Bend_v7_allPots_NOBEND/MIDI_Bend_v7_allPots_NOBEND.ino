

#include <pitchToNote.h>
#include <MIDIUSB_Defs.h>
#include <MIDIUSB.h>

//NOTE VARIABLES
const int firstPin = A1;
const int secondPin = A2;
const int thirdPin = A3;
const int fourthPin = A4;
const int notePin = A5;

int firstJoyNote;
int secondJoyNote;
int thirdJoyNote;
int fourthJoyNote;

int formerFirstJoyNote = pitchC4;
int formerSecondJoyNote = pitchC4;
int formerThirdJoyNote = pitchC4;
int formerFourthJoyNote = pitchC4;

//PITCH BEND VARIABLES

int firstPitchBend;
int secondPitchBend;
int thirdPitchBend;
int fourthPitchBend;

int firstMappedBend;
int secondMappedBend;
int thirdMappedBend;
int fourthMappedBend;

int firstJoyVal = 0;
int secondJoyVal = 255;
int thirdJoyVal = 510;
int fourthJoyVal = 765;

//BUTTON VARIABLED

const int firstButtonPin = 8;
const int secondButtonPin = 9;
const int thirdButtonPin = 10;
const int fourthButtonPin = 7;

int firstButtonVal = 1;
int secondButtonVal = 1;
int thirdButtonVal = 1;
int fourthButtonVal = 1;

int formerFirstButton = 1;
int formerSecondButton = 1;
int formerThirdButton = 1;
int formerFourthButton = 1;

int firstNoteState = 1;
int secondNoteState = 1;
int thirdNoteState = 1;
int fourthNoteState = 1;

//LED VARIABLES

int firstLEDPin = 12;
int secondLEDPin = 13;
int thirdLEDPin = 4;
int fourthLEDPin = 3;

int firstLEDState = 0;
int secondLEDState = 0;
int thirdLEDState = 0;
int fourthLEDState = 0;

void setup() {

  midiCommand(0x80, formerFirstJoyNote, 0);

  Serial.begin(9600);

  pinMode(firstButtonPin, INPUT_PULLUP);
  pinMode(secondButtonPin, INPUT_PULLUP);
  pinMode(thirdButtonPin, INPUT_PULLUP);
  pinMode(fourthButtonPin, INPUT_PULLUP);

  pinMode(firstLEDPin, OUTPUT);
  pinMode(secondLEDPin, OUTPUT);
  pinMode(thirdLEDPin, OUTPUT);
  pinMode(fourthLEDPin, OUTPUT);

}

void loop() {
  //
  ////  //loop the "sensor" values for testing
  ////  if (firstJoyVal >= 1023) {
  ////    firstJoyVal = 0;
  ////  }
  ////  if (secondJoyVal >= 1023) {
  ////    secondJoyVal = 0;
  ////  }
  ////  if (thirdJoyVal >= 1023) {
  ////    thirdJoyVal = 0;
  ////  }
  ////  if (fourthJoyVal >= 1023) {
  ////    fourthJoyVal = 0;
  ////  }


  //------------ -READ INPUTS
  firstJoyVal = analogRead(firstPin);
  secondJoyVal = analogRead(secondPin);
  thirdJoyVal = analogRead(thirdPin);
  fourthJoyVal = analogRead(fourthPin);

  firstButtonVal = digitalRead(firstButtonPin);
  secondButtonVal = digitalRead(secondButtonPin);
  thirdButtonVal = digitalRead(thirdButtonPin);
  fourthButtonVal = digitalRead(fourthButtonPin);






  Serial.print(firstJoyVal);
  Serial.print(" | ");
  Serial.print(secondJoyVal);
  Serial.print(" | ");
  Serial.print(thirdJoyVal);
  Serial.print(" | ");
  Serial.println(fourthJoyVal);

  //---------------BUTTON 1-----------------------//

  //  Serial.print(" | ");
  //  Serial.print("buttonState:");
  //  Serial.println(firstNoteState);

  if (firstButtonVal != formerFirstButton) {
    if (firstButtonVal == LOW && firstNoteState == HIGH) {
      firstNoteState = LOW;
    } else if (firstButtonVal == LOW && firstNoteState == LOW) {
      firstNoteState = HIGH;
    }
    delay(50);
  }
  formerFirstButton = firstButtonVal;


  //--------------JOYSTICK 1-------------------//
  //divided the range of input values equally among the 7 possible notes

  if (firstNoteState == LOW) { //only run this code if the button is pressed


    if (firstJoyVal >= 0 && firstJoyVal < 146) { //PLAY A4

      midiCommand(0x80, firstJoyNote, 0);
      firstJoyNote = pitchA4;

      midiCommand(0x90, firstJoyNote, 127);
      delay(50);
    }
    if (firstJoyVal >= 146 && firstJoyVal < 292) { //PLAY G4

      //play the note
      midiCommand(0x80, firstJoyNote, 0);
      firstJoyNote = pitchG4;

      midiCommand(0x90, firstJoyNote, 127);
      delay(50);
    }
    if (firstJoyVal >= 292 && firstJoyVal < 438) { //PLAY F4

      //play the note
      midiCommand(0x80, firstJoyNote, 0);
      firstJoyNote = pitchF4;

      midiCommand(0x90, firstJoyNote, 127);
      delay(50);
    }
    if (firstJoyVal >= 438 && firstJoyVal < 584) { //PLAY E4

      //play the note
      midiCommand(0x80, firstJoyNote, 0);
      firstJoyNote = pitchE4;

      midiCommand(0x90, firstJoyNote, 127);
      delay(50);
    }
    if (firstJoyVal >= 584 && firstJoyVal < 730) { //PLAY D4

      //play the note
      midiCommand(0x80, firstJoyNote, 0);
      firstJoyNote = pitchD4;

      midiCommand(0x90, firstJoyNote, 127);
      delay(50);
    }
    if (firstJoyVal >= 730 && firstJoyVal < 876) { //PLAY C4

      midiCommand(0x80, firstJoyNote, 0);
      firstJoyNote = pitchC4;

      midiCommand(0x90, firstJoyNote, 127);
      delay(50);
    }
    if (firstJoyVal >= 876 && firstJoyVal <= 1023) { //PLAY B3

      //play the note
      midiCommand(0x80, firstJoyNote, 0);
      firstJoyNote = pitchB3;

      midiCommand(0x90, firstJoyNote, 127);
      delay(50);
    }




    digitalWrite(firstLEDPin, HIGH);
    //  midiCommand(0x80, firstJoyNote, 0);

  } else if (firstNoteState == HIGH) {
    digitalWrite(firstLEDPin, LOW);

    //stop the note
    midiCommand(0x80, firstJoyNote, 0);
  }

  //---------------------------------------

  //---------------BUTTON 2-----------------------//

  //  Serial.print(" | ");
  //  Serial.print("buttonState:");
  //  Serial.println(firstNoteState);

  if (secondButtonVal != formerSecondButton) {
    if (secondButtonVal == LOW && secondNoteState == HIGH) {
      secondNoteState = LOW;
    } else if (secondButtonVal == LOW && secondNoteState == LOW) {
      secondNoteState = HIGH;
    }
    delay(50);
  }
  formerSecondButton = secondButtonVal;


  //--------------JOYSTICK 2-------------------//
  //divided the range of input values equally among the 7 possible notes

  if (secondNoteState == LOW) { //only run this code if the button is pressed


    if (secondJoyVal >= 0 && secondJoyVal < 146) { //PLAY A4

      midiCommand(0x80, secondJoyNote, 0);
      secondJoyNote = pitchA4;

      midiCommand(0x90, secondJoyNote, 127);
      delay(50);
    }
    if (secondJoyVal >= 146 && secondJoyVal < 292) { //PLAY G4

      //play the note
      midiCommand(0x80, secondJoyNote, 0);
      secondJoyNote = pitchG4;

      midiCommand(0x90, secondJoyNote, 127);
      delay(50);
    }
    if (secondJoyVal >= 292 && secondJoyVal < 438) { //PLAY F4

      //play the note
      midiCommand(0x80, secondJoyNote, 0);
      secondJoyNote = pitchF4;

      midiCommand(0x90, secondJoyNote, 127);
      delay(50);
    }
    if (secondJoyVal >= 438 && secondJoyVal < 584) { //PLAY E4

      //play the note
      midiCommand(0x80, secondJoyNote, 0);
      secondJoyNote = pitchE4;

      midiCommand(0x90, secondJoyNote, 127);
      delay(50);
    }
    if (secondJoyVal >= 584 && secondJoyVal < 730) { //PLAY D4

      //play the note
      midiCommand(0x80, secondJoyNote, 0);
      secondJoyNote = pitchD4;

      midiCommand(0x90, secondJoyNote, 127);
      delay(50);
    }
    if (secondJoyVal >= 730 && secondJoyVal < 876) { //PLAY C4

      midiCommand(0x80, secondJoyNote, 0);
      secondJoyNote = pitchC4;

      midiCommand(0x90, secondJoyNote, 127);
      delay(50);
    }
    if (secondJoyVal >= 876 && secondJoyVal <= 1023) { //PLAY B3

      //play the note
      midiCommand(0x80, secondJoyNote, 0);
      secondJoyNote = pitchB3;

      midiCommand(0x90, secondJoyNote, 127);
      delay(50);
    }




    digitalWrite(secondLEDPin, HIGH);

  } else if (secondNoteState == HIGH) {
    digitalWrite(secondLEDPin, LOW);

    //stop the note
    midiCommand(0x80, secondJoyNote, 0);
  }

  //--------------------------------------------

  //---------------BUTTON 3-----------------------//

  //  Serial.print(" | ");
  //  Serial.print("buttonState:");
  //  Serial.println(firstNoteState);

  if (thirdButtonVal != formerThirdButton) {
    if (thirdButtonVal == LOW && thirdNoteState == HIGH) {
      thirdNoteState = LOW;
    } else if (thirdButtonVal == LOW && thirdNoteState == LOW) {
      thirdNoteState = HIGH;
    }
    delay(50);
  }
  formerThirdButton = thirdButtonVal;


  //--------------JOYSTICK 3-------------------//
  //divided the range of input values equally among the 7 possible notes

  if (thirdNoteState == LOW) { //only run this code if the button is pressed


    if (thirdJoyVal >= 0 && thirdJoyVal < 146) { //PLAY A4

      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchA4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(50);
    }
    if (thirdJoyVal >= 146 && thirdJoyVal < 292) { //PLAY G4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchG4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(50);
    }
    if (thirdJoyVal >= 292 && thirdJoyVal < 438) { //PLAY F4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchF4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(50);
    }
    if (thirdJoyVal >= 438 && thirdJoyVal < 584) { //PLAY E4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchE4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(50);
    }
    if (thirdJoyVal >= 584 && thirdJoyVal < 730) { //PLAY D4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchD4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(50);
    }
    if (thirdJoyVal >= 730 && thirdJoyVal < 876) { //PLAY C4

      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchC4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(50);
    }
    if (thirdJoyVal >= 876 && thirdJoyVal <= 1023) { //PLAY B3

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchB3;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(50);
    }




    digitalWrite(thirdLEDPin, HIGH);

  } else if (thirdNoteState == HIGH) {
    digitalWrite(thirdLEDPin, LOW);

    //stop the note
    midiCommand(0x80, thirdJoyNote, 0);
  }

  //--------------------------------------------

  //---------------BUTTON 3-----------------------//

  //  Serial.print(" | ");
  //  Serial.print("buttonState:");
  //  Serial.println(firstNoteState);

  if (fourthButtonVal != formerFourthButton) {
    if (fourthButtonVal == LOW && fourthNoteState == HIGH) {
      fourthNoteState = LOW;
    } else if (fourthButtonVal == LOW && fourthNoteState == LOW) {
      fourthNoteState = HIGH;
    }
    delay(50);
  }
  formerFourthButton = fourthButtonVal;


  //--------------JOYSTICK 3-------------------//
  //divided the range of input values equally among the 7 possible notes

  if (fourthNoteState == LOW) { //only run this code if the button is pressed


    if (fourthJoyVal >= 0 && fourthJoyVal < 146) { //PLAY A4

      midiCommand(0x80, fourthJoyNote, 0);
      fourthJoyNote = pitchA4;

      midiCommand(0x90, fourthJoyNote, 127);
      delay(50);
    }
    if (fourthJoyVal >= 146 && fourthJoyVal < 292) { //PLAY G4

      //play the note
      midiCommand(0x80, fourthJoyNote, 0);
      fourthJoyNote = pitchG4;

      midiCommand(0x90, fourthJoyNote, 127);
      delay(50);
    }
    if (fourthJoyVal >= 292 && fourthJoyVal < 438) { //PLAY F4

      //play the note
      midiCommand(0x80, fourthJoyNote, 0);
      fourthJoyNote = pitchF4;

      midiCommand(0x90, fourthJoyNote, 127);
      delay(50);
    }
    if (fourthJoyVal >= 438 && fourthJoyVal < 584) { //PLAY E4

      //play the note
      midiCommand(0x80, fourthJoyNote, 0);
      fourthJoyNote = pitchE4;

      midiCommand(0x90, fourthJoyNote, 127);
      delay(50);
    }
    if (fourthJoyVal >= 584 && fourthJoyVal < 730) { //PLAY D4

      //play the note
      midiCommand(0x80, fourthJoyNote, 0);
      fourthJoyNote = pitchD4;

      midiCommand(0x90, fourthJoyNote, 127);
      delay(50);
    }
    if (fourthJoyVal >= 730 && fourthJoyVal < 876) { //PLAY C4

      midiCommand(0x80, fourthJoyNote, 0);
      fourthJoyNote = pitchC4;

      midiCommand(0x90, fourthJoyNote, 127);
      delay(50);
    }
    if (fourthJoyVal >= 876 && fourthJoyVal <= 1023) { //PLAY B3

      //play the note
      midiCommand(0x80, fourthJoyNote, 0);
      fourthJoyNote = pitchB3;

      midiCommand(0x90, fourthJoyNote, 127);
      delay(50);
    }




    digitalWrite(fourthLEDPin, HIGH);

  } else if (fourthNoteState == HIGH) {
    digitalWrite(fourthLEDPin, LOW);

    //stop the note
    midiCommand(0x80, fourthJoyNote, 0);
  }

  //--------------------------------------------
}


// send a 3-byte midi message
void midiCommand(byte cmd, byte data1, byte  data2) {
  // First parameter is the event type (top 4 bits of the command byte).
  // Second parameter is command byte combined with the channel.
  // Third parameter is the first data byte
  // Fourth parameter second data byte

  midiEventPacket_t midiMsg = {cmd >> 4, cmd, data1, data2};
  MidiUSB.sendMIDI(midiMsg);
}
