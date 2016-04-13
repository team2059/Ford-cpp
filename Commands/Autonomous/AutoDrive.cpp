#include "AutoDrive.h"
#include "../../Ford.h"
AutoDrive::AutoDrive(int targetTicks, double xtmp, double ytmp, double ztmp): Command("AutoDrive") {
  ticks=targetTicks;
}
void AutoDrive::Initialize() {
  Ford::driveencoder->SetRightWheelEncoderTarget(ticks);
  Ford::driveencoder->SetLeftWheelEncoderTarget(ticks);
  Ford::driveencoder->ResetWheelTicks();
}
void AutoDrive::Execute() {
  //Drive forward
}
bool AutoDrive::IsFinished() {
  return Ford::driveencoder->GetRightWheelEncoderHitTarget() && Ford::driveencoder->GetLeftWheelEncoderHitTarget();
}
void AutoDrive::End() {
}
void AutoDrive::Interrupted() {
}
// vim: ts=2:sw=2:et
