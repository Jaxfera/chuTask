file(GLOB GEDIT_SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*)
add_executable(gedit ${GEDIT_SOURCES})
target_include_directories(gedit PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)