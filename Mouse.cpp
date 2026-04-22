#include "Mouse.h"

Mouse::Mouse(){}

//Sets the motor pins for the mouse program
void Mouse::initMotors(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4){
  mouseMotors = MotorHandler(in1, in2, in3, in4);
}

void Mouse::initSensors(uint8_t frontPin, uint8_t leftPin, uint8_t rightPin, uint8_t left45Pin, uint8_t right45Pin){
  frontSensor = frontPin;
  leftSensor = leftPin;
  rightSensor = rightPin;
  left45Sensor = left45Pin;
  right45Sensor = right45Pin;
}

//Commands the mouse motor movements
void Mouse::moveForward(){mouseMotors.bothCounter();}
void Mouse::moveBackward(){mouseMotors.bothClock();}
void Mouse::moveLeft(){mouseMotors.onlyRightCounter();}
void Mouse::moveRight(){mouseMotors.onlyLeftCounter();}

void Mouse::turnInPlaceRight(){mouseMotors.leftCounterRightClock();}
void Mouse::turnInPlaceLeft(){mouseMotors.leftClockRightCounter();}


void Mouse::stopMoving(){mouseMotors.bothStop();}


bool Mouse::anyWallDetected()
      {return (frontSensor.getSensor() || leftSensor.getSensor() || rightSensor.getSensor() || left45Sensor.getSensor() || right45Sensor.getSensor());}

bool Mouse::wallDetected(uint8_t sensorPin){
  switch (sensorPin){
    case FRONT:
      return frontSensor.getSensor();
    case LEFT:
      return leftSensor.getSensor();
    case RIGHT:
      return rightSensor.getSensor();
    case LEFT_45:
      return left45Sensor.getSensor();
    case RIGHT_45:
      return right45Sensor.getSensor();
  }
}

