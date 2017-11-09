#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>

#define HEAP_INITIAL_LENGTH 256


typedef struct heap_s {
    void** data;
    unsigned int length;
    unsigned int thresholdLength;
} Heap;


Heap* heap();


bool isGreaterThan(void* data1, void* data2);


int getParentIndex(int childIndex);

int getLeftChildIndex(int parentIndex);

int getRightChildIndex(int parentIndex);


void swapData(Heap* h, int index1, int index2);

void cascadeUp(Heap* h, int childIndex);

void cascadeDown(Heap* h, int parentIndex);

bool insert(Heap* h, void* data);

void* pop(Heap* h);

#endif