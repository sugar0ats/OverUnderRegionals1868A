#include "vex.h"

using namespace vex;

competition Competition;

void pre_auton(void) {
  vexcodeInit();
  intake.setVelocity(50, percent);
  hang.set(false);

}

/*---------------------------------------------------------------------------*/
//                CONSTANTS
/*---------------------------------------------------------------------------*/
int deadband = 3;

/*---------------------------------------------------------------------------*/
//                 AUTONS
/*---------------------------------------------------------------------------*/

void autonomous(void) {
}

/*---------------------------------------------------------------------------*/
//          HELPER FUNCTIONS
/*---------------------------------------------------------------------------*/
int expoTurning(int joystickVal) {
  int retVal = 0;
  if (abs(joystickVal) > deadband) {
    int direction = abs(joystickVal) / joystickVal;
    retVal = direction * (0.7 * pow(1.0387, abs(joystickVal)) - 0.7 + 0.096 * abs(joystickVal));
  }
  return retVal;
}

void toggle_hang(){
  hang.set(!hang.value());
  wait(200, msec);
}

/*---------------------------------------------------------------------------*/
//          USER CONTROL
/*---------------------------------------------------------------------------*/
void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    int leftmotorspeed = Controller1.Axis3.position() + expoTurning(Controller1.Axis1.position());
    int rightmotorspeed = Controller1.Axis3.position() - expoTurning(Controller1.Axis1.position());

    if(abs(leftmotorspeed) < deadband){
      LeftDT.setVelocity(0, percent);
    } else{
      LeftDT.setVelocity(leftmotorspeed, percent);
    }
      if(abs(rightmotorspeed) < deadband){
      RightDT.setVelocity(0, percent);
    } else{
      RightDT.setVelocity(rightmotorspeed, percent);
    }

    if(Controller1.ButtonL1.pressing()){
      intake.spin(forward);
    } else if(Controller1.ButtonR1.pressing()){
      intake.spin(reverse);
    } else{
      intake.stop();
    }

    LeftDT.spin(forward);
    RightDT.spin(forward);

    Controller1.ButtonUp.pressed(toggle_hang);

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

/*---------------------------------------------------------------------------*/
//         MAIN
/*---------------------------------------------------------------------------*/
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
