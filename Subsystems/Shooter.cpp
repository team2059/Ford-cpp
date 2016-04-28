#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter(): Subsystem("Shooter") {
  leftShooterMotor = new CANTalon(SHOOTER_LEFT_MOTOR);
  rightShooterMotor = new CANTalon(SHOOTER_RIGHT_MOTOR);
}
void Shooter::InitDefaultCommand() {}
void Shooter::Shoot(){
  leftShooterMotor->SetControlMode(CANSpeedController::kVoltage);
  rightShooterMotor->SetControlMode(CANSpeedController::kVoltage);

  leftShooterMotor->Set(12);
  rightShooterMotor->Set(12);
}
void Shooter::Idle(){
  leftShooterMotor->SetControlMode(CANSpeedController::kVoltage);
  rightShooterMotor->SetControlMode(CANSpeedController::kVoltage);

  leftShooterMotor->Set(0);
  rightShooterMotor->Set(0);
}
void Shooter::ShootAtSpeed(double speed){
  leftShooterMotor->SetControlMode(CANSpeedController::kPercentVbus);
  rightShooterMotor->SetControlMode(CANSpeedController::kPercentVbus);

  leftShooterMotor->Set(speed);
  rightShooterMotor->Set(speed);
}
// vim: ts=2:sw=2:et
