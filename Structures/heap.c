#include <stdlib.h>
#include "heap.h"

Heap* heap() {
    Heap* h = malloc(sizeof(Heap));

    h->length           = 0;
    h->thresholdLength  = HEAP_INITIAL_LENGTH;
    h->data             = malloc(sizeof(void*) * HEAP_INITIAL_LENGTH);

    return h;
}


bool isGreaterThan(void* o8pdata1, void* data2) {
    //TODO implement yourself, return true if data1 > data2, false otherwise
}


int getParentIndex(int childIndex) {
    if (childIndex == 0)    return NULL;
    else                    return (childIndex - 1 / 2);
}

int getLeftChildIndex(int parentIndex) {
    return parentIndex * 2 + 1;
}

int getRightChildIndex(int parentIndex) {
    return parentIndex * 2 + 2;
}

void swapData(Heap* h, int index1, int index2) {
    void* data1 = h->data[index1];
    void* data2 = h->data[index2];

    h->data[index1] = data2;
    h->data[index2] = data1;
}

void cascadeUp(Heap* h, int childIndex) {
    if (!childIndex) return;

    void* child = h->data[childIndex];

    int parentIndex = getParentIndex(childIndex);
    void* parent    = h->data[parentIndex];

    if (isGreaterThan(parent, child)) {
        swapData (h, parentIndex, childIndex);
        cascadeUp(h, parentIndex);
    }
}

void cascadeDown(Heap* h, int parentIndex) {
    int leftChildIndex  = getLeftChildIndex(parentIndex);
    int rightChildIndex = getRightChildIndex(parentIndex);

    if (leftChildIndex > h->length && rightChildIndex > h->length)
        return;

    else if (leftChildIndex < h->length <= rightChildIndex) {
        void* parent    = h->data[parentIndex];
        void* leftChild = h->data[leftChildIndex];

        if (isGreaterThan(parent, leftChild)) { //TODO void* aren't guaranteed to have data attr
            swapData   (h, parentIndex, leftChildIndex);
            cascadeDown(h, leftChildIndex);
        }
    }

    else {
        void* parent        = h->data[parentIndex];
        void* leftChild     = h->data[leftChildIndex];
        void* rightChild    = h->data[rightChildIndex];

        if (isGreaterThan(leftChild, rightChild)) { //TODO void* aren't guaranteed to have data attr
            if (isGreaterThan(parent, leftChild)) {
                swapData   (h, parentIndex, leftChildIndex);
                cascadeDown(h, leftChildIndex);
            }
        }

        else {
            if (isGreaterThan(parent, rightChild)) { //TODO void* aren't guaranteed to have data attr
                swapData   (h, parentIndex, rightChildIndex);
                cascadeDown(h, rightChildIndex);
            }
        }
    }
}

bool insert (Heap* h, void* data) {
    h->data[h->length] = data;
    h->length++;

    if (h->length == h->thresholdLength) {
        h->data = realloc(h->data, h->thresholdLength * 2);
        h->thresholdLength *= 2;
    }

    return true;
}

void* pop(Heap* h) {
    if (!h->length)
        return NULL;
    if (h->length == 1) {
        void* out           = h->data[0];
        h->data[0]          = NULL;
        h->length           = 0;
        h->thresholdLength  = HEAP_INITIAL_LENGTH;

        return out;
    }

    else {
        void* out   = h->data[0];
        h->data[0]  = h->data[h->length - 1];
        cascadeDown(h, 0);

        h->length--;
        if (h->length < h->thresholdLength / 2 && h->thresholdLength > HEAP_INITIAL_LENGTH) {
            h->data = realloc(h->data, h->thresholdLength / 2);
            h->thresholdLength /= 2;
        }

        return out;
    }
}