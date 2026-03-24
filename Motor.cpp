#include "Motor.h"

Motor::Motor(uint8_t in1, uint8_t in2): IN1(in1), IN2(in2){
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

//Moves the motor Counterclockwise
void Motor::forward(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void Motor::backward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void Motor::stop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}