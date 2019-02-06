/* Encoder Library - Basic Example
   http://www.pjrc.com/teensy/td_libs_Encoder.html

   This example code is in the public domain.
*/
/*
  Pushbutton Time Set

  created 22 April 2018
  by Tom Igoe
*/

#include <Encoder.h>

const int tiltPin = 2;
const int rotaryPinA = 3;
const int rotaryPinB = 4;
const int rotaryButton = 5;
const int stateButton = 6;

int buttonState = HIGH;
int tiltState = HIGH;
int rotState = 0;

int oldRot = HIGH;
int oldButton = HIGH;
long oldTilt = -999;

unsigned long lastDebounceRot = 0;  // the last time the rotary was turned
unsigned long debounceDelayRot = 10;
unsigned long lastDebounceTilt = 0;  // the last time the tilt was toggled
unsigned long debounceDelayTilt = 500;



int timeOrTimer = 1; //variable that determines if in the time or timer state
int timerState = 1; //stores if timer is on or off
int valUpdateCheck = 0;


//Encoder setup and value variable
Encoder myEnc(rotaryPinA, rotaryPinB);
long oldPosition  = -999;


//these are variables to store actual time
int hours = 1;
int minutes = 1;
int seconds = 0;
int oldSeconds = 0;
long lastCount = 0; // count of millis since last second

//these are variables to store timer info
int timerHours = 0;
int timerMinutes = 1;
int timerSeconds = 1;
int oldTimerSeconds = 0;
long timerLastCount = 0; // count of millis since last second




void setup() {
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");

  pinMode(tiltPin, INPUT_PULLUP);
  pinMode(rotaryButton, INPUT_PULLUP);
  pinMode(stateButton, INPUT_PULLUP);

}

void loop() {
  //******************RECORD AND FILTER ALL INPUTS********************

  //------ - //record rotary push button//-----------------
  int buttonState = digitalRead(rotaryButton);
  //-------------------------------------------------------- -


  //------ - //record tilt switch//-----------------
  // read the state of the switch into a local variable:
  int readingTilt = digitalRead(tiltPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (readingTilt != oldTilt) {
    // reset the debouncing timer
    lastDebounceTilt = millis();
  }

  if ((millis() - lastDebounceTilt) > debounceDelayTilt) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (readingTilt != tiltState) {
      tiltState = readingTilt;
    }
  }
  //-------------------------------------------------------- -

  //------- //record rotary encoder//-----------------
  // read the state of the switch into a local variable:
  int readingRot = myEnc.read();

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (readingRot != oldRot) {
    // reset the debouncing timer
    lastDebounceRot = millis();
  }

  if ((millis() - lastDebounceRot) > debounceDelayRot) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (readingRot != rotState) {
      rotState = readingRot;
    }
  }
  //-------------------------------------------------------- -


  //*******************************************************************

  //*************APPLY INPUTS FROM BUTTON AND ENCODER**************//

  //check if rotary button has changed. If so change value of timeOrTimer
  if (buttonState != oldButton) {
    delay(8);                         // wait for debounce delay
    if (buttonState == LOW) {

      timeOrTimer = timeOrTimer * -1;
    }
  }

  //-------------------------------------------------

  //checks if rotary knob is being turned and if so updates the correct value//
  if (rotState != oldRot) {
    delay(20);                         // wait for debounce delay
    if (rotState > oldRot) {   //if in time mode, dial updates time
      if (timeOrTimer == 1) {
        minutes++;
      } else if (timeOrTimer == -1) { //if in timer mode dial updates timer
        timerMinutes++;
      }
    }
    if (rotState < oldRot) {
      if (timeOrTimer == 1) {
        minutes--;
      } else if (timeOrTimer == -1) { //if in timer mode dial updates timer
        timerMinutes--;
      }
    }
  }
  //----------------------------------------------------

  //*************************************************************//


  //--------------------UPDATING THE TIME CLOCK//---------------
  // count the milliseconds, update second when 1000ms have passed:
  if (millis() - lastCount > 1000) {
    seconds++;
    lastCount = millis();
    if (seconds > 59) {   // rollover seconds and update minutes
      seconds = 0;
      minutes++;
    }
    if (minutes > 59) {   // rollover minutes and update hours
      minutes = 0;
      hours++;
    }
    if (hours > 12) {     // rollover hours
      hours = 0;
    }
  }

  //--------------------------------------------------------------

  //checks the state of timeOrTimer button to see if time or timer should show

  if (timeOrTimer == 1) {  //if button is set to time, then show time
   
      Serial.print("Time - ");
      // print the time:
      if (hours < 10) Serial.print("0");    // leading zero
      Serial.print(hours);
      Serial.print(":");
      if (minutes < 10) Serial.print("0");  // leading zero
      Serial.print(minutes);
      Serial.print(":");
      if (seconds < 10) Serial.print("0");  // leading zero
      Serial.println(seconds);


  } else {     //if button is set to timer, then allow for controls of timer and show timer

    //if there is time left on the timer, then count down the timer


    if (tiltState == 0) {  //check if tilt button changed. if so then start updating the timer
      if (timerHours != 0 || timerMinutes != 0 || timerSeconds != 0) { // //UPDATING THE TIMER//

        if (millis() - timerLastCount > 1000) {
          timerSeconds--;
          timerLastCount = millis();
          //store the former seconds val to later check if timer is done

          if (timerSeconds < 0) {   // rollover seconds and update minutes
            timerSeconds = 59;
            timerMinutes--;
          }
          if (timerMinutes < 0) {   // rollover minutes and update hours
            timerMinutes = 59;
            timerHours--;
          }
        }
        //if all values are zero and the former seconds val was 1, then print "Timer is Complete"
      } else if (timerHours == 0 && timerMinutes == 0 && timerSeconds == 0) {
        Serial.println("Timer is Done");
      }
    }


    // print the timer even if timer is not counting down if the seconds changed
//    if (timerSeconds != oldTimerSeconds) {
      Serial.print("Timer - ");
      if (timerHours < 10) Serial.print("0");    // leading zero
      Serial.print(timerHours);
      Serial.print(":");
      if (timerMinutes < 10) Serial.print("0");  // leading zero
      Serial.print(timerMinutes);
      Serial.print(":");
      if (timerSeconds < 10) Serial.print("0");  // leading zero
      Serial.println(timerSeconds);
      oldTimerSeconds = timerSeconds;
    }
//  }

  //---------UPDATE ALL OLD STATE VARIABLES
  oldButton = buttonState;
  oldTilt = readingTilt;
  oldRot = readingRot;

}

