#include "SpinRollers.cpp.h"
#include "../../Ford.h"
#include "../../OI.h"
SpinRollers.cpp::Shoot(): Command("Shoot") {
}
void SpinRollers.cpp::Initialize() {}
void SpinRollers.cpp::Execute() {
  Ford::Shooter->ShootAtSpeed(1);
}
bool SpinRollers.cpp::IsFinished() {
  return false;
}
void SpinRollers.cpp::End() {
  Ford::Shooter->ShootAtSpeed(0);
}
void SpinRollers.cpp::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
