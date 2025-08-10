cmake_minimum_required(VERSION 3.29)
project(Algos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Algos main.cpp
        matrixmult.h
        felixsort.h
        levenshtein.h
        rucksack.h
        euros.h
)
