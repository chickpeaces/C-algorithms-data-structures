#include <stdio.h>
#include <assert.h>
#ifndef STACK_HEADER
#define STACK_HEADER
#include "stack.h"
#endif

#define TEST_ELEMENT_COUNT 1000000

int main(void){
    uint32_t e,i;
    stack *test_stk= stack_create();
    e= stack_pop(test_stk);  //empty stack pop's -1
    assert( e == UINT32_MAX);//-1 value signals pop() exception
    /* test stack adds elements correctly */
    for(i=0;i<32;i++)
        stack_push(test_stk, i);
    e= stack_get_size(test_stk);
    assert( e == 32);
    e= stack_get_capacity(test_stk);
    assert( e == 64);
    /* test stack removes elements correctly */
    for(i=0;i<32;i++)
        stack_pop(test_stk);
    e= stack_get_size(test_stk);
    assert( e == 0);
    /* push 1,000,000 elements onto the stack correctly */
    for(i=0;i<TEST_ELEMENT_COUNT;i++)
        stack_push(test_stk, i+1);
    e= stack_get_size(test_stk);
    assert( e == TEST_ELEMENT_COUNT);
    e= stack_get_capacity(test_stk);
    assert( e > TEST_ELEMENT_COUNT);
    /* pop 1,000,000 elements off the stack in the correct order */
    for(i=TEST_ELEMENT_COUNT;i>0;i--){
        e= stack_pop(test_stk);
        assert( e == i);
    }
    e= stack_get_size(test_stk);
    assert( e == 0);

    stack_free(test_stk);
    printf("OK");
    return 0;
}