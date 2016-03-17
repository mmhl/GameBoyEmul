cmake_minimum_required(VERSION 3.4)
project(GameBoyEmul)

find_package(Boost 1.57.0 COMPONENTS system filesystem regex REQUIRED system)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp cpu.cpp cpu.h instructions.h mem.cpp mem.h Rom.cpp Rom.h)
add_executable(GameBoyEmul ${SOURCE_FILES})

target_link_libraries(GameBoyEmul
        ${Boost_PROGRAM_OPTIONS_LIBRARIES}
        ${Boost_FILESYSTEM_LIBRARIES}
        ${Boost_SYSTEM_LIBRARIES}
        )