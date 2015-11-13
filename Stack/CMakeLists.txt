cmake_minimum_required(VERSION 3.3)
project(Stack)

include_directories(../Asm)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Stack.h stack_array.cpp StackFunctions.cpp)
add_executable(Stack ${SOURCE_FILES})