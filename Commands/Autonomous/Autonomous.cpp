#include "Autonomous.h"
#include "../../Ford.h"
#include "AutoDrive.h"
#include "Commands/CommandGroup.h"
Autonomous::Autonomous(int seq) {
  switch(seq) {
    case 1:
      AddSequential(new AutoDrive(SmartDashboard::GetNumber("AutoTicks"), 0.0, 0.3, 0.0));
      break;
    default:
      printf("Invalid seq: %d\n", seq);
      break;
  }
}
// vim: ts=2:sw=2:et
