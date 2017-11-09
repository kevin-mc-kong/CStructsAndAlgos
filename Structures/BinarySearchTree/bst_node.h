//
// Created by mxk7199 on 11/7/17.
//

#ifndef BST_NODE_H
#define BST_NODE_H

#include <stdbool.h>
//TODO #include your object type here, alongside their isGreaterThan and isEqualTo functions

struct bst_node_s {
    void*               data;
    struct  bst_node_s* parent;
    struct  bst_node_s* leftChild;
    struct  bst_node_s* rightChild;
};

typedef struct bst_node_s BSTNode;


bool isGreaterThan  (BSTNode* a, BSTNode* b);

bool isEqualTo      (BSTNode* a, BSTNode* b);


BSTNode* node   (void* data);

void nodeInsert (BSTNode* a, BSTNode* b);

bool nodeFind   (BSTNode* a, BSTNode* b);

bool nodeRemove (BSTNode* a, BSTNode* b);




#endif //BST_NODE_H
