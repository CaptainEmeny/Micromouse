#pragma once

#include "MotorHandler.h"
#include "IRSensor.h"

#define FRONT      12
#define LEFT        8
#define RIGHT       9
#define LEFT_45    11
#define RIGHT_45   10

class Mouse{

  public:
    Mouse();

    void initMotors(uint8_t in1, uint8_t in2, uint8_t in3, uint8_t in4);
    void initSensors(uint8_t frontPin, uint8_t leftPin, uint8_t rightPin, uint8_t left45Pin, uint8_t right45Pin);

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
    bool wallDetected(uint8_t sensorPin);



  private:
    MotorHandler mouseMotors;

    IRSensor frontSensor;
    IRSensor leftSensor;
    IRSensor rightSensor;
    IRSensor left45Sensor;
    IRSensor right45Sensor;
};