cmake_minimum_required(VERSION 3.26)
project(StaticLinkList C)

set(CMAKE_C_STANDARD 11)

add_executable(StaticLinkList main.c
        StaticLinkList.c
        StaticLinkList.h
        library.h)
