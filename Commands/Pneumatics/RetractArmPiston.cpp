#include "RetractArmPiston.h"
#include "../../Ford.h"
#include "../../OI.h"
RetractArmPiston::RetractArmPiston(int time): Command("RetractArmPiston") {
  SetTimeout(time);
}
void RetractArmPiston::Initialize() {}
void RetractArmPiston::Execute() {
  Ford::pneumatics->SetArmStopPistonUp(false);
}
bool RetractArmPiston::IsFinished() {
  if(IsTimedOut()) {
    return true;
  } else {
    return false;
  }
}
void RetractArmPiston::End() {
  Ford::pneumatics->SetArmStopPistonUp(true);
}
void RetractArmPiston::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
