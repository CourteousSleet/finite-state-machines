cmake_minimum_required(VERSION 3.24)
project(finite_state_machines C)

set(CMAKE_C_STANDARD 11)
#########################

include_directories(Lab1)

add_executable(Lab1
        Lab1/Lab1.c)
#########################

include_directories(Lab2)

add_executable(Lab2
        Lab2/Lab2.c)
#########################

include_directories(Lab3)

add_executable(Lab3
        Lab3/Lab3.c)
#########################

include_directories(Lab4)

add_executable(Lab4
        Lab4/Lab4.c)

include_directories(Lab5)
#########################

add_executable(Lab5
        Lab5/Lab5.c)
#########################

include_directories(Lab6)

add_executable(Lab6
        Lab6/Lab6.c)
