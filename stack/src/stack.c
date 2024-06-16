#include "stack.h"

stack *stack_create(){
    stack* nstk= (stack*) malloc(sizeof(stack));
    nstk->siz= 0;
    nstk->cap= BASE_CAPACITY;
    nstk->lf= BASE_LOAD_FACTOR;
    nstk->arr= (uint32_t*) calloc(nstk->cap, sizeof(uint32_t));
    return nstk;
}

void stack_push(stack *s, uint32_t e){
    s->arr[s->siz]= e;
    if( ++s->siz / s->cap >= s->lf)
        stack_resize(s);
}

uint32_t stack_pop(stack *s){
    if(s->siz == 0)
        return -1;

    uint32_t e= s->arr[--s->siz];
    s->arr[s->siz+1]= 0;
    return e;
}

void stack_resize(stack *s){
    s->arr= (uint32_t*) realloc(s->arr, sizeof(uint32_t) * (s->cap*= BASE_MULTIPLE));
    for(uint32_t i=(s->cap/BASE_MULTIPLE);i<s->cap;i++)
        s->arr[i]= 0;
}

void stack_free(stack *s){
    free(s->arr);
    free(s);
}

uint32_t stack_get_size(stack *s){
    return s->siz;
}

uint32_t stack_get_capacity(stack *s){
    return s->cap;
}

uint32_t stack_get_lf(stack *s){
    return s->lf;
}