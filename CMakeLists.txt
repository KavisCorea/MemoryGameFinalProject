cmake_minimum_required(VERSION 3.29)
project(MemoryGameFinal)

set(CMAKE_CXX_STANDARD 20)

add_executable(MemoryGameFinal main.cpp
        Game.cpp
        Game.h
        themes.cpp
        themes.h
        display.cpp
        display.h
        boardData.cpp
        boardData.h
        tuiLogic.cpp
        tuiLogic.h)
