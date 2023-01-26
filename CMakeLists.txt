cmake_minimum_required(VERSION 3.24)
project(RadPatternBuilder)

set(CMAKE_CXX_STANDARD 17)

add_executable(RadPatternBuilder main.cpp RadPattern.cpp RadPattern.h)
