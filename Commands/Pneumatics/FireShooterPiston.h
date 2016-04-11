#ifndef FIRESHOOTERPISTON_H
#define FIRESHOOTERPISTON_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Manually disable/enables the compressor
 */
class FireShooterPiston: public Command {
 private:
 public:
  /**
   * @brief Constructs FireShooterPiston
   */
  FireShooterPiston();
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief Fires the piston
   */
  void Execute();
  /**
   * @brief Checks if the command is finished
   *
   * @return True if the timeout was reached
   */
  bool IsFinished();
  /**
   * @brief Retracts the piston
   */
  void End();
  /**
   * @brief Calls End()
   */
  void Interrupted();
};
#endif
// vim: ts=2:sw=2:et
