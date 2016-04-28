#ifndef PNEUMATICS_H
#define PNEUMATICS_H

#include "WPILib.h"
/**
 * @brief Pneumatics on the robot
 *
 */
class Pneumatics: public Subsystem {
 private:
  Compressor *compressor; //<! Compressor
  DoubleSolenoid *shooterPistonSolenoid, //<! Solenoid for the shooter piston
                 *portcullisPistonSolenoid, //<! Solenoid for the portcullis lifters
                 *armStopPistonSolenoid; //<! Solenoid for the arm stop piston
  bool shooterState, //<! State of the shooter piston
       portcullisState, //<! State of the portcullis lifters
       armStopState; //<! State of the arm stop
 public:
  /**
   * @brief Constructs Pneumatics
   */
  Pneumatics();
  /**
   * @brief No action
   */
  void InitDefaultCommand();
  /**
   * @brief Fires/Retracts the shooter piston
   *
   * @param state State shooter piston
   */
  void SetShooterPistonFired(bool state);
  /**
   * @brief Releases/Retracts the portcullis lifters
   *
   * @param state state of the portcullis lifters
   */
  void SetPortcullisLiftersOut(bool state);
  /**
   * @brief Raises/Lowers the arm stop piston
   *
   * @param state state of the arm stop piston
   */
  void SetArmStopPistonUp(bool state);
  /**
   * @brief Sets the state of the compressor
   *
   * @param state State of the compressor
   */
  void SetCompressorEnabled(bool state);
  /**
   * @brief Gets the state of the shooter piston
   *
   * @return State of the shooter piston
   */
  bool GetShooterPistonFired();
  /**
   * @brief Gets the state of the portcullis lifters
   *
   * @return State of the portcullis lifters
   */
  bool GetPortcullisLiftersOut();
  /**
   * @brief Gets the state of the arm stop piston
   *
   * @return State of the arm stop piston
   */
  bool GetArmStopPistonUp();
  /**
   * @brief Gets the state of the compressor
   *
   * @return State of the compressor
   */
  bool GetCompressorEnabled();

};
#endif
// vim: ts=2:sw=2:et
