cmake_minimum_required(VERSION 3.20)
project(vibedrum CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# std only: this is the library a VST3 links
add_library(vibedrum_core STATIC core/vibedrum.cpp)
target_include_directories(vibedrum_core PUBLIC core)

add_executable(vibedrum cli/main.cpp)
target_link_libraries(vibedrum PRIVATE vibedrum_core)
if(APPLE)
  target_link_libraries(vibedrum PRIVATE "-framework AudioToolbox" "-framework CoreFoundation")
endif()
