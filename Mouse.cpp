#include "Mouse.h"

Mouse::Mouse(){}

//Sets the motor pins for the mouse program
void Mouse::initMotors(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4){
  mouseMotors = MotorHandler(in1, in2, in3, in4);
}

void Mouse::initSensors(uint8_t frontPin, uint8_t leftPin, uint8_t rightPin){
  mouseSensors = IRSensorHandler(frontPin, leftPin, rightPin);
}

//Commands the mouse motor movements
void Mouse::moveForward(){mouseMotors.bothCounter();}
void Mouse::moveBackward(){mouseMotors.bothClock();}
void Mouse::moveLeft(){mouseMotors.onlyRightCounter();}
void Mouse::moveRight(){mouseMotors.onlyLeftCounter();}

void Mouse::turnInPlaceRight(){mouseMotors.leftCounterRightClock();}
void Mouse::turnInPlaceLeft(){mouseMotors.leftClockRightCounter();}


void Mouse::stopMoving(){mouseMotors.bothStop();}


bool Mouse::anyWallDetected(){return mouseSensors.anySensorsTriggered();}
