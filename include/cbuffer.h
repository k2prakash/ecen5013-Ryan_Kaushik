#ifndef _CBUFFER_H
#define _CBUFFER_H

typedef struct cbuffer
{
    uint8_t* start;
    uint8_t* end;
    uint8_t* head;
    uint8_t* tail;
	uint8_t size;
    uint8_t count;
} cbuffer;


/*initializes a circular buffer of size sz on the heap*/
void cbuffer_init(cbuffer* buff, uint8_t);


/*free a circular buffer from memory*/
void cbuffer_free(cbuffer* buff);


/*adds one element to the buffer*/
void cbuffer_add(cbuffer* buff, uint8_t elem);


/*removes one element from the buffer*/
void cbuffer_remove(cbuffer* buff, uint8_t elem);

#endif