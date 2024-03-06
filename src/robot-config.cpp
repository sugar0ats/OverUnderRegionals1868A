#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;
controller Controller1;

// VEXcode device constructors
motor intake = motor(PORT2, ratio6_1, false);
motor LeftDTMotorA = motor(PORT3, ratio6_1, false);
motor LeftDTMotorB = motor(PORT11, ratio6_1, true);
motor LeftDTMotorC = motor(PORT19, ratio6_1, true);
motor_group LeftDT = motor_group(LeftDTMotorA, LeftDTMotorB, LeftDTMotorC);
motor RightDTMotorA = motor(PORT9, ratio6_1, true);
motor RightDTMotorB = motor(PORT4, ratio6_1, false);
motor RightDTMotorC = motor(PORT10, ratio6_1, false);
motor_group RightDT = motor_group(RightDTMotorA, RightDTMotorB, RightDTMotorC);

digital_out hang = digital_out(Brain.ThreeWirePort.G);
inertial inertialSensor = inertial(PORT20);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}