#include <Arduino.h>
#include "AFMotor_R4.h"

AF_DCMotor motor1(1);

void setup() {
  motor1.setSpeed(200);
  motor1.run(FORWARD);
}

void loop() {
  
}
