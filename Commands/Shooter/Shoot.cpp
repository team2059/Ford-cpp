#include "Shoot.h"
#include "../../Ford.h"
#include "../../OI.h"
Shoot::Shoot(): Command("Shoot") {
}
void Shoot::Initialize() {}
void Shoot::Execute() {
  Ford::shooter->Shoot();
}
bool Shoot::IsFinished() {
  return false;
}
void Shoot::End() {
  Ford::shooter->Idle();
}
void Shoot::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
