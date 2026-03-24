#pragma once

#include "IRSensor.h"

class IRSensorHandler{

  public:
    IRSensorHandler(uint8_t frontPin = 255, uint8_t leftPin = 255, uint8_t rightPin = 255);


    bool anySensorsTriggered();

  private:
    
    IRSensor frontSensor;
    IRSensor leftSensor;
    IRSensor rightSensor;
};