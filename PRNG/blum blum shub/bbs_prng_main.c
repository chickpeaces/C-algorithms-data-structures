#include <stdio.h>
#ifndef BBS_PRNG_HEADER
#define BBS_PRNG_HEADER
#include "blum_blum_shub.h"
#endif

#define TEST_ELEMENT_COUNT 100000

int main(void){
    PRNG* bbs_prng= prng_create();
    for(int i=0;i<TEST_ELEMENT_COUNT;i++)
        printf("%llu\n", prng_roll(bbs_prng));
    free(bbs_prng);
    return 0;
}