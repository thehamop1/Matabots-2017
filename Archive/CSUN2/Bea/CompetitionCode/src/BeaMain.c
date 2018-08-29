#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in8,    Gyro,           sensorGyro)
#pragma config(Sensor, dgtl2,  REnc,           sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  ConeLiftEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  LEnc,           sensorQuadEncoder)
#pragma config(Sensor, dgtl11, LiftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  ClawEnc,        sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           LEdgeMots,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           REdgeMots,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           Claw,          tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port5,           ConeLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LiftMotor2,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LiftMotor1,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LInsideMots,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           RInsideMots,   tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/


// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
#include "robotSetup.h"
#include "AutonRun.h"
#include "Variables.h"
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;
	nMotorEncoder[ClawEnc] = 0;
	resetChassisEnc();
	robotSetup();
	setupController();
	resetChassisEnc();
	resetGyro();
	intializeSensorValues();
	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
  // ..........................................................................
  // Insert user code here.
  // ..........................................................................

  // Remove this function call once you have "real" code.

	autonGo();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
    controllerInputs();
    outputSensorData();
  	// This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    // Remove this function call once you have "real" code.
  }
}