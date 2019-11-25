cmake_minimum_required (VERSION 2.6)
project (Lab3)
add_executable(oop_exercise_01
lab3.cpp
hexagon.cpp
octagon.cpp
triangle.cpp
point.cpp
)

set(CMAKE_CXX_FLAGS
	"${CMAKE_CXX_FLAGS} -Wall -Wextra")
