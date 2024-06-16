#include "dynamic_array.h"

da *da_create(){
    da* nda= (da*) malloc(sizeof(da));
    nda->siz= 0;
    nda->cap= BASE_CAPACITY;
    nda->lf= BASE_LOAD_FACTOR;
    nda->arr= (uint32_t*) calloc(nda->cap, sizeof(uint32_t));

    return nda;
}

void da_add_element(da *da, uint32_t e){
    da->arr[da->siz]= e;
    if(++da->siz / da->cap >= da->lf)
        da_resize( da);
}

uint32_t da_set_element(da *da, uint32_t e, uint32_t i){
    if( i > da->cap)
        return -1;
    da->arr[i]= e;

    return 0;
}

uint32_t da_get_element(da *da, uint32_t i){
    if( i > da->siz)
        return -1;
    return da->arr[i];
}

void da_resize(da *da){
    da->arr= (uint32_t*) realloc(da->arr,  sizeof( uint32_t) * (da->cap*= BASE_MULTIPLE));

}

void da_free(da *da){
    free(da->arr);
    free(da);
}

uint32_t da_get_size(da *da){
    return da->siz;
}

uint32_t da_get_capacity(da *da){
    return da->cap;
}

double da_get_load_factor(da *da){
    return da->lf;
}