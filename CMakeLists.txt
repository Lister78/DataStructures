cmake_minimum_required(VERSION 3.0)
project(main)


set(CMAKE_CXX_STANDARD 17)

include_directories(include)


file(GLOB SOURCES "src/*.cc")


set(RANDOMIZE_SOURCE "src/randomize.cc")

set(TIMER_SOURCE "src/timer.cc")

set (LINKED_LIST "src/LinkedList1.cc")
set (DOUBLE_LINKED_L "src/DoubleLinkedList.cc")

list(APPEND SOURCES ${RANDOMIZE_SOURCE})
list(APPEND SOURCES ${TIMER_SOURCE})
list(APPEND SOURCES ${LINKED_LIST})
list(APPEND SOURCES ${DOUBLE_LINKED_L})
add_executable(main ${SOURCES})


