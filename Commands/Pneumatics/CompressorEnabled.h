#ifndef COMPRESSORENABLED_H
#define COMPRESSORENABLED_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Manually disable/enables the compressor
 */
class CompressorEnabled: public Command {
 private:
   bool enabled;
 public:
  /**
   * @brief Constructs CompressorEnabled
   *
   * @param isEnabled sets the compressor to enabled or disabled
   */
  CompressorEnabled(bool isEnabled);
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief CompressorEnableds sets the compressor to enabled
   */
  void Execute();
  /**
   * @brief Checks if the command is finished
   *
   * @return True if the timeout was reached
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
