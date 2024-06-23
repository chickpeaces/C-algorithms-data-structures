#include <stdio.h>
#ifndef MT_TWIST_HEADER
#define MT_TWIST_HEADER
#include "mersenne_twister.h"
#endif

#define TEST_ELEMENT_COUNT 1000000

int main(void){
    
    mt_init(0xABABABABUL);
    for(int i=0;i<TEST_ELEMENT_COUNT;i++){
        printf("%lu ", mt_random());
        if( i % 8 == 0 )
            printf("\n");
    }
    printf("OK");
    return 0;
}