cmake_minimum_required(VERSION 3.24)
project(itmo_algo)

set(CMAKE_CXX_STANDARD 17)

add_executable(itmo_algo ycontest/K.cpp)

add_executable(testgen ycontest/test-gen.cpp)

add_executable(testcheck ycontest/test-check.cpp)
