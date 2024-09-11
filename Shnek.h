#include <Stepper.h>

class Shnek {
  public:
    Shnek(int pin1, int pin2, int pin3, int pin4, int stepsPerTurn, int speed): 
      myStepper(stepsPerTurn, pin1, pin2, pin3, pin4), 
      stepsPerTurn(stepsPerTurn),
      speed(speed) 
      {
        this->myStepper.setSpeed(speed);
        this->degreesPerStep = 360.0 / stepsPerTurn;
      }

    void turnDegrees(int degrees) {
      this->myStepper.step(degrees2steps(degrees));
    }

    void turnSteps(int steps) {
      this->myStepper.step(steps);
    }

  private:
    int stepsPerTurn;
    int speed;
    Stepper myStepper;
    float degreesPerStep;

    int degrees2steps(int degrees) {
      return round(degrees * degreesPerStep);
    }
};
