cmake_minimum_required(VERSION 3.16)
project(point_lab CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(point     point.cpp)
add_executable(bank      bank.cpp)
add_executable(file      file.cpp)
add_executable(crash     crash.cpp)
add_executable(vector    vector.cpp)
