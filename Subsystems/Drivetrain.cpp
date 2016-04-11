#include "Drivetrain.h"
#include "../RobotMap.h"
#include "../Commands/Drivetrain/Drive.h"

Drivetrain::Drivetrain(): Subsystem("Drivetrain") {
  leftMotorOne = new CANTalon(DRIVE_LEFT_MOTOR_ONE);
  leftMotorTwo = new CANTalon(DRIVE_LEFT_MOTOR_TWO);
  rightMotorOne = new CANTalon(DRIVE_RIGHT_MOTOR_ONE);
  rightMotorTwo = new CANTalon(DRIVE_RIGHT_MOTOR_TWO);
}
void Drivetrain::InitDefaultCommand() {
  SetDefaultCommand(new Drive());
}
void Drivetrain::DriveArcade(double x, double y, double z, double sensitivity) {
  leftMotorOne->Set(-y+(x+z));
  leftMotorTwo->Set(-y+(x+z));
  rightMotorOne->Set(y+(x+z));
  rightMotorTwo->Set(y+(x+z));
}
//Used in pretest
void Drivetrain::TestMotor(e_motors motor, double power) {
  switch(motor) {
    case LEFTONE:
      leftMotorOne->Set(power);
      break;
    case LEFTTWO:
      leftMotorTwo->Set(power);
      break;
    case RIGHTONE:
      rightMotorOne->Set(power);
      break;
    case RIGHTTWO:
      rightMotorTwo->Set(power);
      break;
    default:
      break;
  }
}
// vim: ts=2:sw=2:et
