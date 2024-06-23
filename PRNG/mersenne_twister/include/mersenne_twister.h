#include <stdint.h>

#define N 624
#define M 397
#define F 1812433253UL
#define MATRIX_A_VECTOR 0x9908b0dfUL
#define LOWER_MASK 0x7fffffffUL
#define UPPER_MASK 0x80000000UL //most significant W - r bits (w=32, r=32)

void mt_init(uint32_t s);
uint32_t mt_random();
void mt_twist();
uint32_t mt_temper();
