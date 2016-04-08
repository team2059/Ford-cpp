#include "OI.h"
#include "Commands/MainArm/CollectPreset.h"
#include "Commands/MainArm/TraversePreset.h"
OI::OI() {
  // Joysticks
  leftStick = new Joystick(0);
  rightStick = new Joystick(1);

  //Drivestick




  //Armstick
  JoystickButton *right3 = new JoystickButton(rightStick, 3);
  JoystickButton *right5 = new JoystickButton(rightStick, 5);
  right3->WhileHeld(new TraversePreset());
  right5->WhileHeld(new CollectPreset());
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
