#ifndef _MEMORY_H
#define _MEMORY_H

/*
This fucntion will move byte(s) of data starting from the source address location to the desitination address location.
*/
int8_t my_memmove(uint8_t * src, uint8_t * dst, uint32_t length);

/*
This function will zeroize all the the data for the given length of addresses starting from the source address location.
*/

int8_t my_memzero(uint8_t * src, uint32_t length);

/*
This fucntion will takes a pointer to a memory location and a length in bytes and reverse the order of all of the bytes.
*/

int8_t my_reverse(uint8_t * src, uint32_t length);
#endif
