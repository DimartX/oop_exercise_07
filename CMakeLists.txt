cmake_minimum_required(VERSION 3.15)

project(oop_exercise_07)

include_directories(include)
include_directories(include/figures)

add_library(editor STATIC
  editor.cpp
  command.cpp
  document.cpp
  factory.cpp
  )


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main
  src/main.cpp
  )

target_link_libraries(main editor)
