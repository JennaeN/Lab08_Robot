Lab08_Robot
===========


Overview
-------------

During this lab, you will combine the previous laboratory assignments and program your robot to autonomously navigate through a maze. On the last day of the lab, each section will hold a competition to see who can solve the maze the fastest. The fastest time in ECE 382 will have their name engraved on a plaque in the CSD lab. Believe it or not, the main goal of this lab is for you to have some fun with computer engineering!

Requirements
-----------------

You must write a program that autonomously navigates your robot through a maze (Figure 1) while meeting the following requirements:

    Your robot must always start at the home position.
    Your robot is considered successful only if it finds one of the three exits and moves partially out of the maze.
    A large portion of your grade depends on which door you exit.
        Door 1 - Required Functionality
        Door 2 - B Functionality
        Door 3 - A Functionality
        Bonus! Navigate from the A door back to the entrance using the same algorithm.
    Your robot must solve the maze in less than three minutes.
    Your robot will be stopped if it touches the wall more than twice.
    Your robot must use the IR sensors to find its path through the maze.

Do not step onto the maze since the floor will not support your weight. You will notice the maze floor is cracked from cadets who ignored this advice.
Competition Requirements

All the laboratory requirements above are required to be met for the maze, with the following additional requirements:

    Each robot will get only three official attempts to complete the maze. The best time will be used for your score.
    You must notify a referee/instructor before you make an official attempt.
    Your robot must find and exit through Door 3.
    The robot with a lowest adjusted time will be the winner.
    Each collision with a wall will add an additional 20 seconds to your total time.

Prelab
-------

Paste the grading section in your lab notebook as the first page of this lab.

Include whatever information from this lab you think will be useful in creating your program.

Consider your maze navigation strategy. Write pseudocode to show what your main program loop will look like.
Hints

There are a variety of techniques that cadets have used in the past to solve the maze. Here are a few:

    Use a wall-following algorithm (i.e., it tries to maintain a certain distance from the wall).
    Use an empty-space detecting algorithm. If it gets too close to a wall, it steers away.

Maze Diagram
-------------------

Figure 1: Diagram of the maze your robot must navigate. Your demonstration grade depends on which door you go through.


Grading
----------

Item 	Grade 	Points 	Out of 	Date 	Due

Prelab 	On-Time: 0 ---- Check Minus ---- Check ---- Check Plus 		10 		BOC L38

Required Functionality 	On-Time ------------------------------------------------------------------ Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 		40 		COB L40

B Functionality 	On-Time ------------------------------------------------------------------ Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 		10 		COB L40

A Functionality 	On-Time ------------------------------------------------------------------ Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 		10 		COB L40

Bonus Functionality 	On-Time -------------------------------------------------------------- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 		10 		COB L40

Use of Git / Github 	On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 		10 		COB L40

Code Style 	On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 		10 		COB L40

README 	On-Time: 0 ---- Check Minus ---- Check ---- Check Plus ---- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 		10 		COB L40

Total 			100 	





DESIGN
-----------

My robot will be set up to use the front (center) sensor. When it detects a wall it will turn (pre-programmed turn) the direction needed to get through the maze.  

Basically, my robot will go straight until it senses a wall, turn left, go straight until a wall, turn right, go straight, turn right, sense wall, turn left, and it will have completed the maze. 

The code I will use to implement this may be found in my Lab07_Interface and Lab06_Library.
I will use the code from Lab06 to go straight, and will make it go straight until a 1 is detected from my Lab_07 code.

Go stright until wall is detected ~ 
if (direction == 1) {
                //to move forward
                TA0CCTL1 |= OUTMOD_7; // set to Reset / Set mode
                TA0CCTL0 |= OUTMOD_5;                        //set to Reset
                TA1CCTL1 |= OUTMOD_7;                        // set to Reset / Set mode
                TA1CCTL0 |= OUTMOD_5;                        //set to Reset
}

  void senseCenter() {
        ADC10CTL0 &= ~ENC; // Sampling and conversion stop
        ADC10CTL1 = INCH_3;                                                //input channel A3
        ADC10AE0 |= BIT3;                                                        // PA.1 ADC option select

char IsCenterHighLow(int threshhold) {
        if (ADC10MEM < threshhold) {
                return 0;
        } else {
                return 3;
        }


Turn left and then go straight~
 
         else if (direction == 3) {
                //to move left
                TA0CCTL1 |= OUTMOD_7; // set to Reset / Set mode
                TA0CCTL0 |= OUTMOD_5;                        //set to Reset
                TA1CCTL1 |= OUTMOD_5;                        //set to Reset
                TA1CCTL0 |= OUTMOD_4;                        //set to Toggle
        
    if (direction == 1) {
                //to move forward
                TA0CCTL1 |= OUTMOD_7; // set to Reset / Set mode
                TA0CCTL0 |= OUTMOD_5;                        //set to Reset
                TA1CCTL1 |= OUTMOD_7;                        // set to Reset / Set mode
                TA1CCTL0 |= OUTMOD_5;                        //set to Reset
}    

  void senseCenter() {
        ADC10CTL0 &= ~ENC; // Sampling and conversion stop
        ADC10CTL1 = INCH_3;                                                //input channel A3
        ADC10AE0 |= BIT3;                                                        // PA.1 ADC option select

char IsCenterHighLow(int threshhold) {
        if (ADC10MEM < threshhold) {
                return 0;
        } else {
                return 3;
    
    }    }

Turn right and then go straigt~
     else {
                //to move right
                TA0CCTL1 |= OUTMOD_5; // set to Reset
                TA0CCTL0 |= OUTMOD_4;                        //set to Toggle
                TA1CCTL1 |= OUTMOD_7;                        // set to Reset / Set mode
                TA1CCTL0 |= OUTMOD_5;                        // set to Reset
      }

   void senseCenter() {
        ADC10CTL0 &= ~ENC; // Sampling and conversion stop
        ADC10CTL1 = INCH_3;                                                //input channel A3
        ADC10AE0 |= BIT3;                                                        // PA.1 ADC option select

char IsCenterHighLow(int threshhold) {
        if (ADC10MEM < threshhold) {
                return 0;
        } else {
                return 3;
    
    }    }

  
  
  OUTCOMES
  ------------------
  
  I changed the entire algorithm for my robot. Originally, I thought it would be easiest to just preprogram everything. In the end, I found out that is the harder way to do it. Plus, it didn't get me additional functionality. So, why not just go for additional from the beginning, right?
  
  What algorithm was next? I decided to use a walking algorithm that would hug the left wall. I would make the robot walk by changing the duty cycle for each motor when I wanted to go forward. After quite a bit of testing, I found that this algorithm just wasn't making the sharp turns that I needed.
  
  Now what? A robot that would for the most part go straight along the left wall and make tight turns. I didn't want my robot to run into the wall while it was going straight - obstacle number one. I decided that the duty cycles for the motors still couldn't be exactly the same. They needed to be ever so slightly off so that my robot would always move away from the wall, not towards it. 
  Obstacle number two - if the robot got too far, I needed to turn back into the wall. 
  Obstacle number three - running into corners.
  
  To account for all of these obstacles, I needed 3 while loops. The first while  loop for when the robot sensed nothing. The second for when the robot only sensed a left wall. The third for when the robot sensed something in front of it. 
  
  The first while loop made the robot turn left towards the wall. When it could sense the wall again, it would jump into the second while loop and start going straight while it sensed the wall to its left. When it ran into a corner, it would turn right until it could no longer sense the corner.
  
  Last, I had to change where the sensors were pointing. Originally, I had them pointing at right angles, but I found that this wasn't efficient. When the robot sensed the end of the left wall, it wasn't sensing it soon enough, so it would get to far away from the wall by the time it turned. I decided to make that sensor point more forward. Then, the robot wasn't completely finishing the right turns it was making. I decided to point that sensor further toward the left sensor, that way it would drive farther away from the wall, instead of closer.
  
  Robot Bender? Working.
