#include "IRSensorHandler.h"


IRSensorHandler::IRSensorHandler(uint8_t frontPin, uint8_t leftPin, uint8_t rightPin)
  : frontSensor(frontPin), leftSensor(leftPin), rightSensor(rightPin){}


/**
  * @brief Checks whether or not a sensor was triggered, returning true if any of them are HIGH.
  * 
  * @returns TRUE if any sensor was triggered, FALSE if they don't detect anything
  */
bool IRSensorHandler::anySensorsTriggered(){ return (frontSensor.getSensor() || leftSensor.getSensor() || rightSensor.getSensor());}