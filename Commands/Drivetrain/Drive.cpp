#include "Drive.h"
#include "../../Ford.h"
Drive::Drive(): Command("Drive") {
  Requires(Ford::drivetrain);
}
void Drive::Initialize() {}
void Drive::Execute() {
  float x, y, z;
  x = Ford::oi->GetLeftStick()->GetRawAxis(0);
  y = Ford::oi->GetLeftStick()->GetRawAxis(1);
  z = Ford::oi->GetLeftStick()->GetRawAxis(2);
  //X axis, Y axis, Z axis, sensitivity, speed threshold
  Ford::drivetrain->DriveArcade(x, y, z, 0.9);
}
bool Drive::IsFinished() {
  return IsTimedOut();
}
void Drive::End() {}
void Drive::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
