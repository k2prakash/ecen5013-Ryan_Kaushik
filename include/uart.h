/*
 * uart.h
 *
 *  Created on: Oct 7, 2016
 *      Author: kprakash
 */
#include "stdint.h"

#ifndef INCLUDES_UART_H_
#define INCLUDES_UART_H_


#define CLOCKDIV 16
#define CORECLK 24000000

void uart0_init(uint32_t baudrate);
void uart0_putch(char s);
char uart0_getch();
int getstr(char *str);




#endif /* INCLUDES_UART_H_ */
