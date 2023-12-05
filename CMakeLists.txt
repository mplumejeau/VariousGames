cmake_minimum_required(VERSION 3.22)
project(various_games)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable( game
        main.cpp
        Color.h
        Player.h
        Token.h
        Game.h
        GameGrid.h
        Power4.h
        TicTacToe.h
        GameManager.h
)
