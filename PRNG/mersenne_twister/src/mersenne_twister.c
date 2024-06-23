#ifndef MT_TWIST_HEADER
#define MT_TWIST_HEADER
#include "mersenne_twister.h"
#endif

//Static variables for machine state instead of struct obj. 
static uint32_t mt_arr[N];
static uint32_t mt_idx= UINT32_MAX;

void mt_init(uint32_t s){
    mt_arr[0]= s;
    for(mt_idx=1;mt_idx<N;mt_idx++)
        mt_arr[mt_idx]= F * (mt_arr[mt_idx-1] ^ (mt_arr[mt_idx-1] >> 30)) + mt_idx;
}

uint32_t mt_random(){
    if(mt_idx >= N)
        mt_twist();     //re-calc all blocks in mt_arr if state index is > 624
    mt_idx++;           //selected next block in mt_arr for tempering
    return mt_temper(); //shift value back and forth for randomness
}

void mt_twist(){
    /* Twist algorithm has three states
        1. Un-initialized, mt_idx= UINT32_MAX. Init() function must be called with a seed value. 
        2. Iterating, 0 <= k < N. mt_twist() does not get called.
        3. Exceeded all blocks of values. re-calculate all blocks of values with twist algorithm
     */
    if(mt_idx == UINT32_MAX)
        mt_init(0x2ED05EEDUL);

    uint32_t temp= 0;
    for(int i=0;i<N;i++){
        temp = (mt_arr[i]&UPPER_MASK)|(mt_arr[i+1]&LOWER_MASK);
        mt_arr[i] = mt_arr[(i+M)%624] ^ (temp >> 1) ^ (temp & 0x1UL ? MATRIX_A_VECTOR : 0UL);
    }

    mt_idx= 0;
}

uint32_t mt_temper(){
    uint32_t y = mt_arr[mt_idx];
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);
    return y;
}