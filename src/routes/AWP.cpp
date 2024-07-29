#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void AWP(){
    //blue side
    




}

void redAWP(){
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    Pistake.set(false); //intake down
    
    
    RunRoller(-100);//
    wait(180, msec);
    MoveEncoderPID(TestPara, 75, 2.2, 0.3, 0, true);
    RunRoller(0);
    MoveEncoderPID(TestPara, -75, 6, 0.3, 0, true ); // drive forward to clear ring
    wait(200, msec);
    TurnMaxTimePID(TestPara, -140, 0.8, true );        
    MoveEncoderPID(TestPara, 50, 11.8, 0.5, -140, true);
    MoveEncoderPID(TestPara, -40, .5, 0.5, -140, true);
    TurnMaxTimePID(TestPara, -63, 0.8, true);
    MoveEncoderPID(TestPara, 70, 7, 0.5, -63, true);
    MoveEncoderPID(TestPara, 40, 4 , 0.3, -64, true);
    wait(100,msec);
    RunRoller(-100); //score onto alliance stake
    wait(600, msec); //wait for scoring both rings onto alliance stake
    RunRoller(0); //run intake
    MoveEncoderPID(TestPara, -40, 4, 0.7, -63, true);// delta angle needs to be 58(ik its weird)
    TurnMaxTimePID(TestPara, 77, 0.8, true);
   // Tilt.set(true); // up to grab mogo

    MoveEncoderPID(TestPara, 97.5, 36, 0.5, 77, true);
    MoveEncoderPID(TestPara, 50,15,0.6,77,true);
     //slow down to grab mogo
    Clamp.set(true); //close clamp 
    wait(380,msec);
    MoveEncoderPID(TestPara, 100, 1.5, 0.4, 77, true); //move back to let goal sit in
    //Tilt.set(false); // tilt mogo

    RunRoller(100);
    TurnMaxTimePID(TestPara,-100, 0.6,true); 
    RunRoller(-100); //run intake
    //wait(380,msec);
    MoveEncoderPID(TestPara, -100, 23, 0.4, -100, true); //grab ring 2
    TurnMaxTimePID(TestPara, -150, 0.4,true);
    MoveEncoderPID(TestPara, -85, 13, 0.4, -150, true); //grab ring 3
    TurnMaxTimePID(TestPara, 50, 0.7, true);
    MoveEncoderPID(TestPara,-100, 55 , 0.3, 50, true);
   
   
    //MoveEncoderPID(TestPara, -100, 55, 0.1, 60,true);
    //MoveEncoderPID(TestPara, -100, 20, 0.3, 0, true);
    // TurnMaxTimePID(TestPara, -115,0.4,true); 
    // MoveEncoderPID(TestPara, -100, 13, 0.4, -115, true); //grab ring 4
    // wait(400,msec);
    // TurnMaxTimePID(TestPara, -35,0.6,true); //turn t
    //o face ladder
    // MoveEncoderPID(TestPara, -100, 30, 0.4, -35, false); //touch ladder
   //should be within 15 seconds
}

void redSafeAWP() {
     PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    Pistake.set(false); //intake down
    
    RunRoller(-100);//
    wait(180, msec);
    MoveEncoderPID(TestPara, 75, 2.2, 0.3, 0, true);
    RunRoller(0);
    MoveEncoderPID(TestPara, -75, 6, 0.3, 0, true ); // drive forward to clear ring
    wait(200, msec);
    TurnMaxTimePID(TestPara, -140, 0.8, true );        
    MoveEncoderPID(TestPara, 50, 11.8, 0.5, -140, true);
    MoveEncoderPID(TestPara, -40, .5, 0.5, -140, true);
    TurnMaxTimePID(TestPara, -63, 0.8, true);
    MoveEncoderPID(TestPara, 70, 7, 0.5, -63, true);
    MoveEncoderPID(TestPara, 40, 4 , 0.3, -64, true);
    wait(100,msec);
    RunRoller(-100); //score onto alliance stake
    wait(600, msec); //wait for scoring both rings onto alliance stake
    RunRoller(0); //run intake
    MoveEncoderPID(TestPara, -40, 4, 0.7, -63, true);// delta angle needs to be 58(ik its weird)
    TurnMaxTimePID(TestPara, 77, 0.8, true);
    //Tilt.set(true); // up to grab mogo

    MoveEncoderPID(TestPara, 97.5, 36, 0.5, 77, true);
    MoveEncoderPID(TestPara, 50,15,0.6,77,true);
     //slow down to grab mogo
    Clamp.set(true); //close clamp 
    wait(380,msec);
    MoveEncoderPID(TestPara, 100, 1.5, 0.4, 77, true); //move back to let goal sit in
   // Tilt.set(false); // tilt mogo
   // wait(380,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara,-150, 0.6,true); 
    RunRoller(-100);
    MoveEncoderPID(TestPara, -90, 30, 0.6, -150, true);
    wait(200,msec);
    TurnMaxTimePID(TestPara, 10, 0.8, true);
    MoveEncoderPID(TestPara, -100 ,15 , 0.3, 10, true);  
    RunRoller(0);
    MoveEncoderPID(TestPara, -100, 23, 0.4, 10, true);                                                                  





}
void redSuperSafe() {
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    
    MoveEncoderPID(TestPara, 80, 32, 0.3,0, true);
    MoveEncoderPID(TestPara, 40, 4, 0.3, 0, true); //grab mogro
    Clamp.set(false);
    wait(30,msec);
    MoveEncoderPID(TestPara, 40, 6, 0.3, 0, true);
    Pistake.set(false);
    //grab first ring
    RunRoller(-100);
    TurnMaxTimePID(TestPara, 58, 0.8, true);
    MoveEncoderPID(TestPara, -80, 35, 0.3,58, true); //pickup first ring
    TurnMaxTimePID(TestPara, 150, 0.8, true); //approach second ring
    MoveEncoderPID(TestPara, -70, 15, 0.3,150, true); //pickup second ring
    MoveEncoderPID(TestPara, 80, 5, 0.3,150, true); //pickup second ring
    TurnMaxTimePID(TestPara, 180, 0.5, true); //approach third ring
    MoveEncoderPID(TestPara, -70, 9, 0.3,180, true); //pickup third ring 
    MoveEncoderPID(TestPara, 70, 12, 0.3,180, true); //approach ladder 
    TurnMaxTimePID(TestPara, -147, 0.8, true); //turn to face ladder
    MoveEncoderPID(TestPara, -70, 37, 0.3,-147, true); //touch ladder with flex wheels
    RunRoller(0);




}