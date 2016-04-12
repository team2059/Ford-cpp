#ifndef RETRACTARMPISTON_H
#define RETRACTARMPISTON_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Retracts the arm stop wihle the command is running, then extends on completion
 */
class RetractArmPiston: public Command {
 private:
 public:
  /**
   * @brief Constructs RetractArmPiston
   */
  RetractArmPiston(int time);
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief pulls the arm stop back
   */
  void Execute();
  /**
   * @brief Checks if the command is finished
   *
   * @return True if the timeout was reached
   */
  bool IsFinished();
  /**
   * @brief Extends the piston
   */
  void End();
  /**
   * @brief Calls End()
   */
  void Interrupted();
};
#endif
// vim: ts=2:sw=2:et
