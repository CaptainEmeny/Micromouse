#pragma once

#include "MotorHandler.h"
#include "IRSensorHandler.h"

class Mouse{

  public:
    Mouse();

    void initMotors(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4);
    void initSensors(uint8_t frontPin, uint8_t leftPin, uint8_t rightPin);

    //Movements
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    
    void turnInPlaceRight();
    void turnInPlaceLeft();

    void stopMoving();

    //Sensors
    bool anyWallDetected();



  private:
    MotorHandler mouseMotors;
    IRSensorHandler mouseSensors;

};