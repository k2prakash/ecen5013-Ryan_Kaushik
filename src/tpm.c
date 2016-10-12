/*
 * tpm.c
 *
 *  Created on: Oct 7, 2016
 *      Author: kprakash
 */
#include "MKL25Z4.h"
#include "tpm.h"
#include "gpio.h"

/*
 * This function will initialize the registers required for PWM operation.
 */
void pwm_init()
{
	SIM_SCGC5 |= (SIM_SCGC5_PORTB_MASK | // enable clock to PORT B. Port B's pin 18 is red and pin 19 is green.
				  SIM_SCGC5_PORTD_MASK ); // enable clock to PORT D. Port D's pin 19 is blue.

	SIM_SCGC6 |= (SIM_SCGC6_TPM2_MASK |   // enable clocking to TPM2. TMP2-channel 0 is for red pin and TPM2-channel 1 is for green pin
			       SIM_SCGC6_TPM0_MASK); //enable clocking to TPM0. TPM0-channel 1 id for the blue pin

	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1); // set the clock as MCGPLL

	PORTB_PCR18 = PORT_PCR_MUX(3);	//set PORT B, PIN 18 as the TPM2_CH0 channel
	PORTB_PCR19 = PORT_PCR_MUX(3);  //set PORT B, PIN 19 as the TPM2_CH1 channel
	PORTD_PCR1  = PORT_PCR_MUX(3);  //set PORT D, PIN 1 as the TPM0_CH0 channel

	TPM2_MOD  = TPM_MODULE;	// set the Modulo value as 3750
	TPM0_MOD  = TPM_MODULE; // set the Modulo value as 3750


	//set the TPM2 Channel0 status and control register to operate as Edge aligned PWM
	TPM2_C0SC = TPM_Cn_MODE;
	TPM2_C0V  = 0;	//set the initial Duty value to be off

	//set the TPM2 Channel1 status and control register to operate as Edge aligned PWM
	TPM2_C1SC = TPM_Cn_MODE;
	TPM2_C1V  = 0;	//set the initial Duty value to be off

	//set the TPM0 Channel1 status and control register to operate as Edge aligned PWM
	TPM0_C1SC = TPM_Cn_MODE;	//Edge aligned PWM
	TPM0_C1V  = 0;	//set the initial Duty value to be off


	TPM2_SC  |= (TPM_SC_CMOD(1)| // set the LPTPM counter to increment on every LPTPM counter clock
			 TPM_SC_PS(0)); // pre scale factor selection is set to divide by 1
	TPM0_SC  |= (TPM_SC_CMOD(1)| // set the LPTPM counter to increment on every LPTPM counter clock
				 TPM_SC_PS(0));  // pre scale factor selection is set to divide by 1

}

/*
 * This function will reset the gpio high out pins and
 * configure the pins as TPM pins
 */
void set_pins_for_pwm()
{
    // Unset the PORT B pins 18 and 19, and PORT D, pins 1 as GPIO high output pins
	PORTB_PCR18 &= ~PORT_PCR_MUX(1);
	PORTB_PCR19 &= ~PORT_PCR_MUX(1);
	PORTD_PCR1 &= ~PORT_PCR_MUX(1);

	// Set the PORT B pins 18 and 19, and PORT D, pins 1 as TPM pins
	PORTB_PCR18 = PORT_PCR_MUX(3);
	PORTB_PCR19 = PORT_PCR_MUX(3);
	PORTD_PCR1 = PORT_PCR_MUX(4);
}


/*
 * This function will set the duty value for the corresponding TPM channels
 */
void set_brightness(int intensity, int color)
{
	int duty = 0;
	duty = intensity*((DUTY_MAX-DUTY_MIN)/10) + DUTY_MIN;

    switch(color) {
		case PWM_BLACK:
				TPM2_C0V = TPM_CnV_VAL_MASK & 0;
				TPM2_C1V = TPM_CnV_VAL_MASK & 0;
				TPM0_C1V = TPM_CnV_VAL_MASK & 0;
				break;
		case PWM_GREEN:
				TPM2_C0V = TPM_CnV_VAL_MASK & 0;
				TPM2_C1V = TPM_CnV_VAL_MASK & duty;
				TPM0_C1V = TPM_CnV_VAL_MASK & 0;
				break;
		case PWM_BLUE:
				TPM2_C0V = TPM_CnV_VAL_MASK & 0;
				TPM2_C1V = TPM_CnV_VAL_MASK & 0;
				TPM0_C1V = TPM_CnV_VAL_MASK & duty;
				break;
		case PWM_AQUA:
				TPM2_C0V = TPM_CnV_VAL_MASK & 0;
				TPM2_C1V = TPM_CnV_VAL_MASK & duty;
				TPM0_C1V = TPM_CnV_VAL_MASK & duty;
				break;
		case PWM_RED:
				TPM2_C0V = TPM_CnV_VAL_MASK & duty;
				TPM2_C1V = TPM_CnV_VAL_MASK & 0;
				TPM0_C1V = TPM_CnV_VAL_MASK & 0;
				break;
		case PWM_YELLOW:
				TPM2_C0V = TPM_CnV_VAL_MASK & duty;
				TPM2_C1V = TPM_CnV_VAL_MASK & duty;
				TPM0_C1V = TPM_CnV_VAL_MASK & 0;
				break;
		case PWM_VIOLET:
				TPM2_C0V = TPM_CnV_VAL_MASK & duty;
				TPM2_C1V = TPM_CnV_VAL_MASK & 0;
				TPM0_C1V = TPM_CnV_VAL_MASK & duty;
				break;
		case PWM_WHITE:
				TPM2_C0V = TPM_CnV_VAL_MASK & duty;
				TPM2_C1V = TPM_CnV_VAL_MASK & duty;
				TPM0_C1V = TPM_CnV_VAL_MASK & duty;
				break;
    }

}






