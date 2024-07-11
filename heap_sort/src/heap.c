#ifndef HEAP_HEADER
#define HEAP_HEADER
#include "heap.h"
#endif

/* Internal heap functions not part of Heap.h */
static void swap(int *a, int *b){
    int tmp= *a;
    *a= *b;
    *b= tmp;
}

static void heapify(heap *h, int i){
    while(i >= 0 && h->keys[i] > h->keys[PARENT_INDEX(i)]){
        swap(&h->keys[i], &h->keys[PARENT_INDEX(i)]);
        i=PARENT_INDEX(i);
    }
}

heap* create_heap(){
    heap* nh= (heap*) malloc(sizeof(heap));
    nh->count= 0;
    nh->keys= (int*) calloc(HEAP_INIT_SIZE+1, sizeof(int));
    return nh;
}

int heap_push_element(heap *h, int e){
    h->keys[h->count]= e;
    h->count++;
    heapify(h, h->count-1);
    return 0;
}

int heap_pop_element(heap *h){
    int o= h->keys[0];
    h->keys[0]= 0;
    h->count--;
    swap(&h->keys[0],&h->keys[h->count]);
    for(int i=h->count; i>=0; i--)
        heapify(h, i);
    return o;
}

int heap_peek(heap *h){
    return h->keys[0];
}

int heap_get_count(heap *h){
    return h->count;
}

int heap_is_empty(heap *h){
    return h->count == 0;
}

void heap_free(heap *h){
    free(h->keys);
    free(h);
}