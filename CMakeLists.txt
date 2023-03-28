cmake_minimum_required (VERSION 3.8)

project(win_utils CXX)

add_library(win_utils
"dir.h" 
"dir.cpp"
"string_utils.h"
"error.h"
"handle.h"
"handle.cpp"
"file.h" "file.cpp" "file_builder.h" "file_builder.cpp")

