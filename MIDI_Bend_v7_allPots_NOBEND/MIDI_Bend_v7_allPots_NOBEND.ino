

#include <pitchToNote.h>
#include <MIDIUSB_Defs.h>
#include <MIDIUSB.h>

//NOTE VARIABLES
const int thirdPin = A1;
const int thirdPin = A2;
const int thirdPin = A3;
const int fourthPin = A4;
const int notePin = A5;

int thirdJoyNote;
int thirdJoyNote;
int thirdJoyNote;
int fourthJoyNote;

int formerthirdJoyNote = pitchC4;
int formerSecondJoyNote = pitchC4;
int formerThirdJoyNote = pitchC4;
int formerFourthJoyNote = pitchC4;

//PITCH BEND VARIABLES

int thirdPitchBend;
int thirdPitchBend;
int thirdPitchBend;
int fourthPitchBend;

int thirdMappedBend;
int thirdMappedBend;
int thirdMappedBend;
int fourthMappedBend;

int thirdJoyVal = 0;
int thirdJoyVal = 255;
int thirdJoyVal = 510;
int fourthJoyVal = 765;

//BUTTON VARIABLED

const int thirdButtonPin = 8;
const int thirdButtonPin = 9;
const int thirdButtonPin = 10;
const int fourthButtonPin = 7;

int thirdButtonVal = 1;
int thirdButtonVal = 1;
int thirdButtonVal = 1;
int fourthButtonVal = 1;

int formerthirdButton = 1;
int formerSecondButton = 1;
int formerThirdButton = 1;
int formerFourthButton = 1;

int thirdNoteState = 1;
int thirdNoteState = 1;
int thirdNoteState = 1;
int fourthNoteState = 1;

//LED VARIABLES

int thirdLEDPin = 12;
int thirdLEDPin = 13;
int thirdLEDPin = 4;
int fourthLEDPin = 3;

int thirdLEDState = 0;
int thirdLEDState = 0;
int thirdLEDState = 0;
int fourthLEDState = 0;

void setup() {

  midiCommand(0x80, formerthirdJoyNote, 0);

  Serial.begin(9600);

  pinMode(thirdButtonPin, INPUT_PULLUP);
  pinMode(thirdButtonPin, INPUT_PULLUP);
  pinMode(thirdButtonPin, INPUT_PULLUP);
  pinMode(fourthButtonPin, INPUT_PULLUP);

  pinMode(thirdLEDPin, OUTPUT);
  pinMode(thirdLEDPin, OUTPUT);
  pinMode(thirdLEDPin, OUTPUT);
  pinMode(fourthLEDPin, OUTPUT);

}

void loop() {


  //------------ -READ INPUTS
  thirdJoyVal = analogRead(thirdPin);
  thirdJoyVal = analogRead(thirdPin);
  thirdJoyVal = analogRead(thirdPin);
  fourthJoyVal = analogRead(fourthPin);

  thirdButtonVal = digitalRead(thirdButtonPin);
  thirdButtonVal = digitalRead(thirdButtonPin);
  thirdButtonVal = digitalRead(thirdButtonPin);
  fourthButtonVal = digitalRead(fourthButtonPin);



  Serial.print(thirdJoyVal);
  Serial.print(" | ");
  Serial.print(thirdJoyVal);
  Serial.print(" | ");
  Serial.println(thirdJoyVal);
  Serial.print(" | ");
  Serial.println(fourthJoyVal);

  //---------------BUTTON 1-----------------------//

//  Serial.print(" | ");
//  Serial.print("buttonState:");
//  Serial.println(thirdNoteState);

  if (thirdButtonVal != formerthirdButton) {
    if (thirdButtonVal == LOW && thirdNoteState == HIGH) {
      thirdNoteState = LOW;
    } else if (thirdButtonVal == LOW && thirdNoteState == LOW) {
      thirdNoteState = HIGH;
    }
    delay(50);
  }
  formerthirdButton = thirdButtonVal;


  //--------------JOYSTICK 1-------------------//
  //divided the range of input values equally among the 7 possible notes

  if (thirdNoteState == LOW) { //only run this code if the button is pressed


    if (thirdJoyVal >= 0 && thirdJoyVal < 146) { //PLAY A4

      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchA4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 146 && thirdJoyVal < 292) { //PLAY G4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchG4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 292 && thirdJoyVal < 438) { //PLAY F4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchF4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 438 && thirdJoyVal < 584) { //PLAY E4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchE4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 584 && thirdJoyVal < 730) { //PLAY D4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchD4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 730 && thirdJoyVal < 876) { //PLAY C4

      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchC4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 876 && thirdJoyVal <= 1023) { //PLAY B3

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchB3;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }




    digitalWrite(thirdLEDPin, HIGH);
    //  midiCommand(0x80, thirdJoyNote, 0);

  } else if (thirdNoteState == HIGH) {
    digitalWrite(thirdLEDPin, LOW);

    //stop the note
    midiCommand(0x80, thirdJoyNote, 0);
  }


//---------------------------

//---------------BUTTON 2-----------------------//

//  Serial.print(" | ");
//  Serial.print("buttonState:");
//  Serial.println(thirdNoteState);

  if (thirdButtonVal != formerSecondButton) {
    if (thirdButtonVal == LOW && fthirdNoteState == HIGH) {
      thirdNoteState = LOW;
    } else if (thirdButtonVal == LOW && thirdNoteState == LOW) {
      thirdNoteState = HIGH;
    }
    delay(50);
  }
  formerSecondButton = thirdButtonVal;


  //--------------JOYSTICK 2-------------------//
  //divided the range of input values equally among the 7 possible notes

  if (thirdNoteState == LOW) { //only run this code if the button is pressed


    if (thirdJoyVal >= 0 && thirdJoyVal < 146) { //PLAY A4

      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchA4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 146 && thirdJoyVal < 292) { //PLAY G4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchG4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 292 && thirdJoyVal < 438) { //PLAY F4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchF4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 438 && thirdJoyVal < 584) { //PLAY E4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchE4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 584 && thirdJoyVal < 730) { //PLAY D4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchD4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 730 && thirdJoyVal < 876) { //PLAY C4

      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchC4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 876 && thirdJoyVal <= 1023) { //PLAY B3

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchB3;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }




    digitalWrite(thirdLEDPin, HIGH);
    //  midiCommand(0x80, thirdJoyNote, 0);

  } else if (thirdNoteState == HIGH) {
    digitalWrite(thirdLEDPin, LOW);

    //stop the note
    midiCommand(0x80, thirdJoyNote, 0);
  }

//-----------------------------------------


//---------------BUTTON 2-----------------------//

//  Serial.print(" | ");
//  Serial.print("buttonState:");
//  Serial.println(thirdNoteState);

  if (thirdButtonVal != formerSecondButton) {
    if (thirdButtonVal == LOW && fthirdNoteState == HIGH) {
      thirdNoteState = LOW;
    } else if (thirdButtonVal == LOW && thirdNoteState == LOW) {
      thirdNoteState = HIGH;
    }
    delay(50);
  }
  formerSecondButton = thirdButtonVal;


  //--------------JOYSTICK 2-------------------//
  //divided the range of input values equally among the 7 possible notes

  if (thirdNoteState == LOW) { //only run this code if the button is pressed


    if (thirdJoyVal >= 0 && thirdJoyVal < 146) { //PLAY A4

      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchA4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 146 && thirdJoyVal < 292) { //PLAY G4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchG4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 292 && thirdJoyVal < 438) { //PLAY F4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchF4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 438 && thirdJoyVal < 584) { //PLAY E4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchE4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 584 && thirdJoyVal < 730) { //PLAY D4

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchD4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 730 && thirdJoyVal < 876) { //PLAY C4

      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchC4;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }
    if (thirdJoyVal >= 876 && thirdJoyVal <= 1023) { //PLAY B3

      //play the note
      midiCommand(0x80, thirdJoyNote, 0);
      thirdJoyNote = pitchB3;

      midiCommand(0x90, thirdJoyNote, 127);
      delay(100);
    }




    digitalWrite(thirdLEDPin, HIGH);
    //  midiCommand(0x80, thirdJoyNote, 0);

  } else if (thirdNoteState == HIGH) {
    digitalWrite(thirdLEDPin, LOW);

    //stop the note
    midiCommand(0x80, thirdJoyNote, 0);
  }

  //  //turn off the note playing this round to prevent repeats
  //  midiCommand(0x80, firstJoyNote, 0);
  //  midiCommand(0x80, secondJoyNote, 0);
  //  midiCommand(0x80, thirdJoyNote, 0);
  //  midiCommand(0x80, fourthJoyNote, 0);

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
