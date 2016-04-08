#ifndef MainArm_H
#define MainArm_H

#include "WPILib.h"
#include "Commands/PIDSubsystem.h"
#include "../RobotMap.h"
/**
 * @brief Controls the MainArm
 *
 * Controls the angle of the MainArm via a PID control loop
 */
class MainArm: public PIDSubsystem {
 private:
  CANTalon *armLeftDriveMotor, //<<! Left Drive motor for the arm
           *armRightDriveMotor; //<<! Right drive motor for the arm
  AnalogInput *armPot; //<<! Pot used to get arm angle via a four bar linkage
 public:

  static constexpr double COLLECT = MAINARM_PRESET_COLLECT;
  static constexpr double TRAVERSE = MAINARM_PRESET_TRAVERSE;
  static constexpr double SHOOT_CLOSE= MAINARM_PRESET_SHOOT_CLOSE;
//static constexpr double SHOOT_FAR= MAINARM_PRESET_SHOOT_FAR;

  /**
   * @brief Constructs the MainArm
   */
  MainArm();
  /**
   * @brief No action
   */
  void InitDefaultCommand();
  /**
   * @brief Moves the arm to a given angle
   *
   * @param the target angle of the arm
   */
  void MoveToAngle(double angle);
  /**
   * @brief returns the PID input
   *
   * @return PID input
   */
  double ReturnPIDInput();
  /**
   * @brief Uses the PID output
   *
   * @param output of the PID loop
   */
  void UsePIDOutput(double output);
  /**
   * @brief converts the potentiometer voltage to degrees
   *
   * @param voltage of the potentiometer
   */
  double PotToDegrees(double volts);
  /**
	* @brief gets the raw pot voltage for debugging
  *
  * @return pot voltage
  */
	double GetRawPot();
};
#endif
// vim: ts=2:sw=2:et
