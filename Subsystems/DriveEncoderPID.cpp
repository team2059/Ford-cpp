#include "DriveEncoderPID.h"
#include "../RobotMap.h"

DriveEncoderPID::DriveEncoderPID(): PIDSubsystem("DriveEncoderPID", 1.0, 0, 0) {
  rightWheelSensor = new DigitalInput(DRIVE_RIGHT_ENCODER);
  leftWheelSensor = new DigitalInput(DRIVE_LEFT_ENCODER);

  rightWheelLastState = rightWheelSensor->Get();
  leftWheelLastState = leftWheelSensor->Get();
  rightWheelEncoderTicks = 0;
  leftWheelEncoderTicks = 0;
  rightWheelEncoderTarget = 0;
  leftWheelEncoderTarget = 0;
}
double DriveEncoderPID::ReturnPIDInput(){
  return 0;
}
void DriveEncoderPID::InitDefaultCommand() {
}
void DriveEncoderPID::UpdateRightWheelEncoder(){
  if(rightWheelSensor->Get() != rightWheelLastState){
    rightWheelEncoderTicks++;
    rightWheelLastState = rightWheelSensor->Get();
  }
}
void DriveEncoderPID::UpdateLeftWheelEncoder(){
  if(leftWheelSensor->Get() != leftWheelLastState){
    leftWheelEncoderTicks++;
    leftWheelLastState = leftWheelSensor->Get();
  }
}
void DriveEncoderPID::SetRightWheelEncoderTarget(int target){
  rightWheelEncoderTarget=target;
}
void DriveEncoderPID::SetLeftWheelEncoderTarget(int target){
  leftWheelEncoderTarget=target;
}
int DriveEncoderPID::GetRightWheelEncoderTarget(){
  return rightWheelEncoderTarget;
}
int DriveEncoderPID::GetLeftWheelEncoderTarget(){
  return leftWheelEncoderTarget;
}
int DriveEncoderPID::GetRightWheelEncoderTicks(){
  return rightWheelEncoderTicks;
}
int DriveEncoderPID::GetLeftWheelEncoderTicks(){
  return leftWheelEncoderTicks;
}
bool DriveEncoderPID::GetRightWheelEncoderHitTarget(){
  return rightWheelEncoderTicks >= rightWheelEncoderTarget;
}
bool DriveEncoderPID::GetLeftWheelEncoderHitTarget(){
  return leftWheelEncoderTicks >= leftWheelEncoderTarget;
}
void DriveEncoderPID::ResetRightWheelTicks(){
  rightWheelEncoderTicks = 0;
}
void DriveEncoderPID::ResetLeftWheelTicks(){
  leftWheelEncoderTicks = 0;
}
void DriveEncoderPID::ResetWheelTicks(){
  ResetRightWheelTicks();
  ResetLeftWheelTicks();
}
// vim: ts=2:sw=2:et
