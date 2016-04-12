#include "PortcullisLiftersExtended.h"
#include "../../Ford.h"
#include "../../OI.h"
PortcullisLiftersExtended::PortcullisLiftersExtended(bool state): Command("PortcullisLiftersExtended") {
  SetTimeout(5);
  portState=state;
}
void PortcullisLiftersExtended::Initialize() {}
void PortcullisLiftersExtended::Execute() {
  Ford::pneumatics->SetPortcullisLiftersOut(portState);
}
bool PortcullisLiftersExtended::IsFinished() {
  if(IsTimedOut()) {
    return true;
  } else {
    return false;
  }
}
void PortcullisLiftersExtended::End() {
}
void PortcullisLiftersExtended::Interrupted() {
  End();
}
// vim: ts=2:sw=2:et
