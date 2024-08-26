#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void ringquad() {
    //version number 1.0 draft route
    //issues: intake range, time to end
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    
    
    MoveEncoderPID(TestPara, 100, 7.5, 0.4, 0, true); //backup toward goal
    TurnMaxTimePID(TestPara, 26, 0.5,true); //turn to face flat edge of goal
    MoveEncoderPID(TestPara, 100, 13, 0.4, 26, true); //move back to align with goal
    MoveEncoderPID(TestPara, 30, 13, 0.4, 26, true); //move slower to prevent goal from being knocked
    Clamp.set(true); //close clamp 
    wait(200,msec);
    MoveEncoderPID(TestPara, 100, 0.2, 0.4,30, true); //move back to let goal sit in
   // Tilt.set(false); // tilt mogo
    RunRoller(-100); //run intake
    TurnMaxTimePID(TestPara, -125, 0.9, true); //turn to face ring 1
    MoveEncoderPID(TestPara, -100, 23, 0.4, -125, true);
    wait(200,msec);
    TurnMaxTimePID(TestPara, -100, 0.4, true); //turn to face ring 2
    MoveEncoderPID(TestPara, -100, 11, 0.4, -100, true); //pickup ring 2
    wait(100,msec);
    //MoveEncoderPID(TestPara, 100, 7, 0.4, -105, true); 
    TurnMaxTimePID(TestPara, 23, 0.4, true); 
    MoveEncoderPID(TestPara, -100, 28, 0.4, 23, true); //backup closer to ring 3
    //TurnMaxTimePID(TestPara, -90, 0.4, true);  //turn to face ring 3
   // MoveEncoderPID(TestPara, -100, 18, 0.4, -90, true); //drive into ring 3
    TurnMaxTimePID(TestPara, 65, 0.8, true);
    
    
    intakePiston.set(true);
    MoveEncoderPID(TestPara, -100, 50, 0.2, 65, true); //drive into ring 4'
    Clamp.set(false);
   // Tilt.set(true);
    MoveEncoderPID(TestPara, -30, 6, 0.2, 65, true); //drive into ring 4
    intakePiston.set(false);
    wait(200,msec);
    RunRoller(0);
    MoveEncoderPID(TestPara, 70, 15, 0.4, 65,true);
    //TurnMaxTimePID(TestPara, 140, 0.8, true);
    //MoveEncoderPID(TestPara, -70, 10, 0.2, 140, false); //drive into ladder

    TurnMaxTimePID(TestPara, -125, 0.9, true);
    MoveEncoderPID(TestPara, 100, 32, 0.3, -125, true);
    MoveEncoderPID(TestPara, -100,  6, 0.3, -125, true);
    TurnMaxTimePID(TestPara, 180, 0.9, true);
    MoveEncoderPID(TestPara, 100, 10, 0.3, 180, true);
    RunRoller(-100);
    wait(1200,msec);
    MoveEncoderPID(TestPara, -100, 36, 0.3, 180, true);

    //wait(200,msec); //wait for mogo to be dropped
}       

void red_ringquad(){
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    MoveEncoderPID(TestPara, 100, 4, 0.4, 0, true); //backup toward goal
    TurnMaxTimePID(TestPara, -30, 0.4,true); //turn to face flat edge of goal
    MoveEncoderPID(TestPara, 100, 13, 0.4, -30, true); //move back to align with goal
    MoveEncoderPID(TestPara, 30, 13, 0.4, -30, true); //move slower to prevent goal from being knocked
    Clamp.set(true); //close clamp 
    wait(200,msec);
    MoveEncoderPID(TestPara, 100, 0.2, 0.4,-30, true); //move back to let goal sit in
  //  Tilt.set(false); // tilt mogo
    RunRoller(-100); //run intake
    TurnMaxTimePID(TestPara, 135, 0.8, true); //turn to face ring 1
    MoveEncoderPID(TestPara, -100, 23, 0.4, 135, true);
    wait(200,msec);
    TurnMaxTimePID(TestPara, 98, 0.4, true); //turn to face ring 2
    MoveEncoderPID(TestPara, -100, 14, 0.4, 98, true); //pickup ring 2
    wait(100,msec);
    //MoveEncoderPID(TestPara, 100, 7, 0.4, -105, true); 
    TurnMaxTimePID(TestPara,  -10, 0.4, true); 
    MoveEncoderPID(TestPara, -100, 28, 0.4, -10, true); //backup closer to ring 3
    //TurnMaxTimePID(TestPara, -90, 0.4, true);  //turn to face ring 3
   // MoveEncoderPID(TestPara, -100, 18, 0.4, -90, true); //drive into ring 3
    TurnMaxTimePID(TestPara, -78, 0.8, true);
    intakePiston.set(true);
    MoveEncoderPID(TestPara, -100, 50, 0.2, -78, true); //drive into ring 4
    MoveEncoderPID(TestPara, -30, 6, 0.2, -78, true); //drive into ring 4
    intakePiston.set(false);
    wait(400,msec);
    MoveEncoderPID(TestPara, 70, 15, 0.4, -78,true);
    TurnMaxTimePID(TestPara, -140, 0.8, true);
    MoveEncoderPID(TestPara, -70, 10, 0.2, -140, false);



}