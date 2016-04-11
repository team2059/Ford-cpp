#include "Pneumatics.h"
#include "../RobotMap.h"

Pneumatics::Pneumatics(): Subsystem("Pneumatics") {
  compressor = new Compressor(COMPRESSOR_PCM_CAN);
  shooterPistonSolenoidOne = new Solenoid(SHOOTER_PISTON_SOLENOID_ONE);
  shooterPistonSolenoidTwo = new Solenoid(SHOOTER_PISTON_SOLENOID_TWO);
  portcullisPistonSolenoidOne = new Solenoid(PORTCULLIS_PISTON_SOLENOID_ONE);
  portcullisPistonSolenoidTwo = new Solenoid(PORTCULLIS_PISTON_SOLENOID_TWO);
  armStopPistonSolenoidOne = new Solenoid(ARM_STOP_PISTON_SOLENOID_ONE);
  armStopPistonSolenoidTwo = new Solenoid(ARM_STOP_PISTON_SOLENOID_TWO);
  shooterState = false;
  portcullisState = false;
  armStopState = true;
}
void Pneumatics::InitDefaultCommand() {}
void Pneumatics::SetShooterPistonFired(bool state){
  shooterPistonSolenoidOne->Set(state);
  shooterPistonSolenoidTwo->Set(!state);
  shooterState=state;
}
void Pneumatics::SetPortcullisLiftersOut(bool state){
  portcullisPistonSolenoidOne->Set(state);
  portcullisPistonSolenoidTwo->Set(!state);
  portcullisState=state;
}
void Pneumatics::SetArmStopPistonUp(bool state){
  armStopPistonSolenoidOne->Set(state);
  armStopPistonSolenoidTwo->Set(!state);
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
