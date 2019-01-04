cmake_minimum_required(VERSION 3.13.1)
project(Gedit)

set(GDT_SOURCES src/Command.cpp src/Gedit.cpp src/Main.cpp src/Screen.cpp)

add_executable(gedit ${GDT_SOURCES})
target_include_directories(gedit PRIVATE ${CMAKE_SOURCE_DIR}/src)
