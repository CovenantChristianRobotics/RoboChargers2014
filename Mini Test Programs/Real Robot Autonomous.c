#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Hubs,  S3, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     Touch,          sensorTouch)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     IRSeeker,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S2_C1_1,     mtrSweeper,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     mtrKicker,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_1,     mtrLeft1,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_2,     mtrLeft2,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_1,     mtrRight1,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_2,     mtrRight2,     tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C3_1,    leftWhisker,          tServoStandard)
#pragma config(Servo,  srvo_S2_C3_2,    rightWhisker,         tServoStandard)
#pragma config(Servo,  srvo_S2_C3_3,    Indexer,              tServoStandard)
#pragma config(Servo,  srvo_S2_C3_4,    latch,                tServoNone)
#pragma config(Servo,  srvo_S2_C3_5,    goalDoor,             tServoNone)
#pragma config(Servo,  srvo_S2_C3_6,    servo6,               tServoNone)
#pragma config(Servo,  srvo_S3_C3_3,    servo9,               tServoNone)
#pragma config(Servo,  srvo_S3_C3_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S3_C3_6,    servo12,              tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Autonomous Mode Code Template
//
// This file contains a template for simplified creation of an autonomous program for an TETRIX robot
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "hitechnic-irseeker-v2.h"
#include "hitechnic-eopd.h"
#include "lego-touch.h"

#define SPEED 75
#define DEG90 1000
#define DEG45 (DEG90 / 2)

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of autonomous mode, you may want to perform some initialization on your robot.
// Things that might be performed during initialization include:
//   1. Move motors and servos to a preset position.
//   2. Some sensor types take a short while to reach stable values during which time it is best that
//      robot is not moving. For example, gyro sensor needs a few seconds to obtain the background
//      "bias" value.
//
// In many cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
	eraseDisplay();

	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the autonomous robot operation. Customize as appropriate for
// your specific robot.
//
// The types of things you might do during the autonomous phase (for the 2008-9 FTC competition)
// are:
//
//   1. Have the robot follow a line on the game field until it reaches one of the puck storage
//      areas.
//   2. Load pucks into the robot from the storage bin.
//   3. Stop the robot and wait for autonomous phase to end.
//
// This simple template does nothing except play a periodic tone every few seconds.
//
// At the end of the autonomous period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{

	initializeRobot();

		tHTIRS2 irSeeker;

	initSensor(&irSeeker, S4);

	irSeeker.mode = DSP_1200;

	waitForStart(); // Wait for the beginning of autonomous phase.
	readSensor(&irSeeker);

	displayCenteredTextLine(0, "%d", irSeeker.acValues);

	if (irSeeker.acValues[2] < 30)
	{
		displayCenteredTextLine(1, "Position 1");

		motor[mtrLeft1] = SPEED;
		motor[mtrLeft2] = SPEED;

		wait1Msec(DEG45);

		motor[mtrRight1] = -SPEED;
		motor[mtrRight2] = -SPEED;

		wait1Msec(1200);

		motor[mtrLeft1] = 0;
		motor[mtrLeft2] = 0;

		wait1Msec(1200);

		motor[mtrLeft1] = SPEED;
		motor[mtrLeft2] = SPEED;

		wait1Msec(1700);
	}
	else if (irSeeker.acValues[2] < 100)
	{
		displayCenteredTextLine(1, "Position 2");

		motor[mtrLeft1]= SPEED;
		motor[mtrLeft2] = SPEED;
		motor[mtrRight1] = -SPEED;
		motor[mtrRight2] = -SPEED;

		wait1Msec(1400);

		motor[mtrLeft1] = 0;
		motor[mtrLeft2] = 0;

		wait1Msec(300);

		motor[mtrLeft1] = SPEED;
		motor[mtrLeft2] = SPEED;

		wait1Msec(2000);

	}
	else
	{
		displayCenteredTextLine(1, "Position 3");

		motor[mtrRight1] = -SPEED;
		motor[mtrRight2] = -SPEED;
		motor[mtrLeft1] = SPEED;
		motor[mtrLeft2] = SPEED;

		wait1Msec(1400);

		motor[mtrRight1] = 80;
		motor[mtrRight2] = 80;
		motor[mtrLeft1] = -80;
		motor[mtrLeft2] = -80;

		wait1Msec(10);

		motor[mtrRight1] = 0;
		motor[mtrRight2] = 0;
		motor[mtrLeft1] = 0;
		motor[mtrLeft2] = 0;

		wait1Msec(1500);

		motor[mtrRight1] = 0;
		motor[mtrRight2] = 0;
		motor[mtrLeft1] = -25;
		motor[mtrLeft2] = -25;

		wait1Msec(DEG90);

		motor[mtrRight1] = -SPEED;
		motor[mtrRight2] = -SPEED;
		motor[mtrLeft1] = SPEED;
		motor[mtrLeft2] = SPEED;

		wait1Msec(1000);

		motor[mtrRight1] = 25;
		motor[mtrRight2] = 25;
		motor[mtrLeft1] = 0;
		motor[mtrLeft2] = 0;

		wait1Msec(DEG90);

		motor[mtrLeft1] = SPEED;
		motor[mtrLeft2] = SPEED;
		motor[mtrRight1] = -SPEED;
		motor[mtrRight2] = -SPEED;

		wait1Msec(1200);

	}
	motor[mtrRight1] = 0;
	motor[mtrRight2] = 0;
	motor[mtrLeft1] = 0;
	motor[mtrLeft2] = 0;

	while (true)
	{}
}
