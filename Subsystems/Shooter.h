#ifndef SHOOTER_H
#define SHOOTER_H

#include "WPILib.h"
#include "../RobotMap.h"
//#include "../Ford.h"
/**
 * @brief Controls the shooter motors
 */
class Shooter: public Subsystem {
 private:
  CANTalon *leftShooterMotor, //<<! Left Shooter motor
           *rightShooterMotor; //<<! Right shooter motor
 public:
  /**
   * @brief Constructs the Shooter
   */
  Shooter();
  /**
   * @brief No action
   */
  void InitDefaultCommand();
  /**
   * @brief Spins shooter at full speed
   */
  void Shoot();
  /**
   * @brief Stops shooter
   */
  void Idle();
  /**
   * @brief Spins the rollers at a specific speed
   */
  void ShootAtSpeed(double speed);
};
#endif
// vim: ts=2:sw=2:et
