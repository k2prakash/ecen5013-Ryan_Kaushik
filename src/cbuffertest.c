#include <stdio.h>
#include <stdint.h>
#include "../include/cbuffer.h"
#include "../include/cbuffertest.h"

static uint8_t test_count = 0;
static uint8_t init_test_count = 0;
static uint8_t add_test_count = 0;
static uint8_t remove_test_count = 0;
static uint8_t free_test_count = 0;

int main()
{
    run_test_cbuffer();
}


void run_test_cbuffer()
{
    cbuffer buff1, buff2, buff3, buff4, buff5;
    test_cbuffer_init(&buff1,(uint8_t)0);
    test_cbuffer_init(&buff2,(uint8_t)1);
    test_cbuffer_init(&buff3,(uint8_t)16);
    test_cbuffer_init(&buff4,(uint8_t)255);
    test_cbuffer_init(&buff5,(uint8_t)256);
    test_cbuffer_add(&buff3, 8);
    test_cbuffer_remove(&buff3, 12);
    test_cbuffer_add(&buff3,0);
    test_cbuffer_remove(&buff3,4);
    test_cbuffer_add(&buff3,3);
    test_cbuffer_remove(&buff3,0);
    test_cbuffer_add(&buff3,14);
    test_cbuffer_remove(&buff3,15);
    test_cbuffer_free(&buff1);
    test_cbuffer_free(&buff2);
    test_cbuffer_free(&buff3);
	test_cbuffer_free(&buff4);
	test_cbuffer_free(&buff5);
	uint8_t pass_sum = init_test_count + add_test_count + remove_test_count + free_test_count;
	printf("CB UNIT TEST SUITE: (%d/%d) PASS\n",pass_sum,test_count);
}


void test_cbuffer_init(cbuffer* buff, uint8_t size)
{
	test_count++;
    cbuffer_init(buff, size);
    if(!buff->start || !buff->end || !buff->head || !buff->tail)
    {
    	printf("Error : buffer pointer null\n");
    	printf("CB UNIT TEST CBUFFER INITIALIZE (%d) : FAIL (%d/4)\n", test_count, init_test_count);
    }
    else if(buff->head!=buff->tail || buff->head!=buff->start || buff->start!=buff->tail)
    {
    	printf("Error : buffer pointer initialization\n");
    	printf("CB UNIT TEST CBUFFER INITIALIZE (%d) : FAIL (%d/4)\n", test_count, init_test_count);
    }
    else if(buff->start > buff-> end)
    {
    	printf("Error : buffer limits\n");
    	printf("CB UNIT TEST CBUFFER INITIALIZE (%d) : FAIL (%d/4)\n", test_count, init_test_count);
    }
    else if(buff->count != 0)
    {
    	printf("Error : buffer fill status\n");
    	printf("CB UNIT TEST CBUFFER INITIALIZE (%d) : FAIL (%d/4)\n", test_count, init_test_count);
    }
    else if(buff->size < 1)
    {
    	printf("Error : buffer size\n%d",buff->size);
    	printf("CB UNIT TEST CBUFFER INITIALIZE (%d) : FAIL (%d/4)\n", test_count, init_test_count);
    }
    else
    {
    	init_test_count++;
    	printf("CB UNIT TEST CBUFFER INITIALIZE (%d) : PASS (%d/4)\n", test_count, init_test_count);
    }
    return;
}


void test_cbuffer_free(cbuffer* buff)
{
    cbuffer_free(buff);
    free_test_count++;
    test_count++;
    printf("CB UNIT TEST CBUFFER FREE (%d) : PASS (%d/5)\n", test_count, free_test_count);
}


void test_cbuffer_add(cbuffer* buff, uint8_t amt)
{
	test_count++;
	printf("add (%d) : ",amt); 
	for(uint8_t i = 97 ; i <= 97 + amt - 1; i++)
	{
		cbuffer_add(buff, &i);
		printf("%c, ", i);
    }
    printf("\n");
    print_buffer_struct(buff);
    print_buffer_content(buff);
    if(buff->count > buff->size || buff->count < 0)
    {
    	printf("Error : access error\n");
    	printf("CB UNIT TEST CBUFFER ADD (%d) : FAIL (%d/4)\n", test_count, init_test_count);
    }
    add_test_count++;
    printf("CB UNIT TEST CBUFFER ADD (%d) : PASS (%d/4)\n", test_count, add_test_count);
    return;
}


void test_cbuffer_remove(cbuffer* buff, uint8_t amt)
{
	test_count++;
	uint8_t e = 0;
	printf("remove (%d) : ",amt); 
	for(uint8_t i = 1; i <= amt; i++)
	{
		e = 0;
        cbuffer_remove(buff, &e);
     	printf("%c, ", e);
    }
    printf("\n");
    print_buffer_struct(buff);
    print_buffer_content(buff);
    if(buff->count > buff->size || buff->count < 0)
    {
    	printf("Error : access error\n");
    	printf("CB UNIT TEST CBUFFER ADD (%d) : FAIL (%d/4)\n", test_count, init_test_count);
    }
    remove_test_count++;
    printf("CB UNIT TEST CBUFFER REMOVE (%d) : PASS (%d/4)\n", test_count, remove_test_count);
    return;
}


void print_buffer_struct(cbuffer* buff)
{   
    printf("start:%p ", buff->start);
    printf("end:%p ", buff->end);
    printf("head:%p ", buff->head);
    printf("tail:%p ", buff->tail);
    printf("size:%d ", buff->size);
    printf("count:%d ", buff->count);
}


void print_buffer_content(cbuffer* buff)
{   
    printf("buff:");
    for(int i = 0; buff->start + i <= buff->end; i++)
        printf("%c",*(buff->start + i));
    printf("\n");
}
