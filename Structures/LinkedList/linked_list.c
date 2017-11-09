//
// Created by mxk7199 on 11/9/17.
//

#include <stdlib.h>
#include "linked_list.h"


LinkedList* linkedList() {
    LinkedList* ll  = malloc(sizeof(LinkedList));
    ll->head        = NULL;
    ll->size        = 0;

    return ll;
}


void insert (LinkedList* ll, void* data) {
    LLNode* n = llNode(data);

    if (!ll->size)
        ll->head = n;

    else
        nodeInsert(ll->head, n);

    ll->size++;
}

bool find (LinkedList* ll, void* data) {
    if (!ll->size)
        return false;

    LLNode* n = llNode(data);
    return nodeFind(ll->head, n);
}

bool remove (LinkedList* ll, void* data) {
    if (!ll->size)
        return false;

    LLNode* n = llNode(data);
    if (isEqual(ll->head, n)) {
        LLNode* oldHead = ll->head;
        ll->head = ll->head->next;

        free(oldHead->data);
        free(oldHead);

        return true;
    }

    else {
        return nodeRemove(ll->head, n);
    }
}