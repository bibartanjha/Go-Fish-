cmake_minimum_required(VERSION 3.12)
project(GoFish)

set(CMAKE_CXX_STANDARD 98)

add_executable(GoFish card_demo.cpp Card.cpp Deck.cpp Player.cpp)