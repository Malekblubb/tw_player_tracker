project(tw_player_tracker)
cmake_minimum_required(VERSION 2.8)

file(GLOB_RECURSE SRC_LIST "./include/twpt/*" "./src/twpt/*")
include_directories("./include")

add_executable(${PROJECT_NAME} ${SRC_LIST})
include_directories("external/mlk/include" "external/twl/include")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "-std=c++11")
