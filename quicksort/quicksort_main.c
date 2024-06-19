#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

static uint32_t seed;
#define TEST_ELEMENT_COUNT 32506
#define TEST_RANDOM_COUNT 1000

void quicksort(uint32_t arr[], int32_t st, int32_t en);
int32_t partition(uint32_t arr[], int32_t st, int32_t en);
void swap(uint32_t arr[], int32_t i, int32_t j);

uint32_t roll(){//blum-blum-shub PRNG
    seed= (seed * seed) % (17359l * 21487l);
    return seed;
}

int main(void){

    uint32_t *array = (uint32_t*) calloc(TEST_ELEMENT_COUNT, 4);
    for(int i=0;i<TEST_ELEMENT_COUNT;i++)
        array[i]= TEST_ELEMENT_COUNT-i;
    quicksort(array, 0, TEST_ELEMENT_COUNT-1);
    for(int i=0; i<TEST_ELEMENT_COUNT;i++)
        assert(array[i] == i+1);

    seed=104651;
    uint32_t *ran_arr = (uint32_t*) calloc(TEST_ELEMENT_COUNT, 4);
    for(int i=0;i<TEST_RANDOM_COUNT;i++)
        ran_arr[i]= roll();
    quicksort(ran_arr, 0, TEST_RANDOM_COUNT-1);
    for(int i=0;i<TEST_RANDOM_COUNT-1;i++)
        assert(ran_arr[i] <= ran_arr[i+1]);

    printf("OK\n");
    return 0;
}