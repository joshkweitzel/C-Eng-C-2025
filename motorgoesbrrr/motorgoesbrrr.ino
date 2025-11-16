#include <Arduino.h>
#include "AFMotor_R4.h"

AF_DCMotor motor(1);
void setup() {
  motor.setSpeed(200);  // Set speed (0-255)
  motor.run(FORWARD);   // Start motor
}

void loop() {
  

}
