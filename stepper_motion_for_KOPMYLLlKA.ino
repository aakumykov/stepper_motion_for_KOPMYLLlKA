#include <Arduino.h>
#include <EncButton.h>
EncButton eb(8, 9, 2);
int currentPosition = 0;
int lastCount = 0;

#include "Shnek.h"
Shnek shnek(3,4,5,6,200,60);

void setup() {
  Serial.begin(9600);
  Serial.println("stepper_motor_for_KOPMYLLlKA, setup()");
}

void loop() {
  eb.tick();

  if (eb.click()) {
    Serial.println("click");
  }

  if (eb.turn()) {
    // myStepper.step(eb.dir()*10);
    shnek.turnSteps(eb.dir() * 10);
  }

  // step one revolution  in one direction:
  // Serial.println("clockwise");
  // myStepper.step(10);
  // // delay(10);

  // // step one revolution in the other direction:
  // Serial.println("counterclockwise");
  // myStepper.step(-5);
  // delay(10);
}

void changePosition(int32_t count, int8_t direction) {
  // Serial.print("поворот: "); Serial.print(count); Serial.print(" ("); Serial.print(direction); Serial.println(")");
  Serial.println(direction);
}