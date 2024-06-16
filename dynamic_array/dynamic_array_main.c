#include <stdio.h>
#include <assert.h>
#ifndef DA_HEADER
#define DA_HEADER
#include "dynamic_array.h"
#endif

#define TEST_ELEMENT_COUNT 1000000

void da_print(da *da){
    printf("[ ");
    int size= da->siz;
    for(int i=0;i<size-1;i++)
        printf("%d, ",da->arr[i]);
    printf("%d ] (s%d, c%d)\n", da->arr[size-1], da->siz, da->cap);
}

int main(void){

    da* test_da= da_create();
    /* add elements and resize array */
    for(int i=0; i< TEST_ELEMENT_COUNT; i++)
        da_add_element( test_da, i+1);
    uint32_t size= da_get_size(test_da);
    assert( size == TEST_ELEMENT_COUNT);
    /* get all elements */
    uint32_t e;
    for(int i= TEST_ELEMENT_COUNT; i>0; i--){
        e= da_get_element(test_da, i-1);
        assert( e == i);
    }
    /* set element in-bounds */
    uint32_t success= da_set_element( test_da, 123321, 0);
    e= da_get_element(test_da, 0);
    assert( success == 0 );
    assert( e == 123321);
    /* set element out-of-bounds */
    uint32_t ocap= da_get_capacity(test_da);
    success= da_set_element( test_da, 1234321, ocap+1);
    assert( success == -1 );

    da_free(test_da);
    printf("OK");
    return 0;
}