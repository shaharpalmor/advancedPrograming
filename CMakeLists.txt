cmake_minimum_required(VERSION 3.8)
project(ex2)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES  Player.cpp Player.h HumanPlayer.cpp HumanPlayer.h Cell.cpp Cell.h Board.cpp Board.h generaldefinition.h GameRules.cpp GameRules.h Coordinate.cpp Coordinate.h Printer.cpp Printer.h ConsolePrinter.cpp ConsolePrinter.h GameManager.cpp GameManager.h TwoPlayersGame.cpp TwoPlayersGame.h main.cpp)
add_executable(ex2 ${SOURCE_FILES})