#ifndef SHOOT_H
#define SHOOT_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Spins the shooter at 12 volts
 */
class Shoot: public Command {
 private:
 public:
  /**
   * @brief Constructs Shoot
   */
  Shoot();
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief Spins the shooter
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
