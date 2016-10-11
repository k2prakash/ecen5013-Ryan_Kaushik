#include <stdio.h>
#include <stdint.h>
#include "cbuffer.h"
#include "cbuffertest.h"

int main()
{
    run_test_cbuffer();
}

void run_test_cbuffer()
{
    uint8_t result;
    uint8_t size = 0x1F;
    cbuffer buff;
    cbuffer_init(buff, size)
    for(int i = 0; size-- > 0; i++)
        cbuffer_add(buff, (uint8_t)i);
    result = test_cbuffer_init();
}

void print_buffer(cbuffer* buff)
{   
    printf("buff :");
    for(int i = 0; buff->start + i <= buff->end; i++)
        printf("%c",*(buff->start + i));
    printf("\n");
}

uint8_t test_cbuffer_init(cbuffer* buff)
{
    printf("start:%p\n", buff->head);
    printf("end  :%p\n", buff->end);
    printf("head :%p\n", buff->head);
    printf("tail :%p\n", buff->tail);
    printf("size :%d\n", buff->size);
    printf("count:%d\n", buff->count);
    print_buffer(buff);
    return 0;
}

uint8_t test_cbuffer_free()
{
    
}

uint8_t test_cbuffer_add()
{
    
}

uint8_t test_cbuffer_remove()
{
    
}