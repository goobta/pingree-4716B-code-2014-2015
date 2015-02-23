#pragma config(Motor,  port2,           driveRight,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           driveLeft,     tmotorVex393, openLoop)
#pragma config(Motor,  port4,           builder,       tmotorVex393, openLoop)
#pragma config(Motor,  port5,           cube,          tmotorVex393, openLoop)
#pragma config(Motor,  port6,           liftLeftTop,   tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           liftLeftBack,  tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           liftRightTop,  tmotorVex393, openLoop)
#pragma config(Motor,  port9,           liftRightBack, tmotorVex393, openLoop)

////////////////////////////////// Functions //////////////////////////////////

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

void cubeClaw(int power) {
	motor[cube] = power;
}

////////////////////////////////// Functions be Done //////////////////////////////////

task main()
{
	driveTrainLeft(127);
	driveTrainRight(-127);
	wait1Msec(500);

	// driveTrainLeft(127);
	// driveTrainRight(-127);
	// builderClaw(0);
	// wait1Msec(250);

	// drive(-127);
	// wait1Msec(250);

	// builderClaw(-127);
	// drive(0);
	// wait1Msec(250);

	// builderClaw(0);
	// drive(-127);
	// wait1Msec(300);

	// drive(0);
	// driveTrainRight(-127);
	// driveTrainLeft(127);
	// wait1Msec(100);

	// drive(127);
	// wait1Msec(500);

	// drive(0);
	// builderClaw(-127);
	// wait1Msec(250);

	// builderClaw(0);
	// wait1Msec(10);
}
