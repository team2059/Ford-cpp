#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

#define CODE_VERSION 0.1

/* This file contains all of the constants for initializing items on the robot
 * (Talons, Solenoid, Compressor, etc)
 * Left/Right is determined by looking at the robot from behind
 */

//Drive
#define DRIVE_LEFT_MOTOR_ONE 1
#define DRIVE_LEFT_MOTOR_TWO 2
#define DRIVE_RIGHT_MOTOR_ONE 3
#define DRIVE_RIGHT_MOTOR_TWO 4
#define DRIVE_RIGHT_ENCODER 0
#define DRIVE_LEFT_ENCODER 1

//MainArm
#define ZERO_DEGREES 0.1
#define NINETY_DEGREES 0.7
#define MAINARM_POT 0
#define MAINARM_DRIVE_LEFT 5
#define MAINARM_DRIVE_RIGHT 6

//Shooter
#define SHOOTER_LEFT_MOTOR 7
#define SHOOTER_RIGHT_MOTOR 8
//Pneumatics
#define COMPRESSOR_PCM_CAN 31
#define SHOOTER_PISTON_SOLENOID_ONE 0
#define SHOOTER_PISTON_SOLENOID_TWO 1
#define PORTCULLIS_PISTON_SOLENOID_ONE 2
#define PORTCULLIS_PISTON_SOLENOID_TWO 3
#define ARM_STOP_PISTON_SOLENOID_ONE 4
#define ARM_STOP_PISTON_SOLENOID_TWO 5


//Misc variables
#define MAINARM_PRESET_COLLECT 0
#define MAINARM_PRESET_TRAVERSE 5
#define MAINARM_PRESET_SHOOT_CLOSE 95
#define MAINARM_PRESET_SHOOT_FAR 85

#endif
// vim: ts=2:sw=2:et
