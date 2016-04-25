#include "DriveEncoder.h"
#include "../Commands/Drivetrain/DriveEncoders.h"
#include "../RobotMap.h"

DriveEncoder::DriveEncoder(): Subsystem("DriveEncoder") {
  rightWheelSensor = new DigitalInput(DRIVE_RIGHT_ENCODER);
  leftWheelSensor = new DigitalInput(DRIVE_LEFT_ENCODER);

  rightWheelLastState = rightWheelSensor->Get();
  leftWheelLastState = leftWheelSensor->Get();
  rightWheelEncoderTicks = 0;
  leftWheelEncoderTicks = 0;
  rightWheelEncoderTarget = 0;
  leftWheelEncoderTarget = 0;
}
void DriveEncoder::InitDefaultCommand() {
  SetDefaultCommand(new DriveEncoders());
}
void DriveEncoder::UpdateRightWheelEncoder(){
  if(rightWheelSensor->Get() != rightWheelLastState){
    rightWheelEncoderTicks++;
    rightWheelLastState = rightWheelSensor->Get();
  }
  SmartDashboard::PutNumber("RightWheelTicks", rightWheelEncoderTarget);
}
void DriveEncoder::UpdateLeftWheelEncoder(){
  if(leftWheelSensor->Get() != leftWheelLastState){
    leftWheelEncoderTicks++;
    leftWheelLastState = leftWheelSensor->Get();
  }
  SmartDashboard::PutNumber("LeftWheelTicks", leftWheelEncoderTicks);
}
void DriveEncoder::SetRightWheelEncoderTarget(int target){
  SmartDashboard::PutNumber("RightWheelTarget", target);
  rightWheelEncoderTarget=target;
}
void DriveEncoder::SetLeftWheelEncoderTarget(int target){
  SmartDashboard::PutNumber("LeftWheelTarget", target);
  leftWheelEncoderTarget=target;
}
int DriveEncoder::GetRightWheelEncoderTarget(){
  return rightWheelEncoderTarget;
}
int DriveEncoder::GetLeftWheelEncoderTarget(){
  return leftWheelEncoderTarget;
}
int DriveEncoder::GetRightWheelEncoderTicks(){
  return rightWheelEncoderTicks;
}
int DriveEncoder::GetLeftWheelEncoderTicks(){
  return leftWheelEncoderTicks;
}
bool DriveEncoder::GetRightWheelEncoderHitTarget(){
  return rightWheelEncoderTicks >= rightWheelEncoderTarget;
}
bool DriveEncoder::GetLeftWheelEncoderHitTarget(){
  return leftWheelEncoderTicks >= leftWheelEncoderTarget;
}
void DriveEncoder::ResetRightWheelTicks(){
  rightWheelEncoderTicks = 0;
}
void DriveEncoder::ResetLeftWheelTicks(){
  leftWheelEncoderTicks = 0;
}
void DriveEncoder::ResetWheelTicks(){
  ResetRightWheelTicks();
  ResetLeftWheelTicks();
}
// vim: ts=2:sw=2:et
