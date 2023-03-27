# CMakeList.txt : CMake project for win_utils, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (win_utils 
"dir.h" 
"dir.cpp"
"string_utils.h"
"main.cpp"
"error.h"
"handle.h" 
"handle.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET win_utils PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
