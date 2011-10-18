/*
 * Motor.cpp
 *
 *  Created on: 2011-10-17
 *      Author: Akira.Pan
 */

#include "Motor.h"
#include <WProgram.h>
#include <HardwareSerial.h>
Motor::Motor() {

}

Motor::Motor(int ct1, int ct2, int ct3) {
	this->_ct1 = ct1;
	this->_ct2 = ct2;
	this->_ct3 = ct3;
	this->init();
}

void Motor::init() {
	pinMode(this->_ct1, OUTPUT);
	pinMode(this->_ct2, OUTPUT);
	pinMode(this->_ct3, OUTPUT);
	this->_speed = 0;
	analogWrite(this->_ct1, this->_speed);
	digitalWrite(this->_ct2, LOW);
	digitalWrite(this->_ct3, LOW);

}

void Motor::setSpeed(int speed) {
	this->_speed = speed;
	analogWrite(this->_ct1, this->_speed);
}

void Motor::forward() {
	digitalWrite(this->_ct2, HIGH);
	digitalWrite(this->_ct3, LOW);
}

void Motor::forward(int speed) {
	this->setSpeed(speed);
	this->forward();

}
void Motor::backward() {
	digitalWrite(this->_ct2, LOW);
	digitalWrite(this->_ct3, HIGH);
}

void Motor::backward(int speed) {
	this->setSpeed(speed);
	this->backward();
}

void Motor::stop() {
	this->setSpeed(0);
	digitalWrite(this->_ct2, LOW);
	digitalWrite(this->_ct3, LOW);
}

void Motor::slide() {
	digitalWrite(this->_ct1, LOW);
	digitalWrite(this->_ct2, HIGH);
	digitalWrite(this->_ct3, HIGH);
}

