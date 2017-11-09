//
// Created by mxk7199 on 11/7/17.
//

#ifndef BST_H
#define BST_H

#include "bst_node.h"

typedef struct bst_s {
    BSTNode*     root;
    unsigned int size;
} BinarySearchTree;


BinarySearchTree* binarySearchTree();

void insert (BinarySearchTree* bst, void* data);

bool find   (BinarySearchTree* bst, void* data);




#endif //CSTRUCTSANDALGOS_BST_H
