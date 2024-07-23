#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void AWP(){
    //blue side
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    Pistake.set(false); //intake down
    Tilt.set(false); // ohly tilt 
    RunRoller(-100);//
    wait(180, msec);
    MoveEncoderPID(TestPara, 75, 2.2, 0.3, 0, true);
    RunRoller(0);
    MoveEncoderPID(TestPara, -75, 6, 0.3, 0, true ); // drive forward to clear ring
    wait(200, msec);
    TurnMaxTimePID(TestPara, 110, 0.6, true );        
    MoveEncoderPID(TestPara, 75, 8.6, 0.5, 110, true);
   
    TurnMaxTimePID(TestPara, 60, 0.6, true);
    MoveEncoderPID(TestPara, 70, 6, 0.5, 60, true);
    wait(100,msec);
    RunRoller(-100); //score onto alliance stake
    wait(1450, msec); //wait for scoring both rings onto alliance stake
    RunRoller(0); //run intake
    MoveEncoderPID(TestPara, -90, 5, 0.3, 60, true);// delta angle needs to be 58(ik its weird)
    TurnMaxTimePID(TestPara, -80, .8, true);
    Tilt.set(true); // down to grab mogo

    MoveEncoderPID(TestPara, 100, 30, 0.5, -80, false);
    MoveEncoderPID(TestPara, 70,10,0.3,-80,true);
    MoveEncoderPID(TestPara, 40, 5, 0.3, -80, true); //slow down to grab mogo
    Clamp.set(true); //close clamp 
    wait(380,msec);
    MoveEncoderPID(TestPara, 100, 1.5, 0.4,-80, true); //move back to let goal sit in
    Tilt.set(false); // tilt mogo
   // wait(380,msec);

    TurnMaxTimePID(TestPara,106, 0.8,true); 
    RunRoller(-100); //run intake
    //wait(380,msec);
    MoveEncoderPID(TestPara, -100, 28, 0.4, 106, true); //grab ring 2
    TurnMaxTimePID(TestPara, 140,0.4,true);
    MoveEncoderPID(TestPara, -85, 16, 0.4, 140, true); //grab ring 3
    TurnMaxTimePID(TestPara, -50, 0.7, true);
    MoveEncoderPID(TestPara, -100, 55, 0.1, -50,true);
    // TurnMaxTimePID(TestPara, -115,0.4,true); 
    // MoveEncoderPID(TestPara, -100, 13, 0.4, -115, true); //grab ring 4
    // wait(400,msec);
    // TurnMaxTimePID(TestPara, -35,0.6,true); //turn to face ladder
    // MoveEncoderPID(TestPara, -100, 30, 0.4, -35, false); //touch ladder
   //should be within 15 seconds





}

void redAWP(){
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    Pistake.set(false); //intake down
    Tilt.set(false); // ohly tilt 
    RunRoller(-100);//
    wait(180, msec);
    MoveEncoderPID(TestPara, 75, 2.2, 0.3, 0, true);
    RunRoller(0);
    MoveEncoderPID(TestPara, -75, 6, 0.3, 0, true ); // drive forward to clear ring
    wait(200, msec);
    TurnMaxTimePID(TestPara, -140, 0.6, true );        
    MoveEncoderPID(TestPara, 50, 7.5, 0.5, -140, true);
   
    TurnMaxTimePID(TestPara, -60, 0.8, true);
    MoveEncoderPID(TestPara, 100, 11, 0.5, -60, true);
    wait(100,msec);
    RunRoller(-100); //score onto alliance stake
    wait(1450, msec); //wait for scoring both rings onto alliance stake
    RunRoller(0); //run intake
    MoveEncoderPID(TestPara, -60, 5.8, 0.5, -60, true);// delta angle needs to be 58(ik its weird)
    TurnMaxTimePID(TestPara, 80, .8, true);
    Tilt.set(true); // down to grab mogo

    MoveEncoderPID(TestPara, 100, 30, 0.5, 80, true);
    MoveEncoderPID(TestPara, 70,10,0.3,80,true);
     //slow down to grab mogo
    Clamp.set(true); //close clamp 
    wait(380,msec);
    MoveEncoderPID(TestPara, 100, 1.5, 0.4, 80, true); //move back to let goal sit in
    Tilt.set(false); // tilt mogo
   // wait(380,msec);

    TurnMaxTimePID(TestPara,-105, 0.6,true); 
    RunRoller(-100); //run intake
    //wait(380,msec);
    MoveEncoderPID(TestPara, -100, 27, 0.4, -105, true); //grab ring 2
    TurnMaxTimePID(TestPara, -150, 0.4,true);
    MoveEncoderPID(TestPara, -85, 13, 0.4, -150, true); //grab ring 3
    TurnMaxTimePID(TestPara, 50, 0.7, true);
    MoveEncoderPID(TestPara,-100, 55 , 0.3, 50, true);
   
   
    //MoveEncoderPID(TestPara, -100, 55, 0.1, 60,true);
    //MoveEncoderPID(TestPara, -100, 20, 0.3, 0, true);

    // TurnMaxTimePID(TestPara, -115,0.4,true); 
    // MoveEncoderPID(TestPara, -100, 13, 0.4, -115, true); //grab ring 4
    // wait(400,msec);
    // TurnMaxTimePID(TestPara, -35,0.6,true); //turn to face ladder
    // MoveEncoderPID(TestPara, -100, 30, 0.4, -35, false); //touch ladder
   //should be within 15 seconds
}