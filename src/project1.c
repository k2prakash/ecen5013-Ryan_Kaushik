#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <stdlib.h>
#include "../include/memory.h"
#include "../include/data.h"
#include "../include/project1.h"

void project1()
{
	printf("Hello, World!");
}

/*
extern int8_t my_memmove(uint8_t * src, uint8_t * dst, uint32_t length);
extern int8_t my_memzero(uint8_t * src, uint32_t length);
extern int8_t my_reverse(uint8_t * src, uint32_t length);
extern uint32_t srclen (uint8_t * src);

void project1() {

int8_t rc,i = 0;
uint8_t  length  = 7;
uint8_t  * x = '\0';
uint8_t  * y = '\0';
x = (uint8_t *) malloc(sizeof(uint8_t));
y = (uint8_t *) malloc(sizeof(uint8_t));

x= y - length + 2;
//x = '\0';


printf("address pointed by src %p\n", x);
printf("address pointed by dst %p\n", y);


if (x != '\0') {
    for (i=0; i<=length-1;i++) {
        *x++ = i;
    }
    x-=length;
}

//int length_n = -2147483648;
rc = my_memmove (x, y, length);
if (rc == 0) {
    for (i=0; i<=length-1;i++) {
   	 printf("Address %p, value %d\n", y, *y);
   	 y++;
    }
    y-=length;
}

printf("Reversing the values in ptr y\n");

rc =  my_reverse(y, length);
if (rc == 0) {
    for (i=0; i<=length-1;i++) {
   	 printf("Address %p, value %d\n", y, *y);
   	 y++;
    }
    y-=length;
}



printf("Zeroizing the values\n");

rc = my_memzero(y, length);

if(rc == 0) {
    for (i=0; i<=length-1;i++) {
   	 printf("Address %p, value %d\n", y, *y);
   	 y++;
    }
    y-=length;
}

rc = my_memzero(x, length);
if(rc == 0) {
    for (i=0; i<=length-1;i++) {
   	 printf("Address %p, value %d\n", x, *x);
   	 x++;
    }
    x-=length;
}


//free(x);
//free(y);

return;

}*/
