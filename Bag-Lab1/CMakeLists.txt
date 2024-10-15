cmake_minimum_required(VERSION 3.27)
project(LAB1_DSA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LAB1_DSA
        App.cpp
        Bag.cpp
        Bag.h
        BagIterator.cpp
        BagIterator.h
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h)
