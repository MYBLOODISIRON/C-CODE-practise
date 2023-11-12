cmake_minimum_required(VERSION 3.26)
project(ThreadedBinaryTree C)

set(CMAKE_C_STANDARD 11)

add_executable(ThreadedBinaryTree main.c
        ThreadedBinaryTree.h
        ThreadedBinaryTree.c
        library.h)
