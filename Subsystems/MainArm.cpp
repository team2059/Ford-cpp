#include "MainArm.h"
#include "../RobotMap.h"

MainArm::MainArm(): PIDSubsystem("MainArm",1.0,0.0,0.0) {
  armLeftDriveMotor = new CANTalon(MAINARM_DRIVE_LEFT);
  armRightDriveMotor = new CANTalon(MAINARM_DRIVE_RIGHT);
  armPot = new AnalogInput(MAINARM_POT);

  GetPIDController()->SetContinuous(false);
  SetSetpoint(TRAVERSE);
  Enable();
}
void MainArm::InitDefaultCommand() {}
void MainArm::MoveToAngle(double angle){
  //code goes here
}
double MainArm::ReturnPIDInput(){
  return armPot->GetAverageVoltage();
}
void MainArm::UsePIDOutput(double output){
  //This isn't going to work
  armLeftDriveMotor->Set(output);
  armRightDriveMotor->Set(-output);
}
// vim: ts=2:sw=2:et
