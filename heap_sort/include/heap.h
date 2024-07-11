#include <stdlib.h>

#define HEAP_INIT_SIZE 32
#define LEFT_CHILD_INDEX(i) (2*i)
#define RIGHT_CHILD_INDEX(i) ((2*i)+1)
#define PARENT_INDEX(i) (i/2)

typedef struct heap{
    int count;
    int *keys;
}heap;

heap* create_heap();
int heap_push_element(heap* h, int e);
int heap_pop_element(heap *h);
int heap_peek(heap *h);
int heap_get_count(heap *h);
int heap_is_empty(heap *h);
void heap_free(heap *h);