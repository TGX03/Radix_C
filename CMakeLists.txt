cmake_minimum_required(VERSION 3.26)
project(Radix C)

set(CMAKE_C_STANDARD 23)

add_executable(Radix main.c
        IntList.c
        IntList.h
        Radix.c
        Radix.h)
