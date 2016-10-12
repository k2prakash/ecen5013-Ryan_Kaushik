/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "MKL25Z4.h"
#include <stdio.h>
#include "stdint.h"
#include "gpio.h"
#include "uart.h"
#include "ftoa.h"
#include "data.h"
#include "tpm.h"
#include "main.h"
#include "log.h"

static int i = 0;
static int count = 0;
static int color = 0;
static char ch = CHAR_A;
char test_message[] = "Testing123, Serial Print Test, no params";
char integer_message[] = "This is an integer number:";
char float_message[] = "This is an floating point number:";
char str[100];


int main(void)
{
	int counter = 0;
	uint32_t st_len;
	int duty = 0;
	uart0_init(BAUD_RATE);
	pwm_init();
	gpio_init();

    int8_t i1 = 200;
    int16_t i2 = 4096;
    int32_t i3 = 123456;
	float f1 = 1543.321;
	//char buffer[BUFFER_SIZE];


	/*ftoa(f1, buffer);
	log0(buffer, 16);
	log0(NEWLINE, LOG_NEWLINE_LEN);
	*/

	/*
	log1(buffer, BUFFER_SIZE, &i, INTEGER_TYPE);
	log0(NEWLINE, LOG_NEWLINE_LEN);
	log1(buffer, BUFFER_SIZE, &f2, FLOAT_TYPE);
	log0(NEWLINE, LOG_NEWLINE_LEN);
    */

	log0(test_message, MESSAGE_BUFFER_SIZE);
	log0(NEWLINE, LOG_NEWLINE_LEN);

	log1(integer_message, MESSAGE_BUFFER_SIZE, &i1, sizeof(int8_t), INTEGER_TYPE);

	log1(integer_message, MESSAGE_BUFFER_SIZE, &i2, sizeof(int16_t), INTEGER_TYPE);

	log1(integer_message, MESSAGE_BUFFER_SIZE, &i3, sizeof(int32_t), INTEGER_TYPE);

	log1(float_message, MESSAGE_BUFFER_SIZE, &f1, sizeof(uint32_t), FLOAT_TYPE);


	while(1)
		{
			ch = uart0_getch();
			uart0_putch(ch);
			switch (ch) {
			case CHAR_A:
					  set_pins_for_color();
					  i+=1;
					  color=i%8;
				      display_color(color);
				      log0(NEWLINE, LOG_NEWLINE_LEN);
				      break;
			case CHAR_D:
					  set_pins_for_color();
					  i-=1;
					  i = (i == 0) ? 8 : i;
					  color=i%8;
				      display_color(color);
				      log0(NEWLINE, LOG_NEWLINE_LEN);
					  break;
			case CHAR_W:
				      set_pins_for_pwm();
					  if(count<10)
					  {
							set_brightness(++count, color);
					  }
					  log0(NEWLINE, LOG_NEWLINE_LEN);
					  break;
			case CHAR_S:
				      set_pins_for_pwm();
					  if(count>0)
					  {
							set_brightness(--count, color);
		    		  }
					  log0(NEWLINE, LOG_NEWLINE_LEN);
					  break;
			case CHAR_G:
				      log0(NEWLINE, LOG_NEWLINE_LEN);
				      st_len = getstr(str);
				      log0(str, st_len);
				      log0(NEWLINE, LOG_NEWLINE_LEN);
					  break;
         	default:
					  break;
			}

		}

}

