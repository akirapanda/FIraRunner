#ifndef MOTORCONTROL_H_
#define MOTORCONTROL_H_

#include "Motor.h"

/**
 * �������
 */
class MotorCounter {
public:
	MotorCounter();
	void addOneCount();
	void setImpulseWidth(float width);
	void clearCount();
	int getCount();
private:
	int _currentCount;
	float _impulseWidth;
};
/**
 * ��챲���
 */
class Cycle {
	/**
	 * ��ȡ���ӵĵ�Ȧ����
	 */
	void setDiameter(float diameter);
	void setCounter(int _count);
	float getCircumference();
	float oneCountLength();
private:
	float _diameter;
	int _count;
};

/**
 *  �������
 */
class MotorControl {
public:
	MotorControl();
	MotorControl(Motor leftMotor, Motor rightMotor);

	static const int TURN_AROUND_SPEED=100;

	void forward(int speed);
	void backward(int speed);
	void turnLeft();
	void turnRight();
	void setBothCounter(MotorCounter left, MotorCounter rigth);
private:
	Motor _leftMotor;
	Motor _rightMotor;
	Cycle _leftCycle;
	Cycle _rightCycle;
};

#endif /*MOTORCONTROL_H_*/
