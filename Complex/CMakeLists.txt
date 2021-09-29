cmake_minimum_required(VERSION 3.17)
project(Complex)

set(CMAKE_CXX_STANDARD 14)

add_executable(Complex main.cpp complex.cpp)
target_compile_options(Complex PUBLIC -Wall -Wextra)
# target_compile_options(Complex PUBLIC -Wpedantic)