cmake_minimum_required(VERSION 3.10)

project(BakkesSocket VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_library(pluginsdk STATIC IMPORTED)

set_target_properties(pluginsdk PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/deps/lib/pluginsdk.lib"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/deps/inc"
)

add_library(BakkesSocket SHARED BakkesSocket.cpp)
target_link_libraries(BakkesSocket pluginsdk)
