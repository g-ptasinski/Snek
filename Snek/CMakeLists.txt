cmake_minimum_required(VERSION 3.0)

project(snek)

add_executable(snek main.cpp)

install(TARGETS snek RUNTIME DESTINATION bin)
