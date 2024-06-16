#include "queue.h"

queue *queue_create(){
    queue* nq= (queue*) malloc(sizeof(queue));
    nq->head= 0;
    nq->tail= 0;
    nq->size= 0;
    nq->cap= BASE_CAPACITY;
    nq->lf= BASE_LOAD_FACTOR;
    nq->arr= (uint32_t*) calloc(nq->cap, sizeof(uint32_t));
    return nq;
}

void queue_enqueue(queue *q, uint32_t e){
    q->arr[q->head]= e;
    if(++q->head == q->cap && q->tail != 0)
        queue_compress(q);
    if(++q->size / q->cap >= q->lf)
        queue_resize(q);
}

uint32_t queue_dequeue(queue *q){
    if(q->size == 0)
        return -1;//no elements in queue

    uint32_t e= q->arr[q->tail++];
    q->arr[q->tail-1]= 0;
    q->size--;

    if(q->head == q->tail)
        q->head = q->tail = 0;

    return e;
}

void queue_resize(queue *q){
    q->arr= (uint32_t*) realloc(q->arr, sizeof(uint32_t) * (q->cap*= BASE_MULTIPLE));
    for(uint32_t i=(q->cap/BASE_MULTIPLE);i<q->cap;i++)
        q->arr[i]= 0;
}

void queue_compress(queue *q){
    uint32_t i, diff= q->head - q->tail;
    for(i= 0; i < diff; i++)
        q->arr[i]= q->tail+i;
    for(i=diff; i < q->cap; i++)
        q->arr[i]= 0;
    q->head-= q->tail;
    q->tail= 0;
}

void queue_free(queue *q){
    free(q->arr);
    free(q);
}

uint32_t queue_get_size(queue *q){
    return q->size;
}

uint32_t queue_get_capacity(queue *q){
    return q->cap;
}

uint32_t queue_get_lf(queue *q){
    return q->lf;
}

uint32_t queue_get_head(queue *q){
    return q->head;
}

uint32_t queue_get_tail(queue *q){
    return q->tail;
}