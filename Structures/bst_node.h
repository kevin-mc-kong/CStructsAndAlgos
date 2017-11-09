//
// Created by mxk7199 on 11/7/17.
//

#ifndef BST_NODE_H
#define BST_NODE_H

#include <stdbool.h>
//TODO #include your object type here, alongside their isGreaterThan and isEqualTo functions

struct node_s {
            void*   data;
    struct  node_s* parent;
    struct  node_s* leftChild;
    struct  node_s* rightChild;
};

typedef struct node_s Node;


bool isGreaterThan(Node* a, Node* b);

bool isEqualTo(Node* a, Node* b);


Node* node(void* data);

void nodeInsert(Node* a, Node* b);

bool nodeFind(Node* a, Node* b);

bool nodeRemove(Node* a, Node* b);




#endif //BST_NODE_H
