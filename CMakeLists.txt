cmake_minimum_required(VERSION 3.13)
project(SC)

set(CMAKE_CXX_STANDARD 14)

add_executable(SC main.cpp src/Utils.h src/Utils.cpp src/debug.h src/SNLLex.cpp src/SNLLex.h src/structures.cpp src/structures.h src/StringUtils.h src/StringUtils.cpp)