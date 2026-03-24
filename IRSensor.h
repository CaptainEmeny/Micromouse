#pragma once
#include <Arduino.h>

class IRSensor{

  public:

    IRSensor(uint8_t pin = 255);
    bool getSensor();

  private:
    int IRPin;

};