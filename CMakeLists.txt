cmake_minimum_required(VERSION 3.29)
project(cpp_ABC)

set(CMAKE_CXX_STANDARD 20)

include_directories(libs)

file(GLOB SOURCES main.cpp libs/*.cpp)

# Create the executable with all source files from libs folder
add_executable(cpp_ABC ${SOURCES})
