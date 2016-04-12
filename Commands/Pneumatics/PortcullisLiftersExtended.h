#ifndef PORTCULLISLIFTERSEXTENDED_H
#define PORTCULLISLIFTERSEXTENDED_H

#include "Commands/Command.h"
#include "WPILib.h"

/**
 * @brief Extends/Retracts the portcullis lifters
 */
class PortcullisLiftersExtended: public Command {
 private:
   bool portState; //<<! State of the portcullis lifters
 public:
  /**
   * @brief Constructs PortcullisLiftersExtended
   *
   * @param state sets if the lifters are extended
   */
  PortcullisLiftersExtended(bool state);
  /**
   * @brief Initializes the class
   */
  void Initialize();
  /**
   * @brief Sets the porcullis lifters to the state passed in the constructor
   */
  void Execute();
  /**
   * @brief Checks if the command is finished
   *
   * @return True if the timeout was reached
   */
  bool IsFinished();
  /**
   * @brief Does nothing
   */
  void End();
  /**
   * @brief Calls End()
   */
  void Interrupted();
};
#endif
// vim: ts=2:sw=2:et
