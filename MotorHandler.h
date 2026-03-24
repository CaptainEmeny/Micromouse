#pragma once
#include "Motor.h"

class MotorHandler{

  public:
    MotorHandler(uint8_t in1 = 255, uint8_t in2 = 255, uint8_t in3 = 255, uint8_t in4 = 255);

    void bothCounter();
    void bothClock();
    void onlyRightCounter();
    void onlyLeftCounter();
    void leftCounterRightClock();
    void leftClockRightCounter();

    void bothStop();



  private:
    Motor leftMotor;
    Motor rightMotor;

};