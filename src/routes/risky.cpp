#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void risky(){
    //version number 1.0 draft route
    //issues: intake range, time to end
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    MoveEncoderPID(TestPara, 100, 14, 0.4, 0, true); //backup toward goal
    TurnMaxTimePID(TestPara, 30, 0.4,true); //turn to face flat edge of goal
    MoveEncoderPID(TestPara, 100, 13, 0.4, 30, true); //move back to align with goal
    MoveEncoderPID(TestPara, 30, 13, 0.4, 30, true); //move slower to prevent goal from being knocked
    Clamp.set(false); //close clamp
    wait(200,msec);
    MoveEncoderPID(TestPara, 100, 0.2, 0.4,30, true); //move back to let goal sit in
    Tilt.set(false); // tilt mogo
    RunRoller(-100); //run intake
    TurnMaxTimePID(TestPara, -140, 0.8, true); //turn to face ring 1
    MoveEncoderPID(TestPara, -100, 26, 0.4, -140, true);
    wait(200,msec);
    TurnMaxTimePID(TestPara, -105, 0.4, true); //turn to face ring 2
    MoveEncoderPID(TestPara, -100, 10, 0.4, -105, true); //pickup ring 2
    wait(200,msec);
    MoveEncoderPID(TestPara, 100, 7, 0.4, -105, true); 
    TurnMaxTimePID(TestPara, -160, 0.4, true); 
    MoveEncoderPID(TestPara, 100, 18, 0.4, -160, true); //backup closer to ring 3
    TurnMaxTimePID(TestPara, -90, 0.4, true);  //turn to face ring 3
    MoveEncoderPID(TestPara, -100, 15, 0.4, -90, true); //drive into ring 3
    TurnMaxTimePID(TestPara, 70, 0.8, true);
    RunRoller(100); //run intake backwards to prevent ring from getting in
    MoveEncoderPID(TestPara, -100, 170, 0.2, 70, true); //drive into ring 4
    TurnMaxTimePID(TestPara, -120, 0.6, true); //turn to drop mogo
    Tilt.set(true); //drop mogo
    Clamp.set(true);
    //wait(200,msec); //wait for mogo to be dropped
    MoveEncoderPID(TestPara, -100, 87, 0.1, -120, false);//drive into mogo and ladder
}