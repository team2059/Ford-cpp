#include "Pneumatics.h"
#include "../RobotMap.h"

Pneumatics::Pneumatics(): Subsystem("Pneumatics") {
  compressor = new Compressor(COMPRESSOR_PCM_CAN);
  shooterPistonSolenoid = new DoubleSolenoid(SHOOTER_PISTON_SOLENOID_ONE, SHOOTER_PISTON_SOLENOID_TWO);
  portcullisPistonSolenoid = new DoubleSolenoid(PORTCULLIS_PISTON_SOLENOID_ONE, SHOOTER_PISTON_SOLENOID_TWO);
  armStopPistonSolenoid = new DoubleSolenoid(ARM_STOP_PISTON_SOLENOID_ONE, ARM_STOP_PISTON_SOLENOID_TWO);
  shooterState = false;
  portcullisState = false;
  armStopState = true;
}
void Pneumatics::InitDefaultCommand() {}
void Pneumatics::SetShooterPistonFired(bool state){
  if(state){
    shooterPistonSolenoid->Set(DoubleSolenoid::kForward);
  }else{
    shooterPistonSolenoid->Set(DoubleSolenoid::kReverse);
  }
  shooterState=state;
}
void Pneumatics::SetPortcullisLiftersOut(bool state){
  if(state){
    portcullisPistonSolenoid->Set(DoubleSolenoid::kForward);
  }else{
    portcullisPistonSolenoid->Set(DoubleSolenoid::kReverse);
  }
  portcullisState=state;
}
void Pneumatics::SetArmStopPistonUp(bool state){
  if(state){
    armStopPistonSolenoid->Set(DoubleSolenoid::kForward);
  }else{
    armStopPistonSolenoid->Set(DoubleSolenoid::kReverse);
  }
  armStopState=state;
}
void Pneumatics::SetCompressorEnabled(bool state) {
  compressor->SetClosedLoopControl(state);
}
bool Pneumatics::GetShooterPistonFired(){
  return shooterState;
}
bool Pneumatics::GetPortcullisLiftersOut(){
   return portcullisState;
}
bool Pneumatics::GetArmStopPistonUp(){
  return armStopState;
}
bool Pneumatics::GetCompressorEnabled() {
  return compressor->Enabled();
}
// vim: ts=2:sw=2:et
