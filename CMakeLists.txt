cmake_minimum_required(VERSION 3.17)

project(BakkesSocket VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

add_library(BakkesSocket SHARED ${SOURCE_FILES})

set_target_properties(BakkesSocket PROPERTIES COMPILE_OPTIONS "/Zi")

target_include_directories(
  BakkesSocket PRIVATE
  "${CMAKE_SOURCE_DIR}/deps/inc"
)

target_link_libraries(
  BakkesSocket PRIVATE
  "${CMAKE_SOURCE_DIR}/deps/lib/pluginsdk.lib"
)
