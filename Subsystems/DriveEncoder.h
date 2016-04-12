#ifndef DRIVEENCODER_H
#define DRIVEENCODER_H

#include "WPILib.h"
/**
 * @brief Collects data from the wheel encoders
 *
 * Collects data and processes data from IR wheel encoders
 */
class DriveEncoder: public Subsystem {
 private:
  DigitalInput *rightWheelSensor, //<<! Right wheel sensor
              *leftWheelSensor; //<<! Left wheel sensor
  int rightWheelEncoderTicks, //<<! Right wheel encoder ticks
      leftWheelEncoderTicks, //<<! Left wheel encoder ticks
      rightWheelEncoderTarget, //<! Right wheel encoder target
      leftWheelEncoderTarget; //<! Left wheel encoder target
  bool rightWheelLastState,
       leftWheelLastState;
 public:
  /**
   * @brief Constructs DriveEncoder
   */
  DriveEncoder();
  /**
   * @brief Does nothing for now
   */
  void InitDefaultCommand();
  /**
   * @brief Updates the right wheel encoder
   */
  void UpdateRightWheelEncoder();
  /**
   * @brief Updates the left wheel encoder
   */
  void UpdateLeftWheelEncoder();
  /**
   * @brief Sets right wheel encoder target
   */
  void SetRightWheelEncoderTarget(int target);
  /**
   * @brief Sets left wheel encoder target
   */
  void SetLeftWheelEncoderTarget(int target);
  /**
   * @brief Gets current right wheel encoder target
   */
  int GetRightWheelEncoderTarget();
  /**
   * @brief Gets current left wheel encoder target
   */
  int GetLeftWheelEncoderTarget();
  /**
   * @brief Gets current amount of right encoder ticks
   */
  int GetRightWheelEncoderTicks();
  /**
   * @brief Gets current amount of left encoder ticks
   */
  int GetLeftWheelEncoderTicks();
  /**
   * @brief Returns true if the encoder has hit the target
   */
  bool GetRightWheelEncoderHitTarget();
  /**
   * @brief Returns true if the encoder has hit the target
   */
  bool GetLeftWheelEncoderHitTarget();
  /**
   * @brief Resets the right encoder tick count (leaves target)
   */
  void ResetRightWheelTicks();
  /**
   * @brief Resets the left encoder tick count (leaves target)
   */
  void ResetLeftWheelTicks();
  /**
   * @brief Resets the tick count for both sides
   */
  void ResetWheelTicks();
};
#endif
// vim: ts=2:sw=2:et
