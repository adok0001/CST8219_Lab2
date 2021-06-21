# CMakeList.txt : CMake project for CST8219_Lab2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.2)

project ("CST8219_Lab2")

# Add source to this project's executable.
add_executable (Lab3 "Lab3.cpp" "Game.h" "Game.cpp" "Player.cpp" "Player.h")
# CMakeList.txt : CMake project for Week1, include source and define
# project specific logic here.

# TODO: Add tests and install targets if needed.
set_property(TARGET Lab3 PROPERTY CXX_STANDARD 11)
set_property(TARGET Lab3 PROPERTY CXX_STANDARD_REQUIRED ON)

