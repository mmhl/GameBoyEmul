cmake_minimum_required(VERSION 3.4)
project(GameBoyEmul)

find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp cpu.cpp cpu.h instructions.h mem.cpp mem.h)
add_executable(GameBoyEmul ${SOURCE_FILES})