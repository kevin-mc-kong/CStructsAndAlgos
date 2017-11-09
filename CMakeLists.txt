cmake_minimum_required(VERSION 3.8)
project(CStructsAndAlgos)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES Structures/heap.h Structures/bst.h Structures/bst_node.h Structures/heap.c Structures/bst.c Structures/bst_node.c)
add_library(CStructsAndAlgos SHARED ${SOURCE_FILES})