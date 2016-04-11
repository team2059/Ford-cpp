#ifndef FORD_H
#define FORD_H
#include "WPILib.h"
#include "OI.h"
#include "Subsystems/MainArm.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Pneumatics.h"
#include "Commands/Autonomous/Autonomous.h"
/**
 * @brief The Hitchhikers 2016 robot, Ford
 */
class Ford: public IterativeRobot {
 private:
  /**
   * @brief The default driving command
   */
  Command *driveCommand = NULL;
 public:
  /**
   * @brief Constructs Ford
   */
  Ford();
  /**
   * @brief The 2-joystick OI
   */
  static OI* oi;
  /**
   * @brief The main arm of the robot
   */
  static MainArm* mainArm;
  /**
   * @brief 4 cim west coast drive
   */
  static Drivetrain* drivetrain;
  /**
   * @brief pneumatics system
   */
  static Pneumatics* pneumatics;
  /**
   * @brief Autonomous command
   */
  static CommandGroup* aut;
  /**
   * @brief Initializes the robot
   */
  void RobotInit();
  /**
   * @brief Periodically run when disabled
   */
  void DisabledPeriodic();
  /**
   * @brief Initializes the autonomous period
   */
  void AutonomousInit();
  /**
   * @brief Periodically run when enabled in autonomous
   */
  void AutonomousPeriodic();
  /**
   * @brief Initializes the teleop period
   */
  void TeleopInit();
  /**
   * @brief Periodically run when enabled in autonomous
   */
  void TeleopPeriodic();
  /**
   * @brief Periodically run when enabled in test mode
   */
  void TestPeriodic();
};
#endif
// vim: ts=2:sw=2:et
