#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "cbuffer.h"

void cbuffer_init(cbuffer* buff, uint8_t size)
{
    if(size == 0)
        return;
    buff->start = malloc(size);
    buff->end = buff->start + size - 1;
    buff->head = buff->start;
    buff->tail = buff->start;
    buff->size = size;
    buff->count = 0;
    return;
}


void cbuffer_free(cbuffer* buff)
{
    for(  ; --buff->size > 0;  )
        free(buff->start++);
    free(buff);
}


void cbuffer_add(cbuffer* buff, uint8_t elem)
{
    if(buff->count == buff->size)
        return;
    if(buff->head == buff->end)/*wrap around*/
    {
        memcpy(buff->head, &elem, sizeof(uint8_t));
        buff->head = buff->start;
    }
    else
    {
        memcpy(buff->head++, &elem, sizeof(uint8_t));
    }
    buff->count++;
    return;
}


void cbuffer_remove(cbuffer* buff, uint8_t elem)
{
    if(buff->count == 0)
        return;
    if(buff->tail == buff-> end)/*wrap around*/
    {
        memcpy(&elem, buff->tail, sizeof(uint8_t));
        buff->tail = buff->start;        
    }
    else
    {
        memcpy(&elem, buff->tail, sizeof(uint8_t));
    }
    buff->count--;
    return;
}