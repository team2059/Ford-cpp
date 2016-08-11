#include "ShootPreset.h"
#include "../../Ford.h"
#include "../../OI.h"
ShootPreset::ShootPreset(double timeout): Command("ShootPreset") {
  SetTimeout(timeout);
}
void ShootPreset::Initialize() {}
void ShootPreset::Execute() {
  //Ford::mainArm->SetSetpoint(Ford::mainArm->SHOOT_CLOSE);
  Ford::mainArm->SetPosition(-.75);
}
bool ShootPreset::IsFinished() {
  if(!IsTimedOut()) {
    return false;
  }
  //If the arm gets within 0.2 volts of the target call it done
  //return abs(Ford::mainArm->GetSetpoint()-Ford::mainArm->GetPosition()) < 0.2;
}
void ShootPreset::End() {
  Ford::mainArm->SetPosition(0);
}
void ShootPreset::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
