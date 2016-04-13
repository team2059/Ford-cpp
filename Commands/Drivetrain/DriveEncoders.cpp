#include "DriveEncoders.h"
#include "../../Ford.h"
DriveEncoders::DriveEncoders(): Command("DriveEncoders") {
  Requires(Ford::driveencoder);
}
void DriveEncoders::Initialize() {}
void DriveEncoders::Execute() {
  Ford::driveencoder->UpdateRightWheelEncoder();
  Ford::driveencoder->UpdateLeftWheelEncoder();
}
bool DriveEncoders::IsFinished() {
  return IsTimedOut();
}
void DriveEncoders::End() {}
void DriveEncoders::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
