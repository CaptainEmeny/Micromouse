#include "Mouse.h"

//Sensor Pins
const int front_sensor_pin = 12;
const int left_sensor_45_pin = 11;
const int right_sensor_45_pin = 10;
const int right_sensor_pin = 9;
const int left_sensor_pin = 8;



const int IN1 = A0;
const int IN2 = A1;
const int IN3 = A2;
const int IN4 = A3;

Mouse mouse;

bool turnCompleted = true;

void setup(){
  Serial.begin(9600);
  //Init the parts of the mouse that will be used
  mouse.initMotors(IN1, IN2, IN3, IN4);
  mouse.initSensors(front_sensor_pin, left_sensor_pin, right_sensor_pin, left_sensor_45_pin, right_sensor_45_pin);
  
  //Start moving the mouse forward
  mouse.moveForward();
}

void loop(){

  //To consider a turn completed, the mouse must have two walls parallel to itself
  if (!turnCompleted){
    turnCompleted = mouse.wallDetected(LEFT) && mouse.wallDetected(RIGHT);

    delay(100);
  }

  //WILL BE USED TO ADJUST THE MOUSE EVERY LOOP.
  if(mouse.wallDetected(LEFT_45)){                      //Adjust Left Side
    Serial.println("Adjusting Left");

    mouse.turnInPlaceLeft();
    delay(50);
    mouse.moveForward();
    delay(100);

  } else if (mouse.wallDetected(RIGHT_45)){             //Adjust Right Side
    Serial.println("Adjusting Right");
    
    mouse.turnInPlaceRight();
    delay(100);
    mouse.moveForward();
    delay(100);
  }

  
  if(!mouse.wallDetected(LEFT) && turnCompleted){             //Look for Left Hole
    Serial.println("Turning Left");
    turnCompleted = false;

    delay(250);
    mouse.turnInPlaceRight();
    delay(600);
    mouse.moveForward();

    delay(200); //Buffer a digitalRead from the mouse turning

  } else if(!mouse.wallDetected(FRONT)) {        //No hole? Go back and try again.
    Serial.println("Moving Forward");

    turnCompleted = false;
    mouse.moveForward();

  } else if (!mouse.wallDetected(RIGHT) && turnCompleted){    //Look for Right Hole
    Serial.println("Turning Right");
    turnCompleted = false;

    delay(250);
    mouse.turnInPlaceLeft();
    delay(600);
    mouse.moveForward();

    delay(200); //Buffer a digitalRead from the mouse turning


  } else if(mouse.wallDetected(FRONT)) {        //No hole? Go back and try again.
      Serial.println("Going back to try again");

      mouse.moveBackward();
      delay(400);
      mouse.turnInPlaceLeft();
      delay(1200);
      mouse.moveForward();
  }

}