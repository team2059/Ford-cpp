#include "Ford.h"
#include "OI.h"
#include "RobotMap.h"
#include "Commands/Autonomous/Autonomous.h"
OI* Ford::oi = NULL;
Drivetrain* Ford::drivetrain = NULL;
Pneumatics* Ford::pneumatics = NULL;
Ford::Ford() {
  oi = new OI();
}
void Ford::RobotInit() {
  SmartDashboard::PutNumber("CodeVersion", CODE_VERSION);
  pneumatics->SetCompressorEnabled(true);
}
void Ford::DisabledPeriodic() {
  Scheduler::GetInstance()->Run();
}
void Ford::AutonomousInit() {
  aut = new Autonomous(SmartDashboard::GetNumber("Auto Sequence"));
  printf("Enabling Auto Sequence %f\n", SmartDashboard::GetNumber("Auto Sequence"));
  if(aut != NULL) {
    aut->Start();
  }
}
void Ford::AutonomousPeriodic() {
  printf("Running auto.\n");
  Scheduler::GetInstance()->Run();
}
void Ford::TeleopInit() {
  if(aut != NULL) {
    aut->Cancel();
  }
}
void Ford::TeleopPeriodic() {
  Scheduler::GetInstance()->Run();
}
void Ford::TestPeriodic() {}
START_ROBOT_CLASS(Ford);
// vim: ts=2:sw=2:et
