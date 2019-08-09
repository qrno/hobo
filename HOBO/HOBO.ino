#include "ir.h"
#include "motor.h"
#include "color.h"

IR left(A13);
IR center(A14);
IR right(A15);

void setup() {
  setupMotors();
  Serial.begin(9600);
}

void loop() {
    if (center.isBlack() && 
          (!right.isBlack() && !left.isBlack())) drive(FRONT);
    else if (right.isBlack()) drive(LEFT);
    else if (left.isBlack()) drive(RIGHT);
    else drive(FRONT);
}
