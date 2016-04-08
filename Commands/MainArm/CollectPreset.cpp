#include "CollectPreset.h"
#include "../../Ford.h"
#include "../../OI.h"
CollectPreset::CollectPreset(double timeout): Command("CollectPreset") {
  SetTimeout(timeout);
}
void CollectPreset::Initialize() {}
void CollectPreset::Execute() {
  Ford::mainArm->SetSetpoint(Ford::mainArm->COLLECT);
}
bool CollectPreset::IsFinished() {
  if(!IsTimedOut()) {
    return false;
  }
  //If the arm gets within 0.2 volts of the target call it done
  return abs(Ford::mainArm->GetSetpoint()-Ford::mainArm->GetPosition()) < 0.2;
}
void CollectPreset::End() {
}
void CollectPreset::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
