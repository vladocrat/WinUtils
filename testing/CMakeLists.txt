cmake_minimum_required (VERSION 3.8)

project(win_utils_tests CXX)

set(WIN_UTILS ${CMAKE_SOURCE_DIR}/WinUtils)
set(RESOURCES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/test_files)

file(COPY ${RESOURCES_PATH}/readbytes_test.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${WIN_UTILS})

add_executable(win_utils_tests
"main.cpp" 
"file_tests.h")

target_link_libraries(win_utils_tests gtest_main win_utils)

