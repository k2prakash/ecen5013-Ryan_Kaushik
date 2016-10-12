#ifndef _CBUFFERTEST_H
#define _CBUFFERTEST_H

void run_test_cbuffer();

void print_buffer_struct(cbuffer* buff);

void print_buffer_content(cbuffer* buff);

void test_cbuffer_init(cbuffer* buff, uint8_t size);

void test_cbuffer_free(cbuffer* buff);

void test_cbuffer_add(cbuffer* buff, uint8_t amt);

void test_cbuffer_remove(cbuffer* buff, uint8_t amt);

#endif
