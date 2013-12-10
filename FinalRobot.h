/*
 * FinalRobot.h
 *
 *  Created on: Dec 6, 2013
 *      Author: C15Jennae.Steinmiller
 *      Description: FinalRobot.h declares all function calls from main.c.
 */

#ifndef FINALROBOT_H_
#define FINALROBOT_H_


//
// motion() sets the motors so that the robot will move in the specified direction for the specified length of time
//
void motion(int direction);

//
// senseLeft() sets up the left sensor so that it will read in values
//
void senseLeft();

//
// senseRight() sets up the right sensor so that it will read in values.
// **note: not used in my robot algorithm
//
void senseRight();

//
// senseCenter() sets up the center sensor so that it will read in values
//
void senseCenter();

//
// IsLeftHighLow(int threshhold) returns a char which represents whether the left sensor is sensing a wall or not.
// 0 is returned if there is no wall, 1 is returned if there is a wall.
//
char IsLeftHighLow(int threshhold);

//
// IsRightHighLow(int threshhold) returns a char which represents whether the right sensor is sensing a wall or not.
// 0 is returned if there is no wall, 1 is returned if there is a wall.
// **note: not used in my robot algorithm
//
char IsRightHighLow(int threshhold);

//
// IsCenterHighLow(int threshhold) returns a char which represents whether the center sensor is sensing a wall or not.
// 0 is returned if there is no wall, 1 is returned if there is a wall.
//
char IsCenterHighLow(int threshhold);

#endif /* FINALROBOT_H_ */
