#include "CompressorEnabled.h"
#include "../../Ford.h"
#include "../../OI.h"
CompressorEnabled::CompressorEnabled(bool isEnabled): Command("CompressorEnabled") {
  SetTimeout(1);
  enabled=isEnabled;
}
void CompressorEnabled::Initialize() {}
void CompressorEnabled::Execute() {
  Ford::pneumatics->SetCompressorEnabled(enabled);
}
bool CompressorEnabled::IsFinished() {
  if(IsTimedOut()) {
    return true;
  } else {
    return false;
  }
}
void CompressorEnabled::End() {
}
void CompressorEnabled::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
