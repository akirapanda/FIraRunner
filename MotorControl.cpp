#include "MotorControl.h"
#include "math.h"

MotorControl::MotorControl() {
}
MotorControl::MotorControl(Motor leftMotor, Motor rightMotor) {
	this->_leftMotor=leftMotor;
	this->_rightMotor=rightMotor;
}

void MotorControl::forward(int speed) {
	this->_leftMotor.forward(speed);
	this->_rightMotor.forward(speed);
}

void MotorControl::backward(int speed) {
	this->_leftMotor.backward(speed);
	this->_rightMotor.backward(speed);
}
void MotorControl::turnLeft() {
	this->_rightMotor.forward(this->TURN_AROUND_SPEED);
	this->_leftMotor.backward(this->TURN_AROUND_SPEED);
}

void MotorControl::turnRight() {
	this->_leftMotor.forward(this->TURN_AROUND_SPEED);
	this->_rightMotor.backward(this->TURN_AROUND_SPEED);
}
/**
 */
MotorCounter::MotorCounter() {
	this->_currentCount=0;
}

void MotorCounter::addOneCount() {
	this->_currentCount++;
}

void MotorCounter::clearCount() {
	this->_currentCount=0;
}

int MotorCounter::getCount() {
	return this->_currentCount;
}
/* *
 * Cycle Part
 * */
float Cycle::getCircumference() {
	return M_PI*this->_diameter;
}

void Cycle::setCounter(int count) {
	this->_count=count;
}
void Cycle::setDiameter(float diameter) {
	this->_diameter=diameter;
}

float Cycle::oneCountLength() {
	return this->getCircumference()/this->_count;
}