#include <stdint.h>
#include <stdlib.h>

#define BASE_CAPACITY 8
#define BASE_MULTIPLE 2.0f
#define BASE_LOAD_FACTOR 0.75f

typedef struct queue{
    uint32_t head;//head is always >= tail
    uint32_t tail;//head & tail only equal when the queue is empty
    uint32_t size;//total elements in queue
    uint32_t cap; //maximum elements in queue
    double lf;
    uint32_t* arr;
} queue;

queue *queue_create();
void queue_enqueue(queue *q, uint32_t e);
uint32_t queue_dequeue(queue *q);
void queue_resize(queue *q);
void queue_compress(queue *q);
void queue_free(queue *q);
uint32_t queue_get_size(queue *q);
uint32_t queue_get_capacity(queue *q);
uint32_t queue_get_lf(queue *q);
uint32_t queue_get_head(queue *q);
uint32_t queue_get_tail(queue *q);