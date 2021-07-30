# CMakeList.txt : CMake project for CST8219_Lab2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.20)

project ("CST8219_Lab2")

# Add source to this project's executable.
add_executable (Lab5 "Lab5.cpp" "Player.cpp" "Player.h") #"Game.h" "Game.cpp" 
# CMakeList.txt : CMake project for Week1, include source and define
# project specific logic here.

# TODO: Add tests and install targets if needed.
set_property(TARGET Lab5 PROPERTY CXX_STANDARD 11)
set_property(TARGET Lab5 PROPERTY CXX_STANDARD_REQUIRED ON)
 
