cmake_minimum_required(VERSION 3.13.1)
project(Gedit)

# set_target_properties(gedit PROPERTIES CXX_STANDARD_REQUIRED ON CXX_STANDARD 17) doesn't work but this workaround does
set(CMAKE_CXX_FLAGS -std=c++17)
set(CMAKE_CXX_FLAGS_DEBUG "-g -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O -O3")

add_subdirectory(${CMAKE_SOURCE_DIR}/src/Gedit ${CMAKE_BINARY_DIR}/Gedit)
