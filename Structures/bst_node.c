//
// Created by mxk7199 on 11/8/17.
//

#include <stdlib.h>
#include "bst_node.h"


bool isGreaterThan(Node* a, Node* b) {
    if (!a || !b)
        return false;

    else {
        //TODO implement yourself, return true if a > b, false otherwise
    }
}

bool isEqualTo(Node* a, Node* b) {
    //TODO implement yourself, return true if a == b, false otherwise
}


Node* node(void* data) {
    Node* n = malloc(sizeof(Node));
    n->data = data;
    n->parent = NULL;
    n->leftChild = NULL;
    n->rightChild = NULL;

    return n;
}


void nodeInsert(Node* a, Node* b) {
    if (isGreaterThan(a, b)) {
        if (a->leftChild)
            nodeInsert(a->leftChild, b);
        else {
            a->leftChild = b;
            b->parent = a;
        }
    }

    else {
        if (a->rightChild)
            nodeInsert(a->rightChild, b);
        else {
            a->rightChild = b;
            b->parent = a;
        }
    }
}

bool nodeFind(Node* a, Node* b) {
    if (isGreaterThan(a, b)) {
        if (a->leftChild)
            return nodeFind(a->leftChild, b);
        else
            return false;
    }

    else if (isEqualTo(a, b)) {
        return true;
    }

    else {
        if (a->rightChild)
            return nodeFind(a->rightChild, b);
        else
            return false;
    }
}

bool nodeRemove(Node* a, Node* b) {
    if (isGreaterThan(a, b)) {
        if (a->leftChild)
            return nodeRemove(a->leftChild, b);
        else
            return false;
    }

    else if (isEqualTo(a, b)) {
        if (a->leftChild && a->rightChild) {

        }

        else if (a->leftChild) {
            if (isEqualTo(a, a->parent->leftChild))
                a->parent->leftChild = a->leftChild;
            else
                a->parent->rightChild = a->leftChild;

            a->leftChild->parent = a->parent;
        }

        else if (a->rightChild) {
            if (isEqualTo(a, a->parent->leftChild))
                a->parent->leftChild = a->rightChild;
            else
                a->parent->rightChild = a->rightChild;

            a->rightChild->parent = a->parent;
        }

        else {
            if (isEqualTo(a, a->parent->leftChild))
                a->parent->leftChild = NULL;
            else
                a->parent->rightChild = NULL;
        }

        a->parent = NULL;
        free(a->data);
        free(a);

        return true;
    }

    else {
        if (a->rightChild)
            return nodeRemove(a->rightChild, b);
        else
            return false;
    }
}
