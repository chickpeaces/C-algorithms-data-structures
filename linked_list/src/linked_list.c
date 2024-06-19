#include "linked_list.h"

llist *ll_create(void){
    llist *n= (llist*) malloc(sizeof(llist));
    n->count= 0;
    n->start= NULL;
    return n;
}

llnode *lln_create(uint32_t i){
    llnode *n= (llnode*) malloc(sizeof(llnode));
    n->payload= i;
    n->next= NULL;
    return n;
}

llnode* ll_add_element(llist* ll, uint32_t i){
    llnode *n= lln_create(i);
    n->next= ll->start;
    ll->start= n;
    ll->count++;
    return n;
}

llnode* ll_find_element(llist* ll, uint32_t i){
    llnode *p= ll->start;
    while(p != NULL){
        if(p->payload == i)
            return p;
        p=p->next;
    }

    return NULL;
}

llnode* ll_remove_element(llist* ll, uint32_t i){
    llnode *p= ll->start;
    llnode *pr= p;

    while(p != NULL){
        if(p->payload == i){
            if(p == ll->start)
                ll->start= p->next;
            if(p != ll->start)
                pr->next= p->next;
            p->next=NULL;
            ll->count--;
            return p;
        }

        pr= p;
        p= p->next;
    }

    return NULL;
}

uint32_t ll_get_count(llist *ll){
    return ll->count;
}

void ll_free(llist* ll){
    llnode *ln= ll->start;
    llnode *pln= ln;
    while(ln != NULL){
        pln= ln->next;
        free(ln);
        ln=pln;
    }
    free(ll);
}