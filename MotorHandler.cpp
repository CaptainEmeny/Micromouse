#import "MotorHandler.h"

MotorHandler::MotorHandler(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4) : leftMotor(in1, in2), rightMotor(in3, in4) {}


void MotorHandler::bothCounter(){
  leftMotor.forward();
  rightMotor.forward();
}

void MotorHandler::bothClock(){
  leftMotor.backward();
  rightMotor.backward();
}

void MotorHandler::onlyRightCounter(){
  leftMotor.stop();
  rightMotor.forward();
}

void MotorHandler::onlyLeftCounter(){
  leftMotor.forward();
  rightMotor.stop();
}

void MotorHandler::leftCounterRightClock(){
  leftMotor.forward();
  rightMotor.backward();
}

void MotorHandler::leftClockRightCounter(){
  leftMotor.backward();
  rightMotor.forward();
}

void MotorHandler::bothStop(){
  leftMotor.stop();
  rightMotor.stop();
}