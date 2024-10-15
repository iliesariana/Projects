cmake_minimum_required(VERSION 3.27)
project(LAB2_DSA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LAB2_DSA
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SortedSet.cpp
        SortedSet.h
        SortedSetIterator.cpp
        SortedSetIterator.h)
