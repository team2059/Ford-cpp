#include "Autonomous.h"
#include "../../Ford.h"
#include "Commands/CommandGroup.h"
Autonomous::Autonomous(int seq) {
  switch(seq) {
    case 0:
      break;
    default:
      printf("Invalid seq: %d\n", seq);
      break;
  }
}
// vim: ts=2:sw=2:et
