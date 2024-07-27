#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void MogoRushQual() {
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    MoveEncoderPID(TestPara, 100, 48,0.4, 0, true);//Grab mogo rush angled
    OPMECH.set(true);
    MoveEncoderPID(TestPara, 100, 4, 0.4, 0, true);
    MoveEncoderPID(TestPara, -100, 25, 0.4, 0, true );
    TurnMaxTimePID(TestPara, 30, 0.5, true);
    MoveEncoderPID(TestPara,-100,  36, 0.4, 30, true);
    TurnMaxTimePID(TestPara, 120, 0.5, true);
    OPMECH.set(false);
    Tilt.set(true);

    MoveEncoderPID(TestPara, -60, 7.4, 0.4, 120, true);
    MoveEncoderPID(TestPara, 60, 2, 0.4, 120, true);
    TurnMaxTimePID(TestPara, -24, 0.7, true);
    MoveEncoderPID(TestPara, 100, 24, 0.4, -24, true);
    MoveEncoderPID(TestPara, 50, 10, 0.4, -24, true);

     //slow down to grab mogo
    Clamp.set(true); //close clamp 
    wait(100,msec);
    Tilt.set(false); // tilt mogo
    wait(100,msec);
    TurnMaxTimePID(TestPara, -90,  0.6, true);
    Pistake.set(false);
    RunRoller(-100);

    MoveEncoderPID(TestPara, -100, 30, 0.4, -90, true);
    wait(1000,msec);
    RunRoller(0);
    TurnMaxTimePID(TestPara, 30, 0.5, true);
    MoveEncoderPID(TestPara, -100, 25, 0.3, 30, true);
    TurnMaxTimePID(TestPara, -40, 0.5, true);
    MoveEncoderPID(TestPara, -100, 18, 0.4, -40, true);
    RunRoller(100);
    wait(200, msec);
    RunRoller(-100);
    wait(700, msec);
    MoveEncoderPID(TestPara, 100, 70, 0.4, -50, true);

}

void RedMogoRushQual()
{
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    MoveEncoderPID(TestPara, 100, 21.15, 0.4, 0, true);//Grab mogo rush angled
    Clamp.set(true);
    MoveEncoderPID(TestPara, 100, -4.3, 0.4,30, true);//peel back to get ready to turn to ring 1
    RunRoller(-100);
    TurnMaxTimePID(TestPara, -135, 0.8, true); //turn to face ring 1
    MoveEncoderPID(TestPara, -100,24, 0.3, -135, true);//Drive to Ring 1  


}