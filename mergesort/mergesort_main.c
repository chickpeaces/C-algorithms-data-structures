#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t seed;
#define TEST_ELEMENT_COUNT 1000000
#define TEST_RANDOM_COUNT 1000

void mergesort(uint32_t arr[], int32_t len);
void merge(uint32_t arr[], uint32_t left[], uint32_t right[], uint32_t llen, uint32_t rlen);

uint32_t roll(){//blum-blum-shub PRNG
    seed= (seed * seed) % (17359l * 21487l);
    return seed;
}

int main(void){

    uint32_t *array = (uint32_t*) calloc(TEST_ELEMENT_COUNT, 4);
    for(int i=0;i<TEST_ELEMENT_COUNT;i++)
        array[i]= TEST_ELEMENT_COUNT-i;
    mergesort(array, TEST_ELEMENT_COUNT);
    for(int i=0; i<TEST_ELEMENT_COUNT;i++)
        assert(array[i] == i+1);

    seed=104651;
    uint32_t *ran_arr = (uint32_t*) calloc(TEST_ELEMENT_COUNT, 4);
    for(int i=0;i<TEST_RANDOM_COUNT;i++)
        ran_arr[i]= roll();
    mergesort(ran_arr, TEST_RANDOM_COUNT);
    for(int i=0;i<TEST_RANDOM_COUNT-1;i++)
        assert(ran_arr[i] <= ran_arr[i+1]);

    printf("OK\n");
    return 0;
}