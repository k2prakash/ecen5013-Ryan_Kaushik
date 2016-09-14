#include <stdio.h>
#include <stdint.h>
#include "memory.h"

/*
This function will move byte(s) of data starting from the source address location to the desitination address location.
*/
int8_t my_memmove(uint8_t * src, uint8_t * dst, uint32_t length) {
    uint32_t count = 0;

    if (dst == NULL || src == NULL) { // Check to see if the pointer points to a NULL Location.
	    fprintf(stderr, "Null pointer encountered. Exit code: %d\n", NULL_PTR_ERROR); // Display Null pointer error message
            return NULL_PTR_ERROR;
    }

    // commented becasue the uimt32_t type takes care of negative numbers
    /*if (length <=0 ) { // Check to see if the length is less than or equal to 0
        fprintf(stderr, "Invalid length encountered. Exit code: %d\n", INVAL_LEN_ERROR);
        return INVAL_LEN_ERROR;
    }*/

    if (  ((dst > src) && ((dst - (src + length -1)) <= 0)) || // Check to see if dst is at least one greater than src + length -1.
		((src > dst) && (( src - (dst + length -1)) <= 0 )) || // Check to see if src is at least one greater than dst + length -1.
			(dst == src)) { // Check to see if the addresses pointed by src and dev are the same.
    	fprintf(stderr, "Overlap of addresses encountered. Exit code: %d\n", ADDR_OVERLAP_ERROR); //Display address overlap error message. 
        return ADDR_OVERLAP_ERROR;
    }

    while (length > 0) { // Copy the contents of address pointed by src pointer into the address pointed by dst pointer. 
	*dst++ = *src++; // Increment the addresses of the pointers till the length is greater than 0.
        length--;
    }
    return SUCCESS;
}

/*
This function will zeroize all the the data for the given length of addresses starting from the source address location.
*/
int8_t my_memzero(uint8_t * src, uint32_t length) {

    if (src == NULL) { // Check to see if the src pointer points to NULL
        fprintf(stderr, "Null pointer encountered. Exit code: %d\n", NULL_PTR_ERROR);// Display Null pointer error message.
        return NULL_PTR_ERROR;
    }

    // commented becasue the uimt32_t type takes care of negative numbers
    /*
    if (length <=0 ) { //Check to see if the length is less than or equal to 0
        fprintf(stderr, "Invalid length encountered. Exit code: %d\n", INVAL_LEN_ERROR); //Display address overlap error message.
        return INVAL_LEN_ERROR;
    }
    */

    while (length > 0) { // Derefernce the value pointed by the pointer src and set it to 0.
        *src++ = 0; // increment the addresses till length is greater than 0.
        length--;
    }
    return SUCCESS;
}

/*
This fucntion will takes a pointer to a memory location and a length in bytes and reverse the order of all of the bytes.
*/

int8_t my_reverse(uint8_t * src, uint32_t length) {

    uint32_t c = 0;
    uint32_t l = length;
    uint8_t tmp = 0;
    if (src == NULL) { // Check to see if the src pointer points to NULL
        fprintf(stderr, "Null pointer encountered. Exit code: %d\n", NULL_PTR_ERROR);// Display Null pointer error message.
        return NULL_PTR_ERROR;
    }

    // commented becasue the uimt32_t type takes care of negative numbers
    /*
    if (length <=0 ) { //Check to see if the length is less than or equal to 0
        fprintf(stderr, "Invalid length encountered. Exit code: %d\n", INVAL_LEN_ERROR); //Display address overlap error message.
        return INVAL_LEN_ERROR;
    }
    */

    while (c != l/2) {
        tmp = *(src + c);
        *( src + c ) = *( src + length - 1);
        *(src + length - 1) = tmp;
        c++;
        length--;
    }
    return SUCCESS;
}

/*
* This function will determine the length of the passed string
*/

/*uint32_t srclen(uint8_t * src) {
    uint32_t count = 0;
    while (*src != '\0') {
        count++;
        src++;
    }
return count;
}
*/
