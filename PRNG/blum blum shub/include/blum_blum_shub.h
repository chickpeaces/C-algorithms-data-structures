#include <stdint.h>
#include <stdlib.h>

#define P1 17359l            //two large primes, both congruent to 3 mod 4
#define P2 21487l
#define STARTING_SEED 104651 //a third number, co-prime with P1 & P2

typedef struct PRNG{
    uint64_t seed;
    uint64_t roll_count;
}PRNG;

PRNG* prng_create();
uint64_t prng_roll(PRNG* prng);//seed= seed*seed mod p1*p2
void prng_seed(PRNG* prng, uint64_t s);
uint64_t prng_get_roll_count(PRNG* prng);
