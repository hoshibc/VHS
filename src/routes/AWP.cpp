#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void AWP(){
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    Pistake.set(false);
    RunRoller(-100);
    wait(300, msec);
    MoveEncoderPID(TestPara, 100, 5, 0.3, 0, true);
    RunRoller(0);

}