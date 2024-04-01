cmake_minimum_required(VERSION 3.0)
project(main)


set(CMAKE_CXX_STANDARD 17)

include_directories(include)


file(GLOB SOURCES "src/*.cc")


set(RANDOMIZE_SOURCE "src/randomize.cc")

set(TIMER_SOURCE "src/timer.cc")


list(APPEND SOURCES ${RANDOMIZE_SOURCE})
list(APPEND SOURCES ${TIMER_SOURCE})

add_executable(main ${SOURCES})

