/*******************************************
 * Author: C2C Jennae Steinmiller
 * Created: 06 December, 2013
 * Description: Main.c is used to handle the overall flow of information in Lab08_Robot.
 * It calls FinalRobot.h and FinalRobot.c in order to carry out functionality. As a whole, Lab08_Robot
 * controls the movement of my robot, Bender. It calls a number of functions taken from my Lab06_Robot and Lab07_Sensor files.
 * These functions allow my robot to make its way through the maze and back. The left and front sensors work together so that the robot
 * does not hit the left wall of the maze and can successfully complete left and right turns.
 * Documentation: None
 *******************************************/

#include <msp430.h> 
#include "FinalRobot.h"
/*
 * main.c
 */

// Define constants for motion()
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

int main(void) {

	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled

	senseCenter(); 	//Center sensor is initialized

	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0; // Select SMCLK (this is the slowest clock)

	P1DIR |= BIT1;				//TAO.0
	P1SEL |= BIT1;

	P1DIR |= BIT2;				//TAO.1
	P1SEL |= BIT2;

	P2DIR |= BIT0;				//TA1.0
	P2SEL |= BIT0;

	P2DIR |= BIT1;				//TA1.1
	P2SEL |= BIT1;

	TA0CTL &= ~MC1 | MC0;            // stop timer A0
	TA1CTL &= ~MC1 | MC0;

	TA0CTL |= TACLR;                // clear timer A0
	TA1CTL |= TACLR;

	TA0CTL |= TASSEL1;           // configure for SMCLK
	TA1CTL |= TASSEL1;

	//Set duty cycles unequal so that the robot is slowly moving away from the wall when going straight.
	//The robot will turn back to the wall if it gets to far away, but has no correction for if it gets to close.
	//For this reason, the robot is continually turning away from the wall.

	TA0CCR0 = 100; 	 			// set signal period to 100 clock cycles (~100 microseconds)
	TA0CCR1 = 54;                // set duty cycle to 54/100 (54%)

	TA1CCR0 = 100;
	TA1CCR1 = 50;					// set duty cycle to 50/100 (50%)

	TA0CTL |= MC0;                // count up
	TA1CTL |= MC0;

	//Initialize variables
	char frontSensor = 0;
	char leftSensor = 0;

	//Infinite loop
	while (1) {

		//When the robot does not sense anything
		while (frontSensor == 0 && leftSensor == 0) {

			//The robot will turn back to the wall
			motion(LEFT);

			//Update the values of leftSensor and frontSensor
			senseLeft();
			leftSensor = IsLeftHighLow(0x2FF);

			senseCenter();
			frontSensor = IsCenterHighLow(0x2CF);

		}

		//When the robot only senses a wall to the left
		while (frontSensor == 0 && leftSensor != 0) {

			//Move forward (slightly away from the wall)
			motion(FORWARD);

			//Update the values of leftSensor and frontSensor
			senseLeft();
			leftSensor = IsLeftHighLow(0x2FF);

			senseCenter();
			frontSensor = IsCenterHighLow(0x2CF);

		}

		//When there is a wall in front of the robot
		while (frontSensor != 0) {

			//Turn away from the wall
			motion(RIGHT);

			//Update the value of frontSensor
			senseCenter();
			frontSensor = IsCenterHighLow(0x2CF);
		}
	}

	return 0;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {
	__bic_SR_register_on_exit(CPUOFF);
// Clear CPUOFF bit from 0(SR)
}
