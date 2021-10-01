cmake_minimum_required(VERSION 3.20)
project(ReferenceCheckers)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(ReferenceCheckers
        src/2021HW5starter.cpp
        src/Board.cpp
        src/Board.h
        src/CheckerMove.cpp
        src/CheckerMove.h
        src/LinkedList.c
        src/LinkedList.h
        src/Production.cpp
        src/Production.h
        src/Tests.cpp
        src/Tests.h src/Piece.cpp src/Piece.h)
