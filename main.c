#include <msp430.h> 
#include "FinalRobot.h"
/*
 * main.c
 */

#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

int main(void) {

	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled

	senseCenter();

	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0; // Select SMCLK (this is the slowest clock)

	P1DIR |= BIT1;
	P1SEL |= BIT1;				//TAO.0

	P1DIR |= BIT2;				//TAO.1
	P1SEL |= BIT2;

	P2DIR |= BIT0;				//TA1.0
	P2SEL |= BIT0;

	P2DIR |= BIT1;				//TA1.1
	P2SEL |= BIT1;

	TA0CTL &= ~MC1 | MC0;            // stop timer A0
	TA1CTL &= ~MC1 | MC0;

	TA0CTL |= TACLR;                // clear timer A0
	TA1CTL |= TACLR;                // clear timer A0

	TA0CTL |= TASSEL1;           // configure for SMCLK
	TA1CTL |= TASSEL1;           // configure for SMCLK

	TA0CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	TA0CCR1 = 60;                // set duty cycle to 60/100 (60%)

	TA1CCR0 = 100;
	TA1CCR1 = 60;

	TA0CTL |= MC0;                // count up
	TA1CTL |= MC0;

	while (1) {

		char frontSensor = 0;
		char rightSensor = 0;
		char leftSensor = 0;

		while (frontSensor == 0) {
			motion(FORWARD);

			ADC10CTL0 |= ENC + ADC10SC;         // Sampling and conversion start
			__bis_SR_register(CPUOFF + GIE);
			// LPM0, ADC10_ISR will force exit
			frontSensor = IsCenterHighLow(0x322);
		}

		TA0CCTL1 &= ~OUTMOD_7;        //clear
		TA0CCTL0 &= ~OUTMOD_7;
		TA1CCTL1 &= ~OUTMOD_7;
		TA1CCTL0 &= ~OUTMOD_7;

		while (rightSensor == 0 && leftSensor == 0) {

			senseRight();

			ADC10CTL0 |= ENC + ADC10SC;         // Sampling and conversion start
			__bis_SR_register(CPUOFF + GIE);
			// LPM0, ADC10_ISR will force exit

			rightSensor = IsRightHighLow(0x2FF);

			senseLeft();

			ADC10CTL0 |= ENC + ADC10SC;         // Sampling and conversion start
			__bis_SR_register(CPUOFF + GIE);
			// LPM0, ADC10_ISR will force exit

			leftSensor = IsLeftHighLow(0x2FF);
		}

		if (rightSensor > 0) {
			motion(RIGHT);
			__delay_cycles(500000);
		}

		else {
			motion(LEFT);
			__delay_cycles(500000);
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
