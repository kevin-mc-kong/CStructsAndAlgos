//
// Created by mxk7199 on 11/9/17.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ll_node.h"

typedef struct LinkedList_s {
    LLNode*      head;
    unsigned int size;
}LinkedList;


LinkedList* linkedList();


void insert (LinkedList* ll, void* data);

bool find   (LinkedList* ll, void* data);

bool remove (LinkedList* ll, void* data);


#endif //LINKED_LIST_H
