cmake_minimum_required(VERSION 3.3)
project(Asm)

include_directories(../Stack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Assembler.cpp Disassembler.cpp ../Stack/stack_array.cpp)
add_executable(Asm ${SOURCE_FILES})