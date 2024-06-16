#include <stdint.h>
#include <stdlib.h>

#define BASE_CAPACITY 8
#define BASE_MULTIPLE 2.0f
#define BASE_LOAD_FACTOR 0.75f

typedef struct stack{
    uint32_t siz;
    uint32_t cap;
    double lf;
    uint32_t *arr;
} stack;

stack *stack_create();
void stack_push(stack *s, uint32_t e);
uint32_t stack_pop(stack *s);
void stack_resize(stack *s);
void stack_free(stack *s);
uint32_t stack_get_size(stack *s);
uint32_t stack_get_capacity(stack *s);
uint32_t stack_get_lf(stack *s);