/*
 * FinalRobot.h
 *
 *  Created on: Dec 6, 2013
 *      Author: C15Jennae.Steinmiller
 */

#ifndef FINALROBOT_H_
#define FINALROBOT_H_


//
// motion() sets the motors so that the robot will move in the specified direction for the specified length of time
//
void motion(int direction);

int movingAverage(int sampleStream[]);

void senseLeft();

void senseRight();

void senseCenter();

char IsLeftHighLow(int threshhold);

char IsRightHighLow(int threshhold);

char IsCenterHighLow(int threshhold);

#endif /* FINALROBOT_H_ */
