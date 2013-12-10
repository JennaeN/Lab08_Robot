/*
 * FinalRobot.c
 *
 *  Created on: Dec 6, 2013
 *      Author: C15Jennae.Steinmiller
 *      Description: FinalRobot.c defines the functions that are being called in main.c and initialized in FinalRobot.h
 */

#include <msp430g2553.h>

void senseLeft() {
	ADC10CTL0 &= ~ENC;             			// Sampling and conversion stop
	ADC10CTL1 = INCH_4;                     // input channel A4
	ADC10AE0 |= BIT4;                         	// PA.1 ADC option select

	ADC10CTL0 |= ENC + ADC10SC;         // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);
	// LPM0, ADC10_ISR will force exit
}

void senseRight() {
	ADC10CTL0 &= ~ENC;           			  // Sampling and conversion stop
	ADC10CTL1 = INCH_5;                       // input channel A5
	ADC10AE0 |= BIT5;                         	  // PA.1 ADC option select

	ADC10CTL0 |= ENC + ADC10SC;         // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);
	// LPM0, ADC10_ISR will force exit
}

void senseCenter() {
	ADC10CTL0 &= ~ENC;             			// Sampling and conversion stop
	ADC10CTL1 = INCH_3;						//input channel A3
	ADC10AE0 |= BIT3;							// PA ADC option select

	ADC10CTL0 |= ENC + ADC10SC;         // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);
	// LPM0, ADC10_ISR will force exit
}

char IsRightHighLow(int threshhold) {

	// return 0 if no wall, otherwise return 1
	// wall is found if the value sensed is greater than the threshold
	if (ADC10MEM < threshold) {
		return 0;
	} else {
		return 1;
	}
}

char IsLeftHighLow(int threshold) {

	// return 0 if no wall, otherwise return 1
	// wall is found if the value sensed is greater than the threshold
	if (ADC10MEM < threshhold) {
		return 0;
	} else {
		return 1;
	}
}

char IsCenterHighLow(int threshold) {

	// return 0 if no wall, otherwise return 1
	// wall is found if the value sensed is greater than the threshold
	if (ADC10MEM < threshhold) {
		return 0;
	} else {
		return 1;
	}
}

void motion(int direction) {

	//clears TA0 and Ta1 so they can be programmed for a different direction
	TA0CCTL1 &= ~OUTMOD_7;
	TA0CCTL0 &= ~OUTMOD_7;
	TA1CCTL1 &= ~OUTMOD_7;
	TA1CCTL0 &= ~OUTMOD_7;

	if (direction == 1) {

		//to move forward
		TA0CCTL1 |= OUTMOD_7;         // set to Reset / Set mode
		TA0CCTL0 |= OUTMOD_5;			//set to Reset
		TA1CCTL1 |= OUTMOD_7;			// set to Reset / Set mode
		TA1CCTL0 |= OUTMOD_5;			//set to Reset

	}

	else if (direction == 2) {

		//to move backward
		TA0CCTL1 |= OUTMOD_5;		//set to reset
		TA0CCTL0 |= OUTMOD_4;		//set to toggle
		TA1CCTL1 |= OUTMOD_5;		//set to reset
		TA1CCTL0 |= OUTMOD_4;		//set to toggle

	}

	else if (direction == 3) {

		//to move left
		TA0CCTL1 |= OUTMOD_5;         // set to Reset
		TA0CCTL0 |= OUTMOD_4;			//set to Toggle
		TA1CCTL1 |= OUTMOD_7;			// set to Reset / Set mode
		TA1CCTL0 |= OUTMOD_5;			// set to Reset

	}

	else {

		//to move right
		TA0CCTL1 |= OUTMOD_7;         // set to Reset / Set mode
		TA0CCTL0 |= OUTMOD_5;			//set to Reset
		TA1CCTL1 |= OUTMOD_5;			//set to Reset
		TA1CCTL0 |= OUTMOD_4;			//set to Toggle

	}
	//delays movement for smoothness
	__delay_cycles(1000);
}

