cmake_minimum_required(VERSION 3.16)
project(K)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS '-O3')
set(CMAKE_CXX_FLAGS '-fopenmp')

include_directories(.)

add_executable(K main.cpp conv.h conv.cpp)

add_executable(tests test/main.cpp test/conv_test.h test/conv_test.cpp conv.h conv.cpp)