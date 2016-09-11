#ifndef _DATA_H
#define _DATA_H

/*
This function will take an integer value and converts the value into an ascii string.
*/
int8_t * my_itoa(uint8_t * str, int32_t data, int32_t base);

/*
This function will take an ascii string and converts it into an integer value.
*/
int32_t my_atoi(uint8_t * str);

/*
This function takes a pointer to memory and prints the hex output of bytes given a pointer
    to a memory location and a length of bytes to print.
*/
void dump_memory(uint8_t * start, uint32_t length);

/*
This function converts data with big endian notation to a little endian notation. 
*/
int32_t big_to_little(int32_t data);

/*
This function converts data little endian notation to a big endian notation.
*/
int32_t little_to_big(int32_t data);
#endif
