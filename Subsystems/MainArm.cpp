#include "MainArm.h"
#include "../RobotMap.h"

MainArm::MainArm(): PIDSubsystem("MainArm",1.0,0.0,0.0) {
  armLeftDriveMotor = new CANTalon(MAINARM_DRIVE_LEFT);
  armRightDriveMotor = new CANTalon(MAINARM_DRIVE_RIGHT);
  armPot = new AnalogInput(MAINARM_POT);

  GetPIDController()->SetContinuous(false);
//  SetSetpoint(TRAVERSE);
  Enable();
}
void MainArm::InitDefaultCommand() {}
double MainArm::ReturnPIDInput(){
}
void MainArm::UsePIDOutput(double output){
}
double MainArm::PotToDegrees(double volts){
  return 300-((volts-NINETY_DEGREES)*(300/(ZERO_DEGREES-NINETY_DEGREES)));
}
double MainArm::GetDegrees(){
  return PotToDegrees(GetRawPot());
}
double MainArm::GetRawPot(){
	return armPot->GetAverageVoltage();
}

void MainArm::SetPosition(double speed){
  armLeftDriveMotor.Set(speed);
  armRightDriveMotor.Set(-speed);
}
// vim: ts=2:sw=2:et
