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

  
