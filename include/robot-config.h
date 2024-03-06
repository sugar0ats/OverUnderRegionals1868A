using namespace vex;

extern brain Brain;
extern controller Controller1;
extern motor_group LeftDT;
extern motor_group RightDT;
extern motor RightDTMotorA;
extern motor RightDTMotorB;
extern motor RightDTMotorC;
extern motor LeftDTMotorA;
extern motor LeftDTMotorB;
extern motor LeftDTMotorC;
extern motor intake;

extern inertial inertialSensor;
extern digital_out hang;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
