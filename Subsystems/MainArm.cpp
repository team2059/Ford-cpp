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
  return PotToDegrees(armPot->GetAverageVoltage());
}
void MainArm::UsePIDOutput(double output){
  //This isn't going to work
  armLeftDriveMotor->Set(output);
  armRightDriveMotor->Set(-output);
}
double MainArm::PotToDegrees(double volts){
  //numbers off of Zaphod's pot
  //needs to be recalibrated
  float max = -.0003948;
  float min = 5.0245547;
  float tmp = volts - max;
  min = min - max; // ~5.0027
  //important
  max = max - max; //=0
  return 300 - ((tmp + max) * (300 / min));
}
double MainArm::GetRawPot(){
	return armPot->GetAverageVoltage();
}
// vim: ts=2:sw=2:et
