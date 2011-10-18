/*
 * Motor.h
 *
 *  Created on: 2011-10-17
 *      Author: Administrator
 */

#ifndef MOTOR_H_
#define MOTOR_H_

class Motor {
public:
	Motor();
	Motor(int ct1, int ct2, int ct3);
	void init();
	void setSpeed(int speed);
	void forward();
	void forward(int speed);
	void stop();
	void backward();
	void backward(int speed);
	void slide();

private:
	int _ct1;
	int _ct2;
	int _ct3;
	int _speed;
};

#endif /* MOTOR_H_ */
