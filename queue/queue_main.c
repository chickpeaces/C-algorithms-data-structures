#include <stdio.h>
#include <assert.h>
#ifndef QUEUE_HEADER
#define QUEUE_HEADER
#include "queue.h"
#endif

#define TEST_ELEMENT_COUNT 1000000

int main(void){

    queue* test_q= queue_create();
    uint32_t e, i;
    e= queue_dequeue(test_q);
    assert(e == UINT32_MAX);//return -1 in an empty queue
    /* test enqueue'ing elements, correctly resize*/
    for(i=0; i<32;i++)
        queue_enqueue(test_q, i+1);
    e= queue_get_size(test_q);
    assert( e == 32);
    e= queue_get_capacity(test_q);
    assert( e == 64);
    e= queue_get_head(test_q);
    assert( e == 32);
    e= queue_get_tail(test_q);
    assert( e == 0);
    /* test dequeue'ing elements, set up for queue compression*/
    for(i=0;i<24;i++){
        e= queue_dequeue(test_q);
        assert( e == i+1);
    }
    e= queue_get_size(test_q);
    assert( e == 8);
    e= queue_get_capacity(test_q);
    assert( e == 64);
    e= queue_get_head(test_q);
    assert( e == 32);
    e= queue_get_tail(test_q);
    assert( e == 24);
    /* test for queue compression when attempting to resize */
    for(i=32; i< 64;i++)
        queue_enqueue(test_q, i+1);
    e= queue_get_size(test_q);
    assert( e == 40);
    e= queue_get_capacity(test_q);
    assert( e == 64);
    e= queue_get_head(test_q);
    assert( e == 40);
    e= queue_get_tail(test_q);
    assert( e == 0);
    /* test empty queue */
    while(queue_get_size(test_q) > 0)
        queue_dequeue(test_q);
    e= queue_get_size(test_q);
    assert( e == 0);
    e= queue_get_capacity(test_q);
    assert( e == 64);
    e= queue_get_head(test_q);
    assert( e == 0);
    e= queue_get_tail(test_q);
    assert( e == 0);
    /* test 1,000,000 elements enqueue'd correctly*/
    for(i=0; i<TEST_ELEMENT_COUNT;i++)
        queue_enqueue(test_q, i+1);
    e= queue_get_size(test_q);
    assert( e == TEST_ELEMENT_COUNT);
    e= queue_get_capacity(test_q);
    assert( e > TEST_ELEMENT_COUNT);
    e= queue_get_head(test_q);
    assert( e == TEST_ELEMENT_COUNT);
    e= queue_get_tail(test_q);
    assert( e == 0);
    /* test 1,000,000 elements dequeue'd in the correct order */
    for(i=0;i<TEST_ELEMENT_COUNT;i++){
        e= queue_dequeue(test_q);
        assert( e == i+1);
    }
    e= queue_get_size(test_q);
    assert( e == 0);
    e= queue_get_capacity(test_q);
    assert( e > TEST_ELEMENT_COUNT);
    e= queue_get_head(test_q);
    assert( e == 0);
    e= queue_get_tail(test_q);
    assert( e == 0);
    /* release memory with free */
    queue_free(test_q);
    printf("OK");
    return 0;
}