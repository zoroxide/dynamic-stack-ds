cmake_minimum_required(VERSION 3.28)
project(dynamic_stack C)

set(CMAKE_C_STANDARD 11)

add_executable(dynamic_stack
        main.c
        dynamic_stack.h
        dynamic_stack.c)
