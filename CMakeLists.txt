cmake_minimum_required(VERSION 3.25)

project(PlatineProject LANGUAGES CXX)

add_executable(Platine
    code/src/main.cpp
    code/src/GameMgr.cpp
    code/src/MapContentReader.cpp
    code/src/MapData.cpp
    code/src/SFMLGraphicalDisplay.cpp
    code/src/SFMLEventManager.cpp
)

target_compile_features(Platine PRIVATE cxx_std_17)

target_compile_options(Platine
    PRIVATE
        -Wall
)

target_include_directories(Platine
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/code/include
        ${CMAKE_CURRENT_SOURCE_DIR}/externals
)

find_package(SFML 2 REQUIRED COMPONENTS graphics window system)

target_link_libraries(Platine
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)