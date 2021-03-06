#ifndef TRAVERSEPRESET_H
#define TRAVERSEPRESET_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Moves the arm to the traverse preset
 */
class TraversePreset: public Command {
 private:
 public:
  /**
   * @brief Constructs TraversePreset
   *
   * @param timeout Timeout in seconds (default: 5)
   *
   */
  TraversePreset(double timeout = 5);
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief Moves the arm to the traverse position
   */
  void Execute();
  /**
   * @brief Checks if the command is finished
   *
   * @return True if the timeout was reached or the desired angle was reached
   */
  bool IsFinished();
  /**
   * @brief Stops the arm
   */
  void End();
  /**
   * @brief Calls End()
   */
  void Interrupted();
};
#endif
// vim: ts=2:sw=2:et
