cmake_minimum_required(VERSION 3.26)
project(seqList C)

set(CMAKE_C_STANDARD 11)

add_executable(seqList seqList.c
        main.c
        seqList.h
)
