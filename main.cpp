#include <WProgram.h>
#include "Motor.h"
#include "MotorControl.h"
#include "PID_v1.h"
#include <HardwareSerial.h>
#include "main.h"
/* *
 * Pin Sheet Setup
 * */
const int L_CT1 = 9;
const int L_CT2 = 8;
const int L_CT3 = 7;
const int R_CT1 = 10;
const int R_CT2 = 5;
const int R_CT3 = 4;

/**
 * Impulse Interrupt Setting up
 */
const int L_INTERRUPT = 1;
const int R_INTERRUPT = 0;
int R_COUNT = 0;
int L_COUNT = 0;

/**
 * construcor for whole parts
 */

/*two side motors*/
Motor lMotor(L_CT1, L_CT2, L_CT3);
Motor rMotor(R_CT1, R_CT2, R_CT3);

/*two counter for both side*/
MotorCounter lCounter;
MotorCounter rCounter;

#define        Kp_L                0.32
#define        Ki_L                0.42
#define        Kd_L                0.03

double eSpeed = 50;
double nowSpeed = 0;
double outPwm;

PID leftPid(&nowSpeed, &outPwm, &eSpeed, Kp_L, Ki_L, Kd_L, DIRECT);

/*main motor control*/
MotorControl motorCtl(lMotor, rMotor);

/**
 * Interrupt function
 * */
void rImpulseFunction() {
	rCounter.addOneCount();
}
void lImpluseFunction() {
	lCounter.addOneCount();
}

int main(void) {
	init();

	setup();

	for (;;)
		loop();

	return 0;
}
long startTime;
long endTime;

void setup() {
	Serial.begin(9600);
	attachInterrupt(L_INTERRUPT, lImpluseFunction, CHANGE);
	attachInterrupt(R_INTERRUPT, rImpulseFunction, CHANGE);
	motorCtl.forward(100);
	leftPid.SetMode(AUTOMATIC);
}

void loop() {
	if ((endTime = millis()) % 100 == 0) {
		nowSpeed = lCounter.getCount();
		Serial.print(nowSpeed);
		leftPid.Compute();
		lCounter.clearCount();
		Serial.print(nowSpeed);
		Serial.print("    &    ");
		Serial.println(outPwm);
		motorCtl.forward(outPwm);
	}
}

