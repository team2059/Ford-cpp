#include "TogglePortcullisLifters.h"
#include "../../Ford.h"
#include "../../OI.h"
TogglePortcullisLifters::TogglePortcullisLifters(): Command("TogglePortcullisLifters") {
  SetTimeout(5);
}
void TogglePortcullisLifters::Initialize() {}
void TogglePortcullisLifters::Execute() {
  Ford::pneumatics->SetPortcullisLiftersOut(!Ford::pneumatics->GetPortcullisLiftersOut());
}
bool TogglePortcullisLifters::IsFinished() {
  if(IsTimedOut()) {
    return true;
  } else {
    return false;
  }
}
void TogglePortcullisLifters::End() {
}
void TogglePortcullisLifters::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
