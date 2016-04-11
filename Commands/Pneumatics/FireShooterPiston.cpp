#include "FireShooterPiston.h"
#include "../../Ford.h"
#include "../../OI.h"
FireShooterPiston::FireShooterPiston(): Command("FireShooterPiston") {
  SetTimeout(5);
}
void FireShooterPiston::Initialize() {}
void FireShooterPiston::Execute() {
  Ford::pneumatics->SetShooterPistonFired(true);
}
bool FireShooterPiston::IsFinished() {
  if(IsTimedOut()) {
    return true;
  } else {
    return false;
  }
}
void FireShooterPiston::End() {
  Ford::pneumatics->SetShooterPistonFired(false);
}
void FireShooterPiston::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
