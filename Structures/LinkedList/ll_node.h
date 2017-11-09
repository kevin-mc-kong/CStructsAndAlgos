//
// Created by mxk7199 on 11/9/17.
//

#include <stdbool.h>

#ifndef LL_NODE_H
#define LL_NODE_H

struct ll_node_s {
    void*               data;
    struct ll_node_s*   next;
};

typedef struct ll_node_s LLNode;


LLNode* llNode     (void* data);


bool    isEqual    (LLNode* a, LLNode* b);


void    nodeInsert (LLNode* head, LLNode* n);

bool    nodeFind   (LLNode* head, LLNode* n);

bool    nodeRemove (LLNode* head, LLNode* n);


#endif //LL_NODE_H
