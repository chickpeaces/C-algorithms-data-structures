#include <stdio.h>
#include <assert.h>
#ifndef HEAP_HEADER
#define HEAP_HEADER
#include "heap.h"
#endif

#define TEST_ARRAY_LENGTH 32

void a_print(int* a, int l){
    printf("[ ");
    for(int i=0;i<l;i++)
        printf("%d ", a[i]);
    printf("]\n");
}

int main(void){

    heap* test_heap= create_heap();
    int *array= (int*) calloc(32, 4);
    /* intial heap state */
    assert(heap_get_count(test_heap) == 0);
    assert(heap_peek(test_heap) == 0);
    assert(heap_is_empty(test_heap) == 1);
    /* create unsorted array and heap */
    for(int i=16; i>0;i--){
        heap_push_element(test_heap, i);
        array[TEST_ARRAY_LENGTH-i]= i;
    }
    for(int i=32; i>16;i--){
        heap_push_element(test_heap, i);
        array[TEST_ARRAY_LENGTH-i]= i;
    }
    printf("\n");
    a_print(test_heap->keys, test_heap->count);
    a_print(array, TEST_ARRAY_LENGTH);
    /* sort array by removing elements from the heap */
    while(!heap_is_empty(test_heap))
        array[test_heap->count-1]= heap_pop_element(test_heap);
    a_print(array, TEST_ARRAY_LENGTH);
    for(int i= 0; i< TEST_ARRAY_LENGTH-1;i++)
        assert(array[i] <= array[i+1]);

    heap_free(test_heap);
    printf("OK");
    return 0;
}