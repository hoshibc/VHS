#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);


void RedSafeMogo()
{
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    Pistake.set(false); //intake down
    Tilt.set(false); // ohly tilt 
    RunRoller(-100);//
    wait(200, msec);
    MoveEncoderPID(TestPara, 100, 2.2, 0.3, 0, true);
    RunRoller(0);
    MoveEncoderPID(TestPara, -100, 5, 0.3, 0, true ); // drive forward to clear ring
    wait(200, msec);
    TurnMaxTimePID(TestPara, 100, 0.5, true );        
    MoveEncoderPID(TestPara, 100, 7.8, 0.3, 100, true);
    TurnMaxTimePID(TestPara, 50, 0.3, true);
    MoveEncoderPID(TestPara, 100, 3, 0.3, 57, true);
    wait(100,msec);
    RunRoller(-100); //score onto alliance stake
    wait(1250, msec); //wait for scoring both rings onto alliance stake
    RunRoller(0); //run intake
    MoveEncoderPID(TestPara, -100, 2.4, 0.3, 57, true);
    TurnMaxTimePID(TestPara, -88, 0.5, true);
    Tilt.set(true); // down to grab mogo

    MoveEncoderPID(TestPara, 100, 25, 0.3, -88, false);
    MoveEncoderPID(TestPara, 40, 25, 0.3, -88, true); //slow down to grab mogo
    Clamp.set(true); //close clamp 
    wait(400,msec);
    MoveEncoderPID(TestPara, 100, 2, 0.4,-88, true); //move back to let goal sit in
    Tilt.set(false); // tilt mogo
    wait(350,msec);



}