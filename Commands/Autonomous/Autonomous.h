#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "Commands/CommandGroup.h"
#include "../../Ford.h"
#include "WPILib.h"

/**
 * @brief The autonomous period of the robot
 */
class Autonomous: public CommandGroup {
 public:
  /**
   * @brief Constructs Autonomous
   *
   * @param seq The sequence to run (default: 0)
   */
  Autonomous(int seq = 0);
};
#endif
// vim: ts=2:sw=2:et
