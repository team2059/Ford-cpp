#ifndef DRIVEENCODERS_H
#define DRIVEENCODERS_H

#include "Commands/Command.h"
#include "../../Ford.h"
#include "WPILib.h"

/**
 * @brief Updates the drive encoders
 */
class DriveEncoders: public Command {
 public:
  /**
   * @brief Constructs DriveEncoders
   */
  DriveEncoders();
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief Updates the drive encoders
   */
  void Execute();
  /**
   * @brief Checks if the command is finished (never)
   *
   * @return False
   */
  bool IsFinished();
  /**
   * @brief Ends the command
   */
  void End();
  /**
   * @brief Calls End()
   */
  void Interrupted();
};
#endif
// vim: ts=2:sw=2:et
