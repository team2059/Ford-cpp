#include "OI.h"
#include "Commands/MainArm/CollectPreset.h"
OI::OI() {
  // Joysticks
  leftStick = new Joystick(0);
  rightStick = new Joystick(1);

  //Drivestick




  //Armstick
  JoystickButton *right7 = new JoystickButton(rightStick, 7);
  right7->WhenPressed(new CollectPreset());
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
