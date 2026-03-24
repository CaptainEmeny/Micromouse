#pragma once
#include <Arduino.h>

class Motor{

  public:
    Motor(uint8_t in1, uint8_t in2);

    void forward();
    void backward();
    void stop();

  private:
    int IN1, IN2;
};