#include <stdint.h>
#include <stdlib.h>

#define BASE_CAPACITY 8
#define BASE_MULTIPLE 2.0f
#define BASE_LOAD_FACTOR 0.75f

typedef struct da{
    uint32_t siz;
    uint32_t cap;
    double lf;
    uint32_t *arr;
} da;

da *da_create();
void da_add_element(da *da, uint32_t e);
uint32_t da_set_element(da *da, uint32_t e, uint32_t i);
uint32_t da_get_element(da *da, uint32_t i);
void da_resize(da *da);
void da_free(da *da);
uint32_t da_get_size(da *da);
uint32_t da_get_capacity(da *da);
double da_get_load_factor(da *da);