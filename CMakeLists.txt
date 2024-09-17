cmake_minimum_required(VERSION 3.17)

project(BakkesSocket VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

add_library(BakkesSocket SHARED ${SOURCE_FILES})

add_library(asio INTERFACE)
target_include_directories(asio INTERFACE "${CMAKE_SOURCE_DIR}/deps/inc/asio/asio/include")

add_library(websocketpp INTERFACE)
target_include_directories(websocketpp INTERFACE "${CMAKE_SOURCE_DIR}/deps/inc/websocketpp")

target_compile_definitions(websocketpp INTERFACE
  ASIO_STANDALONE
  _WEBSOCKETPP_CPP11_STL_
)

target_compile_options(BakkesSocket PRIVATE
  /permissive-
  /MP
  /GS
  /GL
  /W3
  /Gy
  /Zc:wchar_t
  /Zi
  /Gm-
  /sdl
  /Zc:inline
  /fp:precise
  /WX-
  /Zc:forScope
  /Gd
  /Oi
  /MT
  /EHsc
  /FC
)

target_compile_definitions(BakkesSocket PRIVATE
  NDEBUG
  _CONSOLE
  _WINDLL
  _UNICODE
  UNICODE
)

target_include_directories(
  BakkesSocket PRIVATE
  "${CMAKE_SOURCE_DIR}/deps/inc"
)

target_link_libraries(
  BakkesSocket PRIVATE
  "${CMAKE_SOURCE_DIR}/deps/lib/pluginsdk.lib"
  asio
  websocketpp
)