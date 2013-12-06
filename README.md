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
