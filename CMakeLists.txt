cmake_minimum_required(VERSION 3.24)
project(finite_state_machines C)

set(CMAKE_C_STANDARD 11)

include_directories(Lab1)

add_executable(finite_state_machines
    Lab1/Lab1.c)
