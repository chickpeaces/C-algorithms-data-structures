#include <stdint.h>
#include <stdlib.h>

typedef struct linked_list_node {
    uint32_t payload;
    struct linked_list_node *next;
}llnode;

typedef struct linked_list {
    uint32_t count;
    llnode *start;
}llist;

llist* ll_create(void);
llnode* lln_create(uint32_t i);
llnode* ll_add_element(llist* ll, uint32_t i);
llnode* ll_find_element(llist* ll, uint32_t i);
llnode* ll_remove_element(llist* ll, uint32_t i);
uint32_t ll_get_count(llist *ll);
void ll_free(llist* ll);