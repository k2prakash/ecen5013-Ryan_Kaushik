#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <stdlib.h>
#include "../include/memory.h"
#include "../include/data.h"
#include "../include/project_1.h"

#ifdef FRDM
#define printf(...)
#endif

void project_1_report()
{
    uint8_t array[32];
    uint8_t * ptr1 = array; // Initialize the address to be the beginning of the array
    uint8_t * ptr2 = array +8; //Initialize the address to be the 9th element of the array
    uint8_t * ptr3 = array + 16; // Initialize the address to be the 17th element of the array

    printf("\nContents of pointer PTR1 before populating it with values 31-46\n\n");
    dump_memory(ptr1, 16);
    for (int8_t i=0,j=31; i<16; i++,j++) {
	*ptr1++ = j;
    }
    printf("\nContents of pointer PTR1 after populating it with values 31-46\n\n");
    ptr1-=16;
    dump_memory(ptr1, 16);

    printf("\nContents of pointer PTR3 before Zeroizing the values\n\n");
    dump_memory(ptr3, 16);
    

    printf("\nContents of pointer PTR3 after Zeroizing the values\n\n");
    my_memzero(ptr3, 16);
    dump_memory(ptr3, 16);

    printf("\nMoving 8 bytes of data from APTR1 to APTR3...\n\n");
    my_memmove(ptr1, ptr3, 8);
    printf("\nContents of pointer PTR3 after copying the values from PTR1 \n\n");
    dump_memory(ptr3, 15);

    printf("\nContents of pointer APTR1 before copying the values from APTR2 \n\n");
    dump_memory(ptr1, 16);
    printf("\nMoving 16 bytes of data from APTR2 to APTR1...\n\n");
    my_memmove(ptr2, ptr1, 16);
    printf("\nContents of pointer APTR1 after copying the values from APTR2 \n\n");
    dump_memory(ptr1, 16);

    printf("\nContents of pointer APTR1 before reversing the values\n\n");
    dump_memory(ptr1, 32);
    printf("\nContents of pointer APTR1 after reversing the values\n\n");
    my_reverse(ptr1, 32);
    dump_memory(ptr1, 32);

    printf("\nThe decoded mesasge is %s\n", array);
    return;
}

