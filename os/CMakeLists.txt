cmake_minimum_required(VERSION 3.10)
project(os)

set(CMAKE_CXX_STANDARD 11)

add_library(os library.cpp library.h Msg.cpp Msg.h ShdMem.h ShdMem.cpp Pipe.cpp Pipe.h Socket.h Socket.cpp)