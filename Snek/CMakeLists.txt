cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 20)

project(snek)

add_executable(snek

    src/snake.cpp
    src/state.cpp
    src/statemanager.cpp
    src/assetmanager.cpp
    src/mainmenu.cpp
    src/gameplay.cpp
    src/game.cpp
    src/main.cpp


    )

find_package(SFML 2.5
  COMPONENTS
    system window graphics network audio REQUIRED)


target_link_libraries (snek sfml-window sfml-graphics sfml-system)

install(TARGETS snek RUNTIME DESTINATION bin)
