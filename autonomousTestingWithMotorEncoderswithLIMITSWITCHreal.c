#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  limitSwitch,    sensorTouch)
#pragma config(Sensor, I2C_1,  rightIEM,       sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  leftIEM,        sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port2,           driveRight,    tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port3,           driveLeft,     tmotorVex393, openLoop, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port4,           builder,       tmotorVex393, openLoop)
#pragma config(Motor,  port5,           cube,          tmotorVex393, openLoop)
#pragma config(Motor,  port6,           liftLeftTop,   tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           liftLeftBack,  tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           liftRightTop,  tmotorVex393, openLoop)
#pragma config(Motor,  port9,           liftRightBack, tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////


void drive(int power) {
	motor[driveLeft] = power;
	motor[driveRight] = power;
}

void driveTrainLeft(int power) {
	motor[driveLeft] = power;
}


void driveTrainRight(int power) {
	motor[driveRight] = power;
}

void lift(int power) {
	motor[liftLeftBack] = power;
	motor[liftLeftTop] = power;
	motor[liftRightTop] = power;
	motor[liftRightBack] = power;
}

void builderClaw(int power) {
	motor[builder] = power;
}
void builderClawClose() {
	while(SensorValue[limitSwitch] != 1) {
		builderClaw(127);
	}

	builderClaw(0);
	wait1Msec(10);
}

void builderClawOpen() {
	while(SensorValue[limitSwitch] == 1) {
		builderClaw(-127);
	}
	builderClaw(127);
	wait1Msec(150);

	builderClaw(0);
	wait1Msec(10);
}

void cubeClaw(int power) {
	motor[cube] = power;
}

void resetEncoders() {
	nMotorEncoder[driveRight] = 0;
	nMotorEncoder[driveLeft] = 0;
}

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................

	resetEncoders();

	while(nMotorEncoder[driveRight] <= 600) {
		drive(75);
	}

	drive(-20);
	wait1Msec(75);

	resetEncoders();

	drive(0);
	wait1Msec(10);

	while(nMotorEncoder[driveLeft] <= 330)  {
		driveTrainLeft(90);
		driveTrainRight(-90);
	}

	resetEncoders();

	drive(0);
	wait1Msec(10);

	builderClawOpen();

  builderClaw(0);
	wait1Msec(500);

	while(nMotorEncoder[driveRight] > -850) {
		drive(-80);
	}

	drive(0);
	wait1Msec(50);

	builderClawClose();

	lift(127);
	wait1Msec(950);

	lift(0);
	wait1Msec(10);

	resetEncoders();
	while(nMotorEncoder[driveRight] < 425) {
		drive(127);
	}

	drive(0);
	wait1Msec(10);

	resetEncoders();
	while(nMotorEncoder[driveLeft] <= 658) {
		driveTrainLeft(80);
		driveTrainRight(-80);
	}

	resetEncoders();
	while(nMotorEncoder[driveLeft] >= -40) {
		drive(-80);
	}

	drive(0);
	wait1Msec(10);
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
	  // This is the main execution loop for the user control program. Each time through the loop
	  // your program should update motor + servo values based on feedback from the joysticks.

	  // .....................................................................................
	  // Insert user code here. This is where you use the joystick values to update your motors, etc.
	  // .....................................................................................
	  int x = 5;
	}
}
