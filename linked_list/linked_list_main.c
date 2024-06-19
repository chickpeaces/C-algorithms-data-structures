#include <stdio.h>
#include <assert.h>
#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER
#include "linked_list.h"
#endif

#define TEST_ELEMENT_COUNT 1000000

int main(void){
    llist *list= ll_create();
    assert(list->count == 0);
    assert(list->start == NULL);
    llnode *lnode= lln_create(444);
    assert(lnode->payload == 444);
    assert(lnode->next == NULL);
    free(lnode);

    for(int i=0;i<500;i++)
        ll_add_element(list,i+1);
    assert(ll_get_count(list) == 500);

    for(int i=299;i<399;i++){
        lnode= ll_remove_element(list, i+1);
        assert(lnode != NULL);
        assert(lnode->payload == i+1);
        lnode= ll_find_element(list, i+1);
        assert(lnode == NULL);
    }
    assert(ll_get_count(list) == 400);

    assert(ll_remove_element(list, 1) != NULL);
    assert(ll_remove_element(list, 500) != NULL);
    assert(ll_find_element(list, 499) != NULL);

    ll_free(list);
    printf("OK");
    return 0;
}