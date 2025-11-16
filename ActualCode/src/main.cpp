#include <Arduino.h>
#include "AFMotor_R4.h"

#define FAST 100
#define SLOW 50
AF_DCMotor motorL(3);
AF_DCMotor motorR(1);
volatile int photo;

void checkLine();

void setup() {
  Serial.begin(9600);
  motorL.setSpeed(0);
  motorR.setSpeed(0);
  motorL.run(FORWARD);
  motorR.run(FORWARD);
}

void loop() {
  checkLine();
  if(photo == HIGH){
    //Line detected
    motorL.setSpeed(FAST);
    motorR.setSpeed(SLOW);
  } else {
    //Line not detected
    motorL.setSpeed(SLOW);
    motorR.setSpeed(FAST);
  }
  
  delay(300);
}

void checkLine(){
  //Converts analog input from the photo sensor into HIGH or LOW
  if(analogRead(A0) >= 700){
    photo = HIGH;
    Serial.println("DETECTED");
  } else {
    photo = LOW;
    Serial.println("NOT DETECTED");

  }
}