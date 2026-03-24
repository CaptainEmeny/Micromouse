#pragma once

#include "IRSensor.h"

IRSensor::IRSensor(uint8_t pin) : IRPin(pin) {
  pinMode(pin, INPUT);
};

/**
  * @brief Gets whether a sensor picks up an object or not.
  *
  * @note This will return the OPPOSITE of that is usually read, and will
  * actually return HIGH when it detects an object to make understanding 
  * the output more understandable. 
  * 
  * @returns If object is detected by sensor
  */
bool IRSensor::getSensor(){
  return !digitalRead(IRPin);
};