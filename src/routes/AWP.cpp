#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void AWP(){
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
    MoveEncoderPID(TestPara, 100, 6, 0.3, 100, true);
    TurnMaxTimePID(TestPara, 50, 0.3, true);
    MoveEncoderPID(TestPara, 100, 3, 0.3, 57, true);
    wait(100,msec);
    RunRoller(-100); //score onto alliance stake
    wait(1000, msec);
    MoveEncoderPID(TestPara, -100, 3, 0.3, 57, true);
    TurnMaxTimePID(TestPara, -85, 0.5, true);
    Tilt.set(true); // down to grab mogo

    MoveEncoderPID(TestPara, 100, 25, 0.3, -87, false);
    MoveEncoderPID(TestPara, 40, 25, 0.3, -87, true); //slow down to grab mogo
    Clamp.set(true); //close clamp 
    wait(200,msec);
    MoveEncoderPID(TestPara, 100, 2, 0.4,-87, true); //move back to let goal sit in
    Tilt.set(false); // tilt mogo
    RunRoller(-100); //run intake
    TurnMaxTimePID(TestPara, 107, 0.8,true);
    MoveEncoderPID(TestPara, -100, 20, 0.4, 107, true); //move back to let goal sit in
    TurnMaxTimePID(TestPara, 140,0.4,true);
    MoveEncoderPID(TestPara, -60, 10, 0.4, 140, true); //grab ring 3
    TurnMaxTimePID(TestPara, -100,0.4,true); 
    MoveEncoderPID(TestPara, -100, 10, 0.4, -100, true); //move back to let goal sit in





}