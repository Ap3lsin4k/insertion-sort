cmake_minimum_required(VERSION 3.17)
project(L2_1_third C)

set(CMAKE_C_STANDARD 11)

#add_executable(L2_1_third main.c implementation.c implementation.h)
add_executable(L2_1_third test/test_sort.c insertion_sort.c insertion_sort.h)