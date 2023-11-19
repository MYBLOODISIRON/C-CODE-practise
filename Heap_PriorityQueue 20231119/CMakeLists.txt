cmake_minimum_required(VERSION 3.26)
project(Heap_PriorityQueue C)

set(CMAKE_C_STANDARD 11)

add_executable(Heap_PriorityQueue main.c
        Heap.h
        Heap.c
        library.h)
