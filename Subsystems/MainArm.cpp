#include "MainArm.h"
#include "../RobotMap.h"

MainArm::MainArm(): PIDSubsystem("MainArm",1.0,0.0,0.0) {
  armLeftDriveMotor = new CANTalon(MAINARM_DRIVE_LEFT);
  armRightDriveMotor = new CANTalon(MAINARM_DRIVE_RIGHT);
  armPot = new AnalogInput(MAINARM_POT);

  static const double COLLECT = MAINARM_PRESET_COLLECT;
  static const double TRAVERSE = MAINARM_PRESET_TRAVERSE;
  static const double SHOOT = MAINARM_PRESET_SHOOT;

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
  //Use output
}
// vim: ts=2:sw=2:et
