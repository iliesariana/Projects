cmake_minimum_required(VERSION 3.27)
project(LAB3_DSA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LAB3_DSA
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SMIterator.cpp
        SMIterator.h
        SortedMap.cpp
        SortedMap.h)
