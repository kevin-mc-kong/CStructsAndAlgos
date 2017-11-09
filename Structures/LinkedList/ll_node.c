//
// Created by mxk7199 on 11/9/17.
//

#include <stdlib.h>
#include "ll_node.h"


LLNode* llNode(void* data) {
    LLNode* n = malloc(sizeof(LLNode));
    n->data = data;
    n->next = NULL;

    return n;
}


bool isEqual(LLNode* a, LLNode* b) {
    //TODO implement yourself
}


void nodeInsert(LLNode* head, LLNode* n) {
    if (head->next)
        nodeInsert(head->next, n);
    else
        head->next = n;
}

bool nodeFind(LLNode* head, LLNode* n) {
    if (isEqual(head, n))
        return true;
    else if (head->next)
        return nodeFind(head->next, n);

    return false;
}

bool nodeRemove(LLNode* head, LLNode* n) {
    if (!head->next)
        return false;

    LLNode* oldNext = head->next;

    if (isEqual(head->next, n)) {
        if (head->next->next)
            head->next = head->next->next;

        else
            head->next = NULL;

        free(oldNext->data);
        free(oldNext);

        return true;
    }

    else
        return nodeRemove(head->next, n);
}

