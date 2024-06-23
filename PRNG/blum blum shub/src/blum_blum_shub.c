#ifndef BBS_PRNG_HEADER
#define BBS_PRNG_HEADER
#include "blum_blum_shub.h"
#endif

PRNG* prng_create(){
    PRNG* prng= (PRNG*) malloc(sizeof(PRNG));
    prng->seed= STARTING_SEED;
    prng->roll_count=  0;
    return prng;
}

uint64_t prng_roll(PRNG* prng){
    prng->seed=  (prng->seed*prng->seed) % (P1*P2);
    prng->roll_count++;
    return prng->seed;
}

void prng_seed(PRNG* prng, uint64_t s){
    prng->seed= s;
    prng->roll_count= 0;
}

uint64_t prng_get_roll_count(PRNG* prng){
    return prng->roll_count;
}