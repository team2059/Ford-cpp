#ifndef SPINROLLERS_H
#define SPINROLLERS_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Spins the SpinRollers.cpper at 12 volts
 */
class SpinRollers.cpp: public Command {
 private:
 public:
  /**
   * @brief Constructs SpinRollers.cpp
   */
  SpinRollers.cpp();
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief Spins the SpinRollers.cpper
   */
  void Execute();
  /**
   * @brief Checks if the command is finished
   */
  bool IsFinished();
  /**
   * @brief required for the command
   */
  void End();
  /**
   * @brief Calls End()
   */
  void Interrupted();
};
#endif
// vim: ts=2:sw=2:et
