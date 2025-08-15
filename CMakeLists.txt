cmake_minimum_required(VERSION 3.29)
project(Algos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Algos main.cpp
        matrixmult.h
        sort-felix.h
        levenshtein.h
        rucksack.h
        euros.h
        binomialkoeffizient.h
        factorial.h
        binarysearch.h
        graph.h
        sort-quick.h
        queue.h
        infinite-wall.h
)
