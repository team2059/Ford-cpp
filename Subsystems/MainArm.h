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

  static constexpr double COLLECT = MAINARM_PRESET_COLLECT; //<<! Lowest "0" preset, used for collecting
  static constexpr double TRAVERSE = MAINARM_PRESET_TRAVERSE; //<<! Slightly higher than collect, rests on physical stop
  static constexpr double SHOOT_CLOSE= MAINARM_PRESET_SHOOT_CLOSE; //<<! Angle for shooting shots from the edge of the batter
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
   * @brief returns the PID input
   *
   * @return PID input
   */
  double ReturnPIDInput();
  /**
   * @brief Uses the PID output
   *
   * @param output output of the PID loop
   */
  void UsePIDOutput(double output);
  /**
   * @brief converts the potentiometer voltage to degrees
   *
   * @param volts voltage of the potentiometer
   */
  double GetDegrees();
  /**
   * @brief Gets the degrees of the arm
   *
   * @return the degrees of the arm
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
