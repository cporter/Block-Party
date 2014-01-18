#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S3,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S4,     IR,             sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     DriveFL,       tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     DriveBL,       tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     DriveFR,       tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     DriveBR,       tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     FRM,           tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     Lift,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C4_1,     EG1,           tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     EG2,           tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    autoArm,              tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    spinny,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messagesvalidateLongAddresvalidateLongAddresvalidateLongAddresvalidateLongAddress
#include "TeleOp_functions.h"  // an H file that we wrote implementing various functions


const tMotor DriveMotors[] = { DriveFL, DriveBL, DriveFR, DriveBR };  //an array that describes the Drive motors
const tMotor EGMotors[] = {EG1, EG2};


void initializeRobot() {
	servo[autoArm] = 255;
}


task main()
{
	initializeRobot();
	waitForStart();
	while (true)
	{
		getJoystickSettings(joystick);

		operate_Lift(Lift);
		operate_Spinny(spinny);
		operate_FRM(FRM);
		omni_drive(DriveMotors);

	}
}
