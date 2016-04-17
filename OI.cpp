#include "OI.h"
#include "Commands/MainArm/CollectPreset.h"
#include "Commands/MainArm/TraversePreset.h"
#include "Commands/MainArm/ShootPreset.h"
#include "Commands/Pneumatics/FireShooterPiston.h"
#include "Commands/Pneumatics/TogglePortcullisLifters.h"
#include "Commands/Pneumatics/RetractArmPiston.h"
#include "Commands/Shooter/Shoot.h"
OI::OI() {
  // Joysticks
  leftStick = new Joystick(0);
  rightStick = new Joystick(1);

  //Drivestick
  JoystickButton *left1 = new JoystickButton(leftStick, 1);
  JoystickButton *left5 = new JoystickButton(leftStick, 5);
  left1->WhileHeld(new FireShooterPiston());
  left5->WhileHeld(new Shoot());

  //Armstick
  JoystickButton *right3 = new JoystickButton(rightStick, 3);
  JoystickButton *right4 = new JoystickButton(rightStick, 4);
  JoystickButton *right5 = new JoystickButton(rightStick, 5);
  JoystickButton *right9 = new JoystickButton(rightStick, 9);
  JoystickButton *right11 = new JoystickButton(rightStick, 11);
  right3->WhileHeld(new TraversePreset());
  right4->WhileHeld(new ShootPreset());
  right5->WhileHeld(new CollectPreset());
  right9->WhileHeld(new RetractArmPiston(20));
  right11->WhenPressed(new TogglePortcullisLifters());
}
Joystick* OI::GetRightStick() {
  return rightStick;
}
Joystick* OI::GetLeftStick() {
  return leftStick;
}
double OI::GetRightThrottle() {
  return (-rightStick->GetRawAxis(3)+1.0)/2;
}
double OI::GetLeftThrottle() {
  return (-leftStick->GetRawAxis(3)+1.0)/2;
}
// vim: ts=2:sw=2:et
