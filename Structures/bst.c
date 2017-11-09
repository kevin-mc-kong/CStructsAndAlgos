//
// Created by mxk7199 on 11/7/17.
//

#include <stdlib.h>
#include "bst.h"


BinarySearchTree* binarySearchTree() {
    BinarySearchTree* bst = malloc(sizeof(BinarySearchTree));
    bst->root = NULL;
    bst->size = 0;
}


void insert(BinarySearchTree* bst, void* data) {
    Node* n = node(data);

    if (!bst->size)
        bst->root = n;

    else
        nodeInsert(bst->root, n);

    bst->size++;
}

bool find(BinarySearchTree* bst, void* data) {
    Node* n = node(data);

    if (!bst->size)
        return false;

    else
        return nodeFind(bst->root, n);
}

