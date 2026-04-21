cmake_minimum_required(VERSION 3.36)
project(datrueone)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS ON)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT datrueone)

add_executable(datrueone ${CMAKE_CURRENT_SOURCE_DIR}/datrueone.cpp)