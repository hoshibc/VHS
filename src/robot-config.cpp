#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructor
controller Controller1 = controller(primary);

// Left side drivetrain
motor LF = motor(PORT13, ratio6_1, false);
motor LM = motor(PORT12, ratio6_1, false);
motor LB = motor(PORT1, ratio6_1, false);

// Right side drivetrain
motor RF = motor(PORT5, ratio6_1, true);
motor RM = motor(PORT3, ratio6_1, true);
motor RB = motor(PORT14, ratio6_1, true);

// Intake motor 
motor In1 = motor(PORT2, ratio6_1, false);

// Lift 
motor lift= motor(PORT11, ratio36_1, true);

// Color sensor
optical OpSens = optical(PORT1);

//define lift to brake when stopped

//Motor Groups
motor_group Roller = motor_group(In1);

//Pistons
digital_out intakePiston = digital_out(Brain.ThreeWirePort.H);
digital_out Clamp = digital_out(Brain.ThreeWirePort.B);

//Gyro and stuff for PID
inertial Gyro = inertial(PORT4);

//Naming convention: 

// Important variables
const double wheelDiam = 2.75;
const double wheelToMotorRatio = 48.0/36;

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}