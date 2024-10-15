cmake_minimum_required(VERSION 3.27)
project(Lab5_dsa)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab5_dsa
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SMMIterator.cpp
        SMMIterator.h
        SortedMultiMap.cpp
        SortedMultiMap.h)
