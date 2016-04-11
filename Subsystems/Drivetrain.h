#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WPILib.h"
/**
 * @brief Drives the robot
 *
 * Drives wheels via 4 cims through a VEX Pro gearbox
 */
class Drivetrain: public Subsystem {
 private:
  CANTalon *rightMotorOne, //<! First right drive motor
           *rightMotorTwo, //<! Second right drive motor
           *leftMotorOne, //<! First left drive motor
           *leftMotorTwo; //<! Second left drive motor
 public:
  /**
   * @brief Constructs Drivetrain
   */
  Drivetrain();
  /**
   * @brief Current motor to test
   */
  enum e_motors {
    RIGHTONE, //<! First right drive motor
    RIGHTTWO, //<! Second right drive motor
    LEFTONE, //<! First left drive motor
    LEFTTWO //<! Second left drive motor
  };
  /**
   * @brief Sets Drive as the default command
   */
  void InitDefaultCommand();
  /**
   * @brief Drives the robot with arcade
   *
   * @param x Joystick x value (-1.0 to 1.0)
   * @param y Joystick y value (-1.0 to 1.0)
   * @param z Joystick z value (-1.0 to 1.0)
   * @param sensitivity Sensitivity (0.0 to 1.0)
   */
  void DriveArcade(double x, double y, double z, double sensitivity);
  /**
   * @brief Tests one motor
   *
   * @param motor Motor to test
   * @param power Power to set motor
   */
  void TestMotor(e_motors motor, double power);
};
#endif
// vim: ts=2:sw=2:et
