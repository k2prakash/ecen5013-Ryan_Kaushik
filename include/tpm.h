/*
 * tpm.h
 *
 *  Created on: Oct 7, 2016
 *      Author: kprakash
 */

#ifndef INCLUDES_TPM_H_
#define INCLUDES_TPM_H_

#define TPM_Cn_MODE  (TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK)
#define TPM_MODULE  3750
#define DUTY_MIN	220
#define DUTY_MAX	350

#define PWM_BLACK 	0
#define PWM_GREEN 	1
#define PWM_BLUE  	2
#define PWM_AQUA  	3
#define PWM_RED   	4
#define PWM_YELLOW  5
#define PWM_VIOLET  6
#define PWM_WHITE   7

void pwm_init();
void set_brightness(int intensity, int color);
void set_pins_for_pwm();


#endif /* INCLUDES_TPM_H_ */
