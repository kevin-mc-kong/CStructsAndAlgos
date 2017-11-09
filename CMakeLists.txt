cmake_minimum_required(VERSION 3.8)
project(CStructsAndAlgos)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES Structures/Heap/heap.h Structures/BinarySearchTree/bst.h Structures/BinarySearchTree/bst_node.h Structures/Heap/heap.c Structures/BinarySearchTree/bst.c Structures/BinarySearchTree/bst_node.c Structures/LinkedList/ll_node.h Structures/LinkedList/ll_node.c Structures/LinkedList/linked_list.c Structures/LinkedList/linked_list.h)
add_library(CStructsAndAlgos SHARED ${SOURCE_FILES})