cmake_minimum_required(VERSION 3.15)

project(oop_exercise_07)

include_directories(include)
include_directories(include/figures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-g")

add_executable(main
  src/main.cpp
  include/editor.cpp
  include/command.cpp
  include/document.cpp
  include/factory.cpp
  )
