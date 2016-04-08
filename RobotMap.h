#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

#define CODE_VERSION 0.1

/* This file contains all of the constants for initializing items on the robot
 * (Talons, Solenoid, Compressor, etc)
 * Left/Right is determined by looking at the robot from behind
 */

//MainArm
#define MAINARM_POT 0
#define MAINARM_DRIVE_LEFT 5
#define MAINARM_DRIVE_RIGHT 6


//Misc variables
#define MAINARM_PRESET_COLLECT 0
#define MAINARM_PRESET_TRAVERSE 5
#define MAINARM_PRESET_SHOOT_CLOSE 95
#define MAINARM_PRESET_SHOOT_FAR 85

#endif
// vim: ts=2:sw=2:et
