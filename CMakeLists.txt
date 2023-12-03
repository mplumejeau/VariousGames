cmake_minimum_required(VERSION 3.26)
project(tp4_play)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tp4_play
        main.cpp
        Game.h
        GameT.h
        Power4.h
        TicTacToe.h
        Play.h
        Play.cpp
        PlayPower4.h
        PlayTicTacToe.h

)
