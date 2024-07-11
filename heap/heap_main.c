#include <stdio.h>
#include <assert.h>
#ifndef HEAP_HEADER
#define HEAP_HEADER
#include "heap.h"
#endif

void a_print(int* a, int l){
    printf("[ ");
    for(int i=0;i<l;i++)
        printf("%d ", a[i]);
    printf("]\n");
}

int main(void){

    heap* test_heap= create_heap();
    /* intial heap state */
    assert(heap_get_count(test_heap) == 0);
    assert(heap_peek(test_heap) == 0);
    assert(heap_is_empty(test_heap) == 1);
    /* adding elements preserves the heap property */
    for(int i= 0;i <16;i++)
        heap_push_element(test_heap, i+1);
    a_print(test_heap->keys, test_heap->count);
    assert(heap_peek(test_heap) == 16);
    for(int i= 32;i <64;i++)
        heap_push_element(test_heap, i+1);
    a_print(test_heap->keys, test_heap->count);
    assert(heap_peek(test_heap) == 64);
    /* removing heap elements preserves the heap property */
    for(int i= 63; i>31;i--)
        assert(heap_pop_element(test_heap) == i+1);
    for(int i= 15;i>=0;i--)
        assert(heap_pop_element(test_heap) == i+1);
    assert(heap_get_count(test_heap) == 0);
    assert(heap_peek(test_heap) == 0);
    assert(heap_is_empty(test_heap) == 1);

    heap_free(test_heap);
    printf("OK");
    return 0;
}