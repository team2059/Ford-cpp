#include "TraversePreset.h"
#include "../../Ford.h"
#include "../../OI.h"
TraversePreset::TraversePreset(double timeout): Command("TraversePreset") {
  SetTimeout(timeout);
}
void TraversePreset::Initialize() {}
void TraversePreset::Execute() {
  //Ford::mainArm->SetSetpoint(Ford::mainArm->TRAVERSE);
  Ford::mainArm-SetPosition(.75);
}
bool TraversePreset::IsFinished() {
  if(!IsTimedOut()) {
    return false;
  }
  //If the arm gets within 0.2 volts of the target call it done
  //return abs(Ford::mainArm->GetSetpoint()-Ford::mainArm->GetPosition()) < 0.2;
}
void TraversePreset::End() {
  Ford::mainArm->SetPosition(0);
}
void TraversePreset::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
